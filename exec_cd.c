#include "bash.h"
void exec_cd(char *s)
{
	int csp=0;
	for(int x=0;x<strlen(s);x++)
	{
		if(s[x]==' ' && x!=(strlen(s)-1))
		{
			csp++;
		}
	}
	if(csp>1)
	{
		printf("cd: too many arguments\n");
	}else if(csp==0)
	{
		strcpy(cur_dir,home);
	}else
	{	
		char* token = strtok(s, " "); 
		token = strtok(NULL, " "); 
		if(strcmp(token,"~")==0 || strcmp(token,"~ ")==0)
		{
			strcpy(token,home);
		}else if(token[0]=='~')
		{
			char *tmp=(char *)malloc(1024*sizeof(char));
			strcat(tmp,home);
			strcat(tmp,token+1);
			strcpy(token,tmp);
		}
		if(chdir(token)<0)
		{
			perror("cd");
		}else
		{
			getcwd(cur_dir,1024);
		}
	}
}