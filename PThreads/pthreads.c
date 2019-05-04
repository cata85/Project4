#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>


#define NUM_THREADS 1

//#pragma omp private(results)

typedef struct
{
  int start, stop;
  char **lines;
  char **results;
} lcs_result;


//this method is found https://gist.github.com/adrian-source/4111719 .... THIS CODE IS NOT MINE
char* lcs(char* s1, char* s2)
{
  /*
  #pragma omp private(s1, s2, s1_l, s2_l, i, sl_i, s2_i,longest, set, v)

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
  */

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

// this was my implementation for LCS, I coudn't get it to work so I am using someone else's in order to get to the parrellism part of the assignment and start the write up on time
/*
// this function is what I am going to try to feed it two string and I want it to return the largest substring, it will somehow need to run the for loops in parallel.
char * LCSubstr (char *S, char *T) 
{
  int L[strlen(S)][strlen(T)]; // I need to find the correct way to initialzie this array, based on the current parameters that are getting passed in    
  int z = 0;// this is the current count for the 'longest' substring, initialized to zero before the loop
 // char ret[4000]; // I will need to make this the 'returning' set which will include the longest substring 
  int i, j;  
  int diff = 0;
  //the pseudocode on wikipedia assumes that we are doing 1 indexing, if this fails, try to fall back to 0 indexing the arrays. 
  for (i = 0; i <= strlen(S); i++)
   {
    for (j = 0; j <= strlen(T); j++) 
     {
  if (S[i] == T[j])	
  {
    if (i == 1 || j == 1)
    {
      L[i][j] = 1;
    }
    else { L[i][j] = L[i-1][j-1] +1;	}
    if (L[i][j] > z)
    {
      z = L[i][j];
    //	ret = S[i-z+1, i] // WHAT I REALLY WANT HERE IS THE SUBSTRING!!!!!!!!!	
            diff = i-(i-z+1);
        strncpy(ret, &S[i-z+1], diff);
    }
    else if (L[i][j] == z)
    {
      char* temp;

            diff = i-(i-z+1);

      strncpy(temp, &S[i-z+1], diff);

      strcat(ret,temp); // SAME AS ABOVE, WE WANT TO APPEND THE STRING HERE!!!!

    }
  } // end if
  else
  {
        printf("in the else");
    L[i][j] = 0; 	
  }		

     } // end of inner for loop

   } //end of outer for loop

  return ret; // i need to make sure ret has the correct string that is the longest substring that we are returning
} // end LCSubstr
*/

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
  /*
  i = 0;
	if ((fd = fopen(filename, "r")) != NULL)
  {
    while (fgets(lines[i], 4000, fd) != NULL) 
    {
      len = strlen(lines[i]);
      while (len && isspace(lines[i][len - 1]))
      {
        len--;
      }
      lines[i][len] = '\0';	
      i++;
      if (i >= total_lines)
      {
        break;
      }
    }
    return lines;
  }
  */
  return lines;
}

// this method prints the results from the results 
void PrintResults(char **results, int total_lines)
{
  int i;
  for (i=0; i<total_lines - 1; i++)
  {
    printf("%d-%d: %s\n", i, i+1, results[i]); 
  }
}

void * lcs_function(lcs_result *tr)
{
  lcs_result *thread_results = tr;
  int j;
  for (j=thread_results->start;j<thread_results->stop;j++)
  {
    char *A = thread_results->lines[j];
    char *B = thread_results->lines[j+1];
    char *answer = lcs(A, B);
    thread_results->results[j] = answer;
  }
  return NULL;
}

int main (int argc, char *argv[]) 
{
  if (argc < 4)
  {
    printf("You are missing arguments");
    return 0;
  }
  else
  {
    char *filename = argv[1];
    int total_lines = atoi(argv[2]);
    int thread_number = atoi(argv[3]);
    int i;
    pthread_t threads[thread_number];

    char **lines = ReadFile(filename, total_lines);
    if(lines == NULL)
    {
      free(lines);
      printf("File failed to load");
      return 1; //failed
    }

    int tasksPerThread=(total_lines+thread_number-2)/thread_number; // this rounds up the number of tasks per thread

    char** results = (char **) malloc( (total_lines - 1) * sizeof( char * ) );
    for(i=0; i < total_lines - 1; i++) 
    {
      results[i] = malloc( sizeof(char)*4001 );
    }

    lcs_result** thread_results = malloc( thread_number * sizeof( lcs_result* ) );
    for(i = 0; i < thread_number; i++ ) 
    {
      thread_results[i] = (lcs_result *) malloc( sizeof(lcs_result) );
      thread_results[i]->results = results;
      thread_results[i]->lines = lines;
      thread_results[i]->start = i * tasksPerThread;
      thread_results[i]->stop= (i+1) * tasksPerThread;
    }
    /* the last thread must not go past the end of the array */
    thread_results[thread_number-1]->stop = total_lines - 2;

    for (i=0; i<thread_number; i++) 
    {
        pthread_create(&threads[i], NULL, lcs_function, &thread_results[i]);
    }
    for (i=0; i<thread_number; i++) {
        pthread_join(threads[i], NULL);
    }

    free(lines);
    PrintResults(results, total_lines);
    free(results);
    
    return 0; // success
  }
} // end main
