/**
*Samuel Bunyan 
*File: wis.c
*Operating systems lab2
***/

/**
*implmentation of linux shell
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void clearuserInput (char * userInput){
char length=strlen(userInput);
    if(userInput[length-1] == '\n'){
        userInput[length-1] = '\0';
    }
}


int main (int argc, char *argv[]){
char *userInput;
size_t sizeBuffer = 40;
char *param[30];
char *pathBin = "/bin/";
char *pathUser = "/usr/bin/";

userInput = (char *)malloc(sizeBuffer * sizeof(char));
if( argc == 1) {
  while(1) {
    printf("wish> ");
    getline(&userInput, &sizeBuffer, stdin);
    clearuserInput(userInput);
    int i =0;
    char *token = strtok(userInput, " ");
    char *array[12] ={NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL,NULL,NULL};
    while(token != NULL)
      {
        param[i] = token;
        i =i +1;
        token = strtok(NULL, " ");
      }
      for(int j=1; j<i;j++)
        {  
          array[j]=param[j];
        }
        char  *path1 = malloc(strlen(pathBin)+ strlen(param[0]) +1 ); 
        strcat(path1, pathBin); 
        strcat(path1,param[0]); 
        char  *path2 = malloc(strlen(pathUser)+ strlen(param[0]) +1 );
        strcat(path2, pathUser);
        strcat(path2, param[0]);    

        if(strcmp(param[0],"exit")==0)
          {
            exit(0);
          }
          else if(strcmp(param[0],"cd")==0)
            {
              if (chdir(param[1])==0)
                {
                  printf("%s\n","Folder entered." );
                }
              else
                {
                  printf("%s\n","No folder with such name." );
                }
            }
          else 
            {
               pid_t pid = fork();
                      if(pid==0)
                      {
                          if(access(path1,X_OK)==0){
                              array[0]=path1;
                              execv(path1,array);
                          }
                          else if(access(path2,X_OK)==0){
                              array[0]=path2;                        
                              execv(path2,array);
                          }else{
                              printf("%s\n","Access denied." );
                          }
                      }
                      else
                      {
                        wait(NULL);
                      }
            }
    }      
  }

//batch mode
else if(argc == 2)
  {
    FILE *fp = fopen(argv[1], "r"); 
    if (fp == NULL)
      { 			
			 printf("No contents in file.\n");
			 return 0;
      }
      while(getline(&userInput, &sizeBuline != -1)
          { 
            clearuserInput(userInput);
            int i =0;
            char *token = strtok(userInput, " ");
            char *array[12] ={NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL,NULL,NULL};
            while(token != NULL)
              {
                param[i] = token;
                i =i +1;
                token = strtok(NULL, " ");
              }
              for(int j=1; j<i;j++)
                {
                  array[j]=param[j];
                }
                char  *path1 = malloc(strlen(pathBin)+ strlen(param[0]) +1 ); 
                strcat(path1, pathBin); 
                strcat(path1,param[0]); 
                char  *path2 = malloc(strlen(pathUser)+ strlen(param[0]) +1 );
                strcat(path2, pathUser);
                strcat(path2, param[0]);
      
      //batch mode
                if(strcmp(param[0],"exit")==0)
                  {
                    exit(0);
                  }
                else if(strcmp(param[0],"cd")==0)
                  {
                    if 
                    }
                             line   {
                        printf("%s\n","Folder entered" );
                      }
                    else
                      {
                        printf("%s\n","No folder with such name." );
                      }
                  }
                else
                  {
                     pid_t pid = fork();
                      if(pid==0){
                          if(access(path1,X_OK)==0){
                              array[0]=path1;
                              execv(path1,array);
                          }
                          else if(access(path2,X_OK)==0){
                              array[0]=path2;                        
                              execv(path2,array);
                          }else{
                              printf("%s\n","Access denied." );
                          }
                      }
                      else
                      {
			                   wait(NULL);
                      }             
                  }
	}
}
fclose(fp);
}

return 0;
}