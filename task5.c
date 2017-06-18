#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

char msg_pid1[]="Child process p1 is sending a message!";
char msg_pid2[]="Child process p2 is sending a message!";

int main(){
	int chan1[2],chan2[2];
	char buf[100]="error";
	if(pipe(chan1)==-1||pipe(chan2)==-1)perror("pipe");

	printf("main:I am main process\n");
	printf("main:My PID is %d\n",getpid());

	int pid1=0;
	pid1=fork();
	if(pid1==0){
		wait(NULL);
		printf("p1:My PID is %d\n",getpid());
		
		close(chan1[0]); close(chan2[1]);
		write(chan1[1],msg_pid1,sizeof(msg_pid1));
		close(chan1[1]);
		read(chan2[0],buf,100);
		printf("p1:%s\n",buf);
		close(chan2[0]);

		int pid3=0;
		pid3=fork();
		if(pid3==0){//pid3中运行
			printf("p3:I am child process p3\n");
			printf("p3:My PID is %d\n",getpid());
			char *argv[]={"ls","-al",NULL};
			char *envp[]={0,NULL};
			execve("/bin/ls",argv,envp);
		}
		return 0;
	}

	int pid2=0;
	pid2=fork();
	if(pid2==0){
		wait(NULL);
		printf("p2:My PID is %d\n",getpid());
	
		close(chan1[1]); close(chan2[0]);
		read(chan1[0],buf,100);
		printf("p2:%s\n",buf);
		write(chan2[1],msg_pid2,sizeof(msg_pid2));
		close(chan2[1]); close(chan1[0]);
		return 0;
	}

}
