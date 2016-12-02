/* the program to analyze the binary file */
#include<stdlib.h>
#include<stdio.h>
#include"P2headers.h"
void analyze(FILE* inpf)
{
  unsigned char L; /* stores the length */
  unsigned int numb; /* stores the integer */
  char* str = (char*)malloc(256*sizeof(char));
  unsigned int max=0; /* stores the max integer */
  unsigned int min= numb ; /* stores the min integer */
  unsigned int maxL=0 ; /*stores the max string length */
  unsigned int minL= 255 ; /* stores the min string length */
  
  /* checks if there is a malloc error */
   if( str == NULL )
    {
      fprintf(stderr,"malloc error");
      exit(1);
    }
   /* reads the binary file and finds out the max and min values */
  while(fread(&L,sizeof(char),1,inpf) == 1)
    {
      fread(str,sizeof(char),L,inpf);
      fread(&numb,sizeof(int),1,inpf);
    
      if((int)L >= maxL)
	maxL = L;
      if((int)L <= minL)
	minL = L;
      if(numb >= max)
	max = numb;
      if(numb <= min)
	min = numb; 
    }
  printf("For %s :\n", inpf); /* prints the result for the file */
  fprintf(stdout,"Length of shortest string = %u\n", minL );
  fprintf(stdout,"Length of longest string = %u\n", maxL );
  fprintf(stdout,"value of maximum integer = %u\n", max) ;
  fprintf(stdout,"value of minimum integer = %u\n", min);
    
}
