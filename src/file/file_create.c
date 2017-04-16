#include <stdio.h>

int main()
{
   FILE *fp;
 
   fp = fopen("file.txt", "w");

   fprintf(fp, "%s", "这里是 w3cschool.cc");
   fclose(fp);
   
   return(0);
}