#include <stdio.h>
int main(int argc, char*argv[])
{
FILE * testFile;
char test[255];
//char searchWord[255];

//searchWord = argv[1];
testFile = fopen(argv[2],"r");
if(testFile){
        while(fscanf(testFile,"%[^\n]\n",test) !=EOF){
                if(strstr(test,argv[1]) != NULL )
			printf("%s \n",test);

}fclose(testFile);
}}
