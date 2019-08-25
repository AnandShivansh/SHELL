#include "bash.h"
char *trimm(char *s)
{
	char *blank;
	blank=(char *)malloc(1024*sizeof(char));
	int c = 0, d = 0;
	while (s[c] != '\0')
	{
		if (!(s[c] == ' ' && s[c+1] == ' ')) {
			blank[d] = s[c];
			d++;
		}
		c++;
	}
	blank[d] = '\0';
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
    return blank;

}