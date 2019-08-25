#include "bash.h"
void exec_pinfo(char *s)
{
	// printf("%s\n",s );
	char *commands[1024]={};
	toknnise(s,commands);
	// printf("%s\n",commands[1] );
	// printf("%s\n",s );
	// printf("%d\n",ffff );
	int i=0;
	while(commands[i])
	{
		// printf("%s\n",commands[i] );
		i++;
	}
	if(i==1)
	{
		char *filename=(char *)malloc(1024*sizeof(char));
		strcpy(filename,"/proc/self/stat");
		FILE *f=fopen(filename, "r");
		if(f!=NULL)
		{
			int pidd;
		// char comm[1024];
			char s[1024];
			char state;
			unsigned int u;
			int d;
			unsigned long lu;
			unsigned long long llu;
			long int ld;
			unsigned long vm;
			fscanf(f, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu", &pidd, s, &state, &d,&d,&d,&d,&d,&u,&lu,&lu,&lu,&lu,&lu,&ld,&ld,&ld,&ld,&ld,&ld,&llu,&vm);// printf("comm = %s\n", comm);
			printf("Pid : %d\n", pidd);
			printf("Process Status : %c\n", state);
			printf("Memory ​: %lu\n", vm);
			char *ex_path=(char *)malloc(1024*sizeof(char));
			if(readlink("/proc/self/exe", ex_path, 63) == -1)
			{
				printf("Error: can't get executable\n");
				return;
			}else
			{
				if(strstr(ex_path,home)!=NULL)
				{
					char *temp=(char *)malloc(1024*sizeof(char));
					int p=0;
					for(int x=strlen(home);x<strlen(ex_path);x++)
					{
						temp[p]=ex_path[x];
						p++;
					}
					strcpy(ex_path,"~");
					strcat(ex_path,temp);
					printf("Executable path : %s\n",ex_path );
				}else
				{
					printf("Executable path : %s\n",ex_path );
				}
			}
		}else
		{
			perror("/proc/self/stat");
			return;
		}
	}else if(i==2)
	{
		int gpid;
		int rt=digits_only(commands[1]);
		if(rt==1)
		{
			sscanf(commands[1],"%d",&gpid);
			// printf("%d\n",gpid );
			char *filename=(char *)malloc(1024*sizeof(char));
			char* tpid = (char*)malloc(sizeof(char)*32);
			strcpy(filename,"/proc/");
			sprintf(tpid,"%d",gpid);
			strcat(filename,tpid);
			strcat(filename,"/stat");
		// printf("%s\n",filename );
			FILE *f=fopen(filename, "r");
			if(f!=NULL)
			{
				int pidd;
		// char comm[1024];
				char s[1024];
				char state;
				unsigned int u;
				int d;
				unsigned long lu;
				unsigned long long llu;
				long int ld;
				unsigned long vm;
				fscanf(f, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu", &pidd, s, &state, &d,&d,&d,&d,&d,&u,&lu,&lu,&lu,&lu,&lu,&ld,&ld,&ld,&ld,&ld,&ld,&llu,&vm);// printf("comm = %s\n", comm);
				printf("Pid : %d\n", pidd);
				printf("Process Status : %c\n", state);
				printf("Memory ​: %lu\n", vm);
				char *ex_path=(char *)malloc(1024*sizeof(char));
				char *ex_name=(char *)malloc(1024*sizeof(char));
				strcpy(ex_name,"/proc/");
				strcat(ex_name,tpid);
				strcat(ex_name,"/exe");
				// printf("%s\n",ex_name );
				if(readlink(ex_name, ex_path, 63) == -1)
				{
					printf("Error: can't get executable\n");
					return;
				}else
				{
					if(strstr(ex_path,home)!=NULL)
					{		
						char *temp=(char *)malloc(1024*sizeof(char));
						int p=0;
						for(int x=strlen(home);x<strlen(ex_path);x++)
						{
							temp[p]=ex_path[x];
							p++;
						}
						strcpy(ex_path,"~");
						strcat(ex_path,temp);
						printf("Executable path : %s\n",ex_path );
					}else
					{
						printf("Executable path : %s\n",ex_path );
					}
				}
			}else
			{
				perror(filename);
				return;
			}
		}else
		{
			printf("Error : Process id should be number\n");
			return;
		}
	}else
	{
		printf("Error : Too many arguments\n");
		return;
	}
}