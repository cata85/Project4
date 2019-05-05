#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #include <omp.h>

char *filename;
int number_of_threads;
int number_of_lines;

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


  // printf("%s\n+\n%s\n=\n%s\n\n", s1, s2, set);
	// return
	return set;
}

char** readFile(char* file_name)
{
  int i, nlines, err;
  char** stored_file = malloc(sizeof(char*) * number_of_lines);
  for (i = 0; i < number_of_lines; i++)
  {
    stored_file[i] = malloc(sizeof(char) * 4001);
  }
  FILE *fd;
  fd = fopen(file_name, "r");
	nlines = -1;
	do {
    err = fscanf(fd, "%[^\n]\n", stored_file[++nlines]);
  } while (err != EOF && nlines < number_of_lines);
  fclose( fd );
  return stored_file;
}

void PrintResults(char** string_collection)
{
  int i;
  for (i=0; i < number_of_lines - 1; i++)
  {
    printf("%s\n", string_collection[i]);
  }
}

int main (int argc, char *argv[])
{
  if (argc < 4)
  {
    printf("You are missing arguments\n");
    return 0;
  }
  else
  {
    // File and Collection
    char** stored_file;
    char** string_collection;

    // Collect Args
    filename = argv[1];
    number_of_lines = atoi(argv[2]);
    number_of_threads = atoi(argv[3]);

    // OpenMP Variables
    int i, j;
    char* s1;
    char* s2;
    char* longest;

    // Init File and Collection
    stored_file = readFile(filename);
    string_collection = (char **) malloc( number_of_lines * sizeof( char * ) );

    // OpenMP Parallelization
    // omp_set_num_threads(number_of_threads);

    // #pragma omp parallel
    // {
      for (i = 0; i < number_of_lines - 1; i++)
      {
        s1 = stored_file[i];
        s2 = stored_file[i + 1];
        longest = lcs(s1, s2);
        string_collection[i] = longest;
      }
    // }
    PrintResults(string_collection);
  }
}
