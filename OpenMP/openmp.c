#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <omp.h>

char *filename;
int number_of_threads;
int number_of_lines;
char** longest_common;
char** stored_file;
omp_lock_t o_lock;

void lcs()
{
  
}

void readFile(char* file_name)
{
  FILE *fd;
  int i = 0;
  int nlines, err;
  stored_file = (char **) malloc( number_of_lines * sizeof( char * ) );
  for( i = 0; i < number_of_lines + 1; i++ ) 
  {
    stored_file[i] = malloc( sizeof(char)*4001 );
  }
  fd = fopen(file_name, "r");
	nlines = -1;
	do {
    err = fscanf(fd, "%[^\n]\n", stored_file[++nlines]);
  } while (err != EOF && nlines < number_of_lines);
	fclose( fd );
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
    printf("you are not missing arguments\n");
    // Collect Args
    filename = argv[1];
    number_of_lines = atoi(argv[2]);
    number_of_threads = atoi(argv[3]);
    
    // OpenMP Variables
    omp_init_lock(&o_lock);
    int start_point;
    int end_point;
    int thread_num;
    char** temp_longest_common;
    int i;
    
    // Read File
    readFile(filename);

    printf("File read.\n");
        
    // OpenMP Parallelization
    omp_set_num_threads(number_of_threads);
    #pragma omp parallel private(start_point, end_point, thread_num, temp_longest_common, i)
    {
      thread_num = omp_get_thread_num();
      start_point = thread_num * number_of_lines / number_of_threads;
      end_point = start_point + number_of_lines / number_of_threads;
      temp_longest_common = longest_common + start_point;
      
      if (thread_num == number_of_threads - 1)
      {
        end_point = number_of_lines - 1;
      }
      
      for (i = start_point; i < end_point; i++)
      {
        lcs(stored_file[i], stored_file[i + 1], longest_common);
        temp_longest_common++;
      }
    }
    printf("%s\n", longest_common[0]);
  }
}