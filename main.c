#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static void sighandler(int signo) {
	if(signo == SIGUSR1){
		printf("Current parent process ID: %d\n", getppid());
  }
  if(signo == SIGINT){
		int text_file = open("signal.txt", O_WRONLY | O_APPEND);
		write(text_file, "The process ended due to SIGINT.", strlen("The process ended due to SIGINT."));
		close(text_file);
    printf("File has been written to! The process ended due to SIGINT.\n");
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
