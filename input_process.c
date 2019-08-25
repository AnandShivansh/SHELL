#include "bash.h"
int input_process()
{
	int i,j,ctr;
	j=0; ctr=0;
	for(i=0;i<=(strlen(buf));i++)
	{
		if(buf[i]==';'||buf[i]=='\0')
		{
			semic[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
        	semic[ctr][j]=buf[i];
        	j++;
        }
    }
    return ctr;
}