#include "bash.h"
void exec_echo(char *s)
{
	char *blank=(char *)malloc(1024*sizeof(char));
	strcpy(blank,s);
	int index, i;
	index = 0;
	while(blank[index] == ' ' || blank[index] == '\t' || blank[index] == '\n')
	{
		index++;
	}
	if(index != 0)
	{
		i = 0;
		while(blank[i + index] != '\0')
		{
			blank[i] = blank[i + index];
			i++;
		}
        blank[i] = '\0'; // Make sure that string is NULL terminated
    }
    char *ss=(char *)malloc(1024*sizeof(char));
    strcpy(ss,blank);
    char* token = strtok(blank, " ");
    char *tt=(char *)malloc(1024*sizeof(char));
    strcpy(tt,ss+strlen(token)+1);
    char *tk=(char *)malloc(1024*sizeof(char));
    int p=0;
    for(int x=0;x<strlen(tt);x++)
    {
    	if(tt[x]!='"')
    	{
    		tk[p++]=tt[x];
    	}
    }
    printf("%s\n",tk );
}