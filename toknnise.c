#include "bash.h"
void toknnise(char *s,char *a[1024])
{
	int i=0;
	char *tkn=strtok(s," ");
	while(tkn!=NULL)
	{
		a[i++]=tkn;
		tkn=strtok(NULL," ");
	}
}