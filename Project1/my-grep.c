#include <stdio.h>
#include <string.h>
int main(int argc, char*argv[])
{
FILE * testFile;
char charCnstr[255];

testFile = fopen(argv[2],"r");
if(testFile){
        while(fscanf(testFile,"%[^\n]\n",charCnstr) !=EOF){
                if(strstr(charCnstr,argv[1]) != NULL )
			printf("%s \n",charCnstr);

}fclose(testFile);
}}
