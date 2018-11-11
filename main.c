#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <string.h>

// signalhandler
void sighandler(int signum){
  if(signum == SIGINT){
    int err_fd = open("err.txt", O_CREAT|O_WRONLY);
    lseek(err_fd, 0, SEEK_END);
    char buff[50];
    sprintf(buff, "%ld: Program exited due to SIGINT\n", time(NULL));
    write(err_fd, buff, strlen(buff));
    close(err_fd);
    exit(EXIT_FAILURE);
  }
  if(signum == SIGUSR1){
    printf("  Hello Again! My parent process id is %d\n", getppid());
  }
}

int main(){
  while(1){
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    printf("Hello! My process id is %d\n", getpid());


    sleep(1);
  }

  return 0;
}
