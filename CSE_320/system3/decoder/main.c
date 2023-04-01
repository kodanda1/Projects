#include "decoder.h"
#include <stdio.h>
#include<string.h>

  int main(int argc, char *argv[])
  {
    int maxN = 1000;
    int i,j,ix,n;
    char line[maxN],temp[maxN],d[maxN],stack[200][maxN];
    if (argc < 2)
    {
      printf("Usage: decoder file\n");
      return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
      printf("Unable to open input file\n");
      return 1;
    }
    fgets(d,sizeof(d),fp);
    rstrip(d);
    while (fgets(line, sizeof(line), fp)) 
    {
      rstrip(line);

      for(i=0;line[i]!='\0';i++)
      {
        if(line[i]!=d[i])line[i]='x';
        else line[i]=' ';
      }

      for(i=ix,j=0;line[i]!='\0';i++,j++)
      {
        temp[j]=line[i];
      }
      for(i=0;i<ix;i++,j++)
      {
        temp[j]=line[i];
      }
      temp[j]='\0';

      strcpy(stack[ix],temp);
      ix++;
    }

    n=ix;

    for(i=n-1;i>=0;i--)
    {
      printf("%s\n",stack[i]);
    }

    fclose(fp);

    return 0;
    }

