#include "decoder.h"
#include <stdio.h>
#include<string.h>
int maxN=1000;
void rstrip(char *s)
{
  int n=strlen(s);
  int i;
  for(i=n-1;(s[i]=='\n' || s[i]==' ')&& i>=0;i--)
  {
    s[i]='\0';
  }

}

