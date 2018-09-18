#include <stdio.h>
int main(int argc,char*argv[])
{
FILE * testFile;
char str[255];
testFile = fopen(argv[1],"r");
if (testFile) {
    while (fscanf(testFile, "%s", str)!=EOF)
        printf("%s ",str);
fclose(testFile);
}}

