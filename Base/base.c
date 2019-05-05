#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define NUM_THREADS 1

//#pragma omp private(results)


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
void PrintResults(char **results, int total_lines)
{
  int i;
  for (i=0; i<total_lines; i++)
  {
    printf("%d-%d: %s\n", i, i+1, results[i]);
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
    char** results = (char **) malloc( total_lines * sizeof( char * ) );
    for(i=0; i < total_lines; i++)
    {
      results[i] = malloc( sizeof(char)*4001 );
    }

    char **lines = ReadFile(filename, total_lines);

    if (lines != NULL) {
      for (j=0;j<total_lines-1;j++)
      {
        char *A = lines[j];
        char *B = lines[j+1];
        char *answer = lcs(A, B);
        results[j] = answer;
      }
      free(lines);
      PrintResults(results, total_lines);
      free(results);
    }
    else
    {
      free(lines);
      free(results);
      printf("File failed to load");
      return 1; //failed
    }
    return 0; // success
  }
} // end main
