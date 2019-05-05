#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>


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

// this method prints the results from the results 
void PrintResults(char *results, int total_lines)
{
  int i, j;
  char *answer;
  for (i=0; i<total_lines-1; i++)
  {
    answer = malloc(sizeof(char) * 4001);
    for(j=0; j < 4001; j++)
    {
      if (results[(i*4001)+j] != '\0')
      {
        answer[j] = results[(i*4001)+j];
      }
      else
      {
        answer[j] = '\0';
        break;
      }
    }
    printf("%d-%d: %s\n", i, i+1, answer); 
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
    char *lines;
    char *results;
    MPI_Status status;

    int ierr = MPI_Init(&argc, &argv);

    if (ierr != MPI_SUCCESS)
    {
      printf("Error: MPI could not start.\n");
      MPI_Abort(MPI_COMM_WORLD, ierr);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &number_of_tasks);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    lines = malloc(sizeof(char)*total_lines*4001);

    results = malloc(sizeof(char)*total_lines*4001);

    // Initialize arrays.
    for(i = 0; i < total_lines*4001; i++)
    {
      lines[i] = '\0';
      results[i] = '\0';
    }

    // Read file.
    FILE *file = fopen(filename, "r");
    int line_num = 0;
    char line[4001];
    while(fgets(line, 4001, file) != NULL && line_num < total_lines)
    {
      if ((char) line[0] == '\n')
      {
        line_num--;
      }
      else
      {
        for (i=0; i<4001; i++)
        {
          if ((char) line[i] != NULL && (char) line[i] != '\n' && (char) line[i] != '\0')
          {
            lines[(line_num*4001)+i] = (char) line[i];
          }
          else 
          {
            break;
          }
        }
      }
      line_num++;
    }
    fclose(file);





    // Parallelize.
    MPI_Bcast(lines, total_lines*4001, MPI_CHAR, 0, MPI_COMM_WORLD);
    int num_of_elements_per_process = total_lines / number_of_tasks;
    int startPos = ((long) rank) * (num_of_elements_per_process);
    int endPos = startPos + (num_of_elements_per_process);
    if (rank == number_of_tasks - 1)
    {
      endPos = total_lines;
    }

    char *local_results = malloc(sizeof(char)*num_of_elements_per_process*4001);
    for(i= 0; i < num_of_elements_per_process*4001; i++)
    {
      local_results[i] = '\0';
    }

    char *line1;
    char *line2;
    for (i=startPos; i<endPos; i++)
    {
      line2 = malloc(sizeof(char) * 4001);
      line1 = malloc(sizeof(char) * 4001);
      for(j=0; j < 4001; j++)
      {
        if (lines[(i*4001)+j] != '\0')
        {
          line1[j] = lines[(i*4001)+j];
        }
        else
        {
          line1[j] = '\0';
          break;
        }
      }
      for(j=0; j < 4001; j++)
      {
        if (lines[((i+1)*4001)+j] != '\0')
        {
          line2[j] = lines[((i+1)*4001)+j];
        }
        else
        {
          line2[j] = '\0';
          break;
        }
      }
      char *answer = lcs(line1, line2);
      size_t length = strlen(answer);
      for (j=0; j<length; j++)
      {
        local_results[(i*4001)+j] = answer[j];
      }
    }

    MPI_Reduce(local_results, results, total_lines*4001, MPI_CHAR, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
      PrintResults(results, total_lines);
      free(lines);
      free(results);
    }

    free(local_results);

    MPI_Finalize();
    return 0; // success
  }
} // end main
