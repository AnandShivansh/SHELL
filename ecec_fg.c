#include "bash.h"
void ecec_fg(char *s)
{
	pid_t pid;
	int status;
	pid=fork();
	char *commands[1024]={};
	toknnise(s,commands);
	if(pid<0)
	{
		printf("ERROR: forking child process failed\n");
		exit(1);
	}else if(pid==0)
	{
		if(execvp(commands[0],commands)<0)
		{
			perror(commands[0]);
			exit(1);
		}
	}else
	{
		//while(wait(&status)!=pid);
		waitpid(pid,&status,WUNTRACED);
	}
}