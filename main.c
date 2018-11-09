#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo) {
	if(signo == SIGUSR1){
		printf("Current parent process ID: %d\n", getppid());
  }
  if(signo == SIGINT){
    printf("The process ended due to SIGINT.\n");
    exit(0);
  }
}

int main() {
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while(1) {
		printf("hello, the current process ID is: %d\n", getpid() );
		sleep(1);
  }
  return 0;
}
