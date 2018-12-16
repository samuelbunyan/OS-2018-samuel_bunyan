#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

void linecheck (char * line){
char len=strlen(line);
    if(line[len-1] == '\n'){
        line[len-1] = '\0';
    }
}

void program_error (){
	char error_message[30] = "An error occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
}


int main (int argc, char *argv[]){
char *line;
size_t buffer = 100;
char *bin_ = "/bin/";
char *user = "/usr/bin/";
char *args[100];

line = (char *)malloc(buffer * sizeof(char));
  if( argc == 1) 
    {
    while(1) 
      {
      printf("wish> ");
      getline(&line, &buffer, stdin);
      linecheck(line);
      int i =0;

      char *token = strtok(line, " ");
      char *array[5] ={NULL,NULL, NULL, NULL, NULL};
      
      while(token != NULL)
        {
        args[i] = token;
        i =i +1;
        token = strtok(NULL, " ");

        }
        for(int j=1; j<i;j++)
          {
          array[j]=args[j];
          }

          char  *path1 = malloc(strlen(bin_)+ strlen(args[0]) +1 ); 
          strcat(path1, bin_);  
          strcat(path1,args[0]); 
          char  *path2 = malloc(strlen(user)+ strlen(args[0]) +1 );
          strcat(path2, user);
          strcat(path2, args[0]);
            
          if(strcmp(args[0],"exit")==0)
            {
              exit(0);
            }
          else if(strcmp(args[0],"cd")==0)
            {
              if (chdir(args[1])==0)
                {
                  printf("%s\n","you entered the folder" );
                }
              else
                {
                  program_error();    
                }
            }
          else 
            {
              pid_t pid = fork();
              
              if(pid==0)
                {
                if(access(path1,X_OK)==0)
                  {
                    array[0]=path1;
                    int filename = open("filename.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
                    dup2(filename, 1); 
                    dup2(filename, 2);  
                    close(filename);
                    execv(path1,array);
			            }
                else if(access(path2,X_OK)==0)
                  {
                    array[0]=path2;                        
                    execv(path2,array);
                  }
                else
                  {
                    program_error(); 
                  }
                }
              else
                {
                  wait(NULL);
                }
            }
      }    
    }

    else if(argc == 2)
      {
        FILE *filename = fopen(argv[1], "r"); 
		    
        if (filename == NULL)
          { 			
            printf("File is empty\n");
            return 0;
          }
		else
      {
        while(getline(&line, &buffer, filename) != -1)
          { 
            linecheck(line);
            int i =0;
            char *token = strtok(line, " ");
            char *array[5] ={NULL,NULL, NULL, NULL, NULL};
            
            while(token != NULL)
              {
                args[i] = token;  
                i =i +1;
                token = strtok(NULL, " ");
              }

              for(int j=1; j<i;j++)
                {
                  array[j]=args[j];
                }

                char  *path1 = malloc(strlen(bin_)+ strlen(args[0]) +1 ); //al$
                strcat(path1, bin_);
                strcat(path1,args[0]); 
                char  *path2 = malloc(strlen(user)+ strlen(args[0]) +1 );
                strcat(path2, user);
                strcat(path2, args[0]);

                if(strcmp(args[0],"exit")==0)
                  {
                    exit(0);
                  }
                else if(strcmp(args[0],"cd")==0)
                  {
                    if (chdir(args[1])==0)
                      {
                        printf("%s\n","Folder opened" );
                      }
                             
                    else
                      {
	                      program_error();
	                    }
                  }
                else 
                  {
			              pid_t pid = fork();
			              
                    if(pid==0)
                      {
			                  if(access(path1,X_OK)==0)
                          {
			                      array[0]=path1;
			                      execv(path1,array);
			                    }
			                  else if(access(path2,X_OK)==0)
                          {
			                      array[0]=path2;                        
			                      execv(path2,array);
			                    }

                        else
                          {
			                      printf("%s\n","No access for paths" );
			                    }
			                }
			              else
                      {
			                  wait(NULL);
			                }
                  }
	           }
      }

fclose(filename); 		
}

return 0;
}
