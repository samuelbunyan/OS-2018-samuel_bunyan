#include <stdio.h>
int main(int argc,char*argv[])
{
char str[999];
FILE * file;
file = fopen(argv[1],"r");
if (file) {
    while (fscanf(file, "%s", str)!=EOF)
        printf("%s",str);
    fclose(file);
}}

