// #ifndef BASH_H
// 	#define SHELL_H
		#include<stdio.h> 
		#include<string.h> 
		#include<stdlib.h> 
		#include<unistd.h> 
		#include<sys/types.h> 
		#include<sys/wait.h> 
		#include <dirent.h>
		#include <time.h>
		#include <pwd.h>
		#include <sys/stat.h>
		#include <grp.h> 
		#include <fcntl.h>
		#include <ctype.h>
		extern char *home;
		extern char *cur_dir;
		extern char *username;
		extern char *sysname;
		extern char *buf;
		extern char semic[100][1024];
		extern int lsc;
		extern int countbg;
		extern int pidstore[100];
		extern int flp[100];
		extern char namestore[100][1024];
		extern int cnt;
		extern int piddd;
		void init_shell();
		char *trimm(char *s);
		int input_process();
		void exec_pwd();
		void exec_echo(char *s);
		void exec_cd(char *s);
		void toknnise(char *s,char *a[1024]);
		void ecec_fg(char *s);
		void exec_ls(char *s);
		int digits_only(char *s);
		void exec_pinfo(char *s);
		void checkfunc(char *s);
		// void exec_bg(char *s,in);
// #endif