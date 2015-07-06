#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

int main (){

	int pid;
	int fd[2];
	char buf[256];

	pipe(fd);

	switch(pid = fork()){
		case -1:
			printf("ERROR\n");
			return -1;
		case 0:
			printf("It's CHILD pid:%d\n", getpid());
			close(fd[1]);
			read(fd[0], buf, sizeof("Mess from par"));
			printf("%s\n", buf);
			return 0;
		default:
			printf("It's parent pid %d\n", getpid());
			close(fd[0]);
			write(fd[1], "Mess from par", sizeof("Mess from par"));
	}
}
