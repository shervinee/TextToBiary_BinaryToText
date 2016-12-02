/* program to convert the binary file to text */
#include<stdlib.h>
#include"P2headers.h"
void binToText(FILE *inpf, FILE *outf)
{
  unsigned char L;/* stores the length */
  unsigned int numb;/* stores the integer */
  unsigned char* str = (char*)malloc(256*sizeof(char)); 
  
  /* checks if there is a malloc error */ 
   if( str == NULL )
    {
      fprintf(stderr,"malloc error");
      exit(1);
    }
   /* reads the binary file and prints the output on the text file */
  while(fread(&L,sizeof(char),1,inpf) == 1)
    {
      fread(str,sizeof(char),L,inpf);
      fread(&numb,sizeof(int),1,inpf);
      str[L]= '\0' ; /* adding the null character at the end of string */
      if(ftell(outf) == 0)
	 fprintf(outf,"%s\t%u",str,numb); 
      else
	fprintf(outf,"\n%s\t%u",str,numb);/* adds the new line character */
    }//end of loop
}//end of function 
