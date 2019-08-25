#include "bash.h"
int countbg;
int lsc;
char *home;
char *cur_dir;
char *sysname;
char *username;
char *buf;
char semic[100][1024];
int pidstore[100];
int flp[100];
char namestore[100][1024];
int cnt;
int piddd;
int main(void)
{
	cnt=0;
	lsc=0;
	countbg=0;
	ecec_fg("clear");
	home=(char *)malloc(1024*sizeof(char));
	cur_dir=(char *)malloc(1024*sizeof(char));
	sysname=(char *)malloc(1024*sizeof(char));
	username=(char *)malloc(1024*sizeof(char));
	username=getenv("USER");
	gethostname(sysname,1024);
	getcwd(home,1024);
	getcwd(cur_dir,1024);
	// init_shell();
	buf=(char *)malloc(1024*sizeof(char));
	// fgets(buf,1024,stdin);
	// strtok(buf,"\n");
	char *ck=(char *)malloc(1024*sizeof(char));
	// ck=trimm(buf);
	while(!(strcmp(ck,"exit")==0 || strcmp(ck,"exit ")==0))
	{
		init_shell();
		fgets(buf,1024,stdin);
		strtok(buf,"\n");
		ck=trimm(buf);
		lsc=input_process();
		for(int x=0;x<lsc;x++)
		{
			char *tsc=(char *)malloc(1024*sizeof(char));
			strcpy(tsc,semic[x]);	
			if(strstr(tsc,"&")!=NULL)
			{
				tsc=trimm(tsc);
				pid_t pid;
				int status;
				pid=fork();
				char *commands[1024]={};
				toknnise(tsc,commands);
				if(pid<0)
				{
					printf("ERROR: forking child process failed\n");
					exit(0);
				}else if(pid>0)
				{
					pidstore[cnt]=pid ;
					strcpy(namestore[cnt],commands[0]);
					flp[cnt]=1;
					cnt++;
				}else 
				{
					setpgid(0,0);
					close(STDOUT_FILENO);
					close(STDERR_FILENO);
					if(execvp(commands[0],commands)<0)
					{
						perror(commands[0]);
						exit(0);
					}
				}
			}else
			{
				checkfunc(semic[x]);
			}
		}
		// fgets(buf,1024,stdin);
		// strtok(buf,"\n");
		// ck=trimm(buf);
		int status;
		pid_t pid;
		while((pid = waitpid(-1, &status, WNOHANG)) > 0) 
		{
			for(int x=0;x<cnt;x++)
			{
				if(pidstore[x]==pid && flp[x]==1)
				{
					flp[x]=0;
					printf("Process %s with pid %d exited with status %d\n",namestore[x],pid,WEXITSTATUS(status)); 
				}
			}
		}
		// checkfunc(countbg);
		
	}
}