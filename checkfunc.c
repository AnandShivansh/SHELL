 #include "bash.h"
void checkfunc(char *s)
{
		char *tsc=(char *)malloc(1024*sizeof(char));
		strcpy(tsc,s);
		// char *tsb=(char *)malloc(1024*sizeof(char));
		// strcpy(tsb,semic[x]);
		// int bgf=0;
		// if(strstr(tsb,"&")!=NULL)
		// {
		// 	bgf=1;
		// }
		// // printf("%d\n",bgf );
		char *ts=(char *)malloc(1024*sizeof(char));
		strcpy(ts,s);
		char *tp=(char *)malloc(1024*sizeof(char));
		strcpy(tp,s);
		ts=trimm(ts);
		tsc=trimm(tsc);
		char *tk=strtok(tp," ");
		// printf("%s\n",tk );
		// if(bgf==0)
		// {
			if(strcmp(tk,"cd")==0)
			{
				exec_cd(ts);
			}else if(strcmp(tk,"pwd")==0)
			{
				exec_pwd();
			}else if(strcmp(tk,"echo")==0)
			{
				exec_echo(s);
			}else if(strcmp(tk,"ls")==0)
			{
				exec_ls(ts);
			}else if(strcmp(tk,"pinfo")==0)
			{
				exec_pinfo(ts);
			}else
			{
				ecec_fg(ts);
			}
		// }else
		// {
			// char *bpp=(char *)malloc(1024*sizeof(char));
			// bpp=strtok(tsc,"&");
			// bpp=trimm(bpp);

			// exec_bg(tsc,ct);
		// }
	// init_shell();
}