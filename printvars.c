#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    // TODO
    printf("Running parent process PID: %d\n\n", getpid());
    const char *file = "./echoall";
    const char *file2 = "echoall";
    const char *arg1 = "Bandicoot";
    const char *arg2 = "Pacman";
    const char *arg3 = "Spyro";

    int pid = fork();
    if(pid == 0){
        printf("Running child process PID: %d\n", getpid());

        int pid2 = fork();
        if(pid2 == 0){
            
            printf("Running child process PID: %d\n", getpid());

            execlp(file, file2, arg3, NULL);
        }else{
            execle(file, file2, arg1, arg2, NULL, custom_env);
        }

        

        
    }else{
        int status;

        waitpid(pid, &status, 0);
    }
    
    exit(0);
}