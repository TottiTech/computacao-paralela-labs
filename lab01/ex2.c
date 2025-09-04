 #include <stdio.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdlib.h>

 int main () {
 pid_t pid;
 int num_filhos = 4;

 printf("Eu sou o pai! Meu PID e %d\n", getpid());

for(int i = 0; i < num_filhos; i++){
    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork falhou! \n");
    }
    else if(pid == 0){
        printf("Eu sou o filho numero %d! Meu PID e %d, meu pai e %d.\n", i+1, getpid(), getppid());
        exit(0);
    }
    
}

 for(int i = 0; i < num_filhos; i++){
    wait(NULL);
 }
 return 0;
}