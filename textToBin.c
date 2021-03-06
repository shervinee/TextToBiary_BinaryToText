/* program to convert a text file data into a binary file */
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void textToBin(FILE *inpf, FILE *outf )
{
  unsigned char* str = (char*)malloc(256*sizeof(char)); /* stores the string */
  unsigned int numb;/* stores the integer value */
  unsigned char L; /* stores the string length */

  /* checks if there's a malloc error for the string */
  if( str == NULL )
    {
      fprintf(stderr,"malloc error");
      exit(1);
    }
  
  /* reads the text file and writes the output onto a binary file */
  while(fscanf(inpf,"%s\t%d",str,&numb) != EOF )
  {
    L = strlen(str);
    fwrite(&L,sizeof(char),1,outf);
    fwrite(str,strlen(str),sizeof(char),outf);
    fwrite(&numb,sizeof(int),1,outf);
  }//end of loop
}//end of function
