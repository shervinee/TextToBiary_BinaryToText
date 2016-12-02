/* the main file of the program */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "P2headers.h"

int main(int argc, char* argv[])
{
  FILE *inpf;/* stores the input file */
  FILE *outf;/* stores the ouput file */
  if((inpf=fopen(argv[2],"r+"))== NULL ) /* checks the input file */
    {
    fprintf(stderr,"Could not open the %s file.\n",argv[2]);
    exit(1);
    }
  
  /* checks the flag and verifies the number of arguments 
     after verification it calls the corresponding function */
   if(strcmp(argv[1],"-t") == 0 && argc == 4) 
     {
        if((outf=fopen(argv[3],"w+"))== NULL )
	  {
	    fprintf(stderr,"Could not open the %s file.\n",argv[3]);
	    exit(1);
	  }
       textToBin(inpf,outf);
     }
   else if(strcmp(argv[1],"-b") == 0 && argc == 4)
     {
        if((outf=fopen(argv[3],"w+"))== NULL )
	  {
	    fprintf(stderr,"Could not open the %s file.\n",argv[3]);
	    exit(1);
	  }
       binToText(inpf,outf);
     }
   else if(strcmp(argv[1],"-s") == 0 && argc == 3)
     {
       analyze(inpf);
     }
   else{
     fprintf(stderr,"invalid input\n");
     exit(1);
   }

   fclose(inpf);
   fclose(outf);

   return 0;
}// end of main 
