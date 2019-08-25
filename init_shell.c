#include "bash.h"
void init_shell()
{
	char *disp;
	disp=(char *)malloc(1024*sizeof(char));
	strcat(disp,"<");
	strcat(disp,username);
	strcat(disp,"@");
	strcat(disp,sysname);
	strcat(disp,":");
	char *pdir=(char *)malloc(1024*sizeof(char));
	if(strcmp(home,cur_dir)==0)
	{
		pdir="~";
	}else if(strstr(cur_dir,home)!=NULL)
	{
		char *temp=(char *)malloc(1024*sizeof(char));
		int p=0;
		for(int x=strlen(home);x<strlen(cur_dir);x++)
		{
			temp[p]=cur_dir[x];
			p++;
		}
		strcat(pdir,"~");
		strcat(pdir,temp);
	}else if(strstr(home,cur_dir)!=NULL)
	{
		strcat(pdir,cur_dir);
	}else
	{
		pdir="~";
	}
	strcat(disp,pdir);
	strcat(disp,"> ");
	printf("%s",disp );
}