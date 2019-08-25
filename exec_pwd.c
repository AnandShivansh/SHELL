#include "bash.h"
void exec_pwd()
{
	char *tk=(char *)malloc(1024*sizeof(char));
	getcwd(tk,1024);
	printf("%s\n",tk );
}