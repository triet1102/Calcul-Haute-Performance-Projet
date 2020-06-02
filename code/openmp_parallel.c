#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <crypt.h>
#include <omp.h>
#include<time.h>

char * readline(FILE * f) {
	char * line = NULL;
    size_t len = 0;
	ssize_t read;
    if ((read = getline(&line, &len, f)) != -1) {
	line[read-1] = '\0';

      return line;
    }
	return NULL;
}
			
int main(int argc, char **argv)
{
	if(argc !=4) fprintf(stderr, "Usage:./go2 nb_thread dict_hashed shadow\n", argv[0]), exit(EXIT_FAILURE);	
	char * dict_file = argv[2];
	char * shasum_file = argv[3];
	FILE * ds = fopen(shasum_file, "r");
  	int i, thread_id, nb_thread;
	char * line;

	//set number of thread
	nb_thread = atoi(argv[1]);
	omp_set_num_threads(nb_thread);
	//parallel zone, each thread will execute parallelly the code in the zone below 
	#pragma omp parallel private(thread_id)
  	{
		#pragma omp for
		for (i=0; i<3000; ++i)
		  {
		    line = readline(ds);
		    char cmd[100]="";
		    thread_id = omp_get_thread_num();
		    //printf("thread=%d\tline=%s\n",thread_id,line);
		    sprintf(cmd,"%s %s %s","grep",line,"dict_hashed.txt");
		    system(cmd);
		  }
  	}
    fclose(ds);
  return 0;
}
