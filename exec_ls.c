#include "bash.h"
int fit;
int j;
int fa,fl,i,fff;
char *path;
struct stat st;
void exec_ls(char *s)
{
	char *commands[1024]={};
	toknnise(s,commands);
	fa=0;
	fl=0;
	i=1;
	fff=0;
	path=(char *)malloc(1024*sizeof(char));
	while(commands[i]!=NULL)
	{
		char *tpth;
		tpth=(char *)malloc(1024*sizeof(char));
		j=1;		
		if(commands[i][0]!='-')
		{
			fff=1;
			strcpy(tpth,commands[i]);
			int ln=strlen(tpth);
			strcpy(path,tpth);
			if(ln>0)
			{
				if(path[0]=='~')
				{
					char *fp=(char *)malloc(1024*sizeof(char));
					strcpy(fp,home);
					strcat(fp,&path[1]);
					strcpy(path,fp);
				}
			}
		}else
		{
			while(commands[i][j])
			{
				if(commands[i][j]=='a')
				{
					fa=1;
				}
				if(commands[i][j]=='l')
				{
					fl=1;
				}
				j++;
			}			
		}
		i++;
	}
	if(fff==0)
	{
		strcpy(path,cur_dir);
	}
	
	stat(path,&st);
	if(S_ISDIR(st.st_mode)==0)
	{
		printf("ls: cannot access '%s' : No such directory\n",path );
		return;
	}
	DIR *dir=opendir(path);
	struct dirent *dst;
	typedef struct file_data
	{
		char* f_permissions;
		nlink_t f_nhlinks;
		char* f_uown;
		char* f_gown;
		off_t f_size;
		char* f_mtime;
		char* f_name;
	}fdt;
	int it=0,init_siz=256;
	fdt *files=(fdt *)malloc(init_siz*sizeof(fdt));
	if(files==NULL)
	{
		printf("Allocation Error\n");
		exit(1);
	}
	while(dst=readdir(dir))
	{
		files[it++].f_name=dst->d_name;
		if (it >= init_siz)
		{
			init_siz =init_siz*2;
			files = realloc(files, init_siz);
			if (files == NULL)
			{
				printf("Reallocation Error\n");
				exit(1);
			}
		}
	}
	fit=0;
	while(files[fit].f_name)
	{
		struct stat st;
		char *s=(char *)malloc(1024*sizeof(char));
		strcpy(s,path);
		if (s[(int)strlen(s)-1] != '/') strcat(s,"/");
		strcat(s, files[fit].f_name);
		int x=stat(s,&st);
		if(x==-1)
		{
			printf("Error getting file info\n");
			exit(1);
		}
		files[fit].f_permissions=(char *)malloc(11*sizeof(char));
		if (S_ISREG(st.st_mode))
		{
			files[fit].f_permissions[0] = '-';
		}else if (S_ISDIR(st.st_mode))
		{
			files[fit].f_permissions[0] = 'd';
		}else if (S_ISCHR(st.st_mode))
		{ 
			files[fit].f_permissions[0] = 'c';
		}else if (S_ISBLK(st.st_mode))
		{
			files[fit].f_permissions[0] = 'b';
		}else if (S_ISFIFO(st.st_mode))
		{
			files[fit].f_permissions[0] = 'p';
		}else if (S_ISLNK(st.st_mode))
		{
			files[fit].f_permissions[0] = 'l';
		}else 
		{
			files[fit].f_permissions[0] = 's';
		}
		if (st.st_mode & S_IRUSR)
		{
			files[fit].f_permissions[1] = 'r';
		}else 
		{
			files[fit].f_permissions[1] = '-';
		}
		if (st.st_mode & S_IWUSR)
		{
			files[fit].f_permissions[2] = 'w';
		}else 
		{
			files[fit].f_permissions[2] = '-';
		}
		if (st.st_mode & S_IXUSR)
		{
			files[fit].f_permissions[3] = 'x';
		}else 
		{
			files[fit].f_permissions[3] = '-';
		}
		if (st.st_mode & S_IRGRP) 
		{
			files[fit].f_permissions[4] = 'r';
		}else 
		{
			files[fit].f_permissions[4] = '-';
		}
		if (st.st_mode & S_IWGRP) 
		{
			files[fit].f_permissions[5] = 'w';
		}else
		{
			files[fit].f_permissions[5] = '-';
		}
		if (st.st_mode & S_IXGRP) 
		{
			files[fit].f_permissions[6] = 'x';
		}else 
		{
			files[fit].f_permissions[6] = '-';
		}
		if (st.st_mode & S_IROTH) 
		{
			files[fit].f_permissions[7] = 'r';
		}else 
		{
			files[fit].f_permissions[7] = '-';
		}
		if (st.st_mode & S_IWOTH) 
		{
			files[fit].f_permissions[8] = 'w';
		}else 
		{
			files[fit].f_permissions[8] = '-';
		}
		if (st.st_mode & S_IXOTH) 
		{	
			files[fit].f_permissions[9] = 'x';
		}else 
		{
			files[fit].f_permissions[9] = '-';
		}
		files[fit].f_uown = getpwuid(st.st_uid)->pw_name;
		files[fit].f_permissions[10] = '\0';
		files[fit].f_nhlinks = st.st_nlink;
		files[fit].f_gown = getgrgid(st.st_gid)->gr_name;
		files[fit].f_size = st.st_size;
		files[fit].f_mtime = (char*)malloc(sizeof(char)*100);
		strftime(files[fit++].f_mtime, 100, "%b %d %H:%M", localtime(&st.st_mtime));
	}	
	it = 0;
	while (files[it].f_name)
	{
		if (!fa && files[it].f_name[0] == '.')
		{
			it++;
			continue;
		}
		if (fl) printf("%s\t%d\t%s\t%s\t%d\t%s\t%s\n", files[it].f_permissions, (int)files[it].f_nhlinks, files[it].f_uown, files[it].f_gown, (int)files[it].f_size, files[it].f_mtime, files[it].f_name);
		else printf("%s\n", files[it].f_name);
		it++;
	}
}