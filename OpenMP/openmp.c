#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <omp.h>

int number_of_threads;
int number_of_lines;
char** longest_common;
char** stored_file;

void lcs()
{

}

void readFile()
{
  
}

int main (int argc, char *argv[]) 
{
  if (argc < 3)
  {
    printf("You are missing arguments");
    return 0;
  }
  else
  {
    // Collect Args
    number_of_threads = atoi(argv[1]);
    number_of_lines = atoi(argv[2]);
    // OpenMP Variables
    int start_point;
    int end_point;
    int thread_num;
    char** temp_longest_common;
    int i;
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
          // lcs((void*)stored_file[i], (void*)stored_file[i + 1], longest_common);
          temp_longest_common++;
      }
    }
  }
}