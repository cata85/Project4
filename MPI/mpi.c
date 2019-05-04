#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

  char** results;


//this method is found https://gist.github.com/adrian-source/4111719 .... THIS CODE IS NOT MINE
char* lcs(char* s1, char* s2)
{
  int s1_l = strlen(s1), s2_l = strlen(s2);
	int i, s1_i, s2_i, longest = 0;

	char* set = (char*)malloc(sizeof(char) * ((s1_l < s2_l)?s1_l:s2_l));
	memset(set, ' ', strlen(set));

	// initialize 2d array
	int** l = (int**)malloc((s1_l + 1) * sizeof(int*));
	for (i = 0; i < s1_l + 1; i++)
		l[i] = (int*)malloc((s2_l + 1) * sizeof(int));

	// initialize all array fields to 0
	for (s1_i = 0; s1_i < s1_l; s1_i++)
		for (s2_i = 0; s2_i < s2_l; s2_i++)
			l[s1_i][s2_i] = 0;

	// loop through all letters
	for (s1_i = 0; s1_i < s1_l; s1_i++)
		for (s2_i = 0; s2_i < s2_l; s2_i++)
		{
			// if characters match
			if (s1[s1_i] == s2[s2_i])
			{
				// calculate the incremented length for current sequence
				int v = l[s1_i][s2_i] + 1;

				// save the incremented length in south-east cell
				l[s1_i+1][s2_i+1] = v;

				// if new length is longest thus far
				if (v > longest)
				{
					// set that to be our new longest length
					longest = v;

					// and clear the set
					memset(set, ' ', strlen(set));
				}	

				// if new length equals to the longest length
				if (v == longest)
				{
					// copy the char set to the return set
					for (i = 0; i < longest; i++)
						set[i] = s1[s1_i-longest+i+1];
				}
			}
		}

	// free
	for (i = 0; i < s1_l + 1; i++)
		free(l[i]);
	free(l);

	// return
	return set;
}

// this method reads the file
char **ReadFile (char *filename, int total_lines)
{
  FILE *fd;
  int i = 0;
  int nchars = 0;
  int len, nlines, err;
  char** lines = (char **) malloc( total_lines * sizeof( char * ) );
  for( i = 0; i < total_lines + 1; i++ ) 
  {
    lines[i] = malloc( sizeof(char)*4001 );
  }
  fd = fopen(filename, "r");
	nlines = -1;
	do {
	  err = fscanf(fd, "%[^\n]\n", lines[++nlines]);
	  if( lines[nlines] != NULL ) nchars += (double) strlen( lines[nlines] );
	} while( err != EOF && nlines < total_lines);
	fclose( fd );
  
  return lines;
}

// this method prints the results from the results 
void PrintResults(int total_lines)
{
  int i;
  for (i=0; i<total_lines; i++)
  {
    printf("%d-%d: %s\n", i, i+1, results[i]); 
  }
}

void *job_allocator(void *rank, int total_lines, int number_of_tasks, char **lines)
{
  int i, j;
  int id = *((int *) rank);
  int startPos = ((long) id) * (total_lines / number_of_tasks);
  int endPos = startPos + (total_lines / number_of_tasks);

  if (id == number_of_tasks-1)
  {
    endPos = total_lines-1; // Could be issue.
  }

  for (j=startPos;j<endPos-1;j++)
  {
    char *A = lines[j];
    char *B = lines[j+1];
    char *answer = lcs(A, B);
    results[j] = answer;
  }
}

int main (int argc, char *argv[]) 
{
  int i, j;
  if (argc < 3)
  {
    printf("You are missing arguments");
    return 0;
  }
  else
  {
    char *filename = argv[1];
    int total_lines = atoi(argv[2]);
    int number_of_tasks, rank;
    char **lines;
    MPI_Status status;

    results = (char **) malloc( total_lines * sizeof( char * ) );
    for(i=0; i < total_lines; i++) 
    {
      results[i] = malloc( sizeof(char)*4001 );
    }

    int ierr = MPI_Init(&argc, &argv);

    if (ierr != MPI_SUCCESS)
    {
      printf("Error: MPI could not start.\n");
      MPI_Abort(MPI_COMM_WORLD, ierr);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &number_of_tasks);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
      lines = ReadFile(filename, total_lines);
    }

    MPI_Bcast(lines, total_lines, MPI_CHAR, 0, MPI_COMM_WORLD);
    job_allocator(rank, total_lines, number_of_tasks, lines);
    MPI_Barrier(MPI_COMM_WORLD);
    PrintResults(total_lines);

    free(lines);
    free(results);
    return 0; // success
  }
} // end main
