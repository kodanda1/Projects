#include <stdlib.h>
#include <string.h>
#include "binarymath.h"



/**
 * Increment a BINARY_SIZE binary number expressed as a 
 * character string.
 * @param number The number we are passed
 * @returns Incremented version of the number
 */
char * inc(const char *a){
    int i,n=BINARY_SIZE;
    char *b=calloc((n+1),sizeof(char));
    for(i=0; i<n; i++)
    {
      b[i]=a[i];
    }

    for(i=n-1;i>=0;i--)
    {
      if(b[i]=='1')b[i]='0';
      else
      { 
        b[i]='1';
        break;
      }
    }
    b[n]='\0';
    return b;
}


/**
 * Negate a BINARY_SIZE binary number expressed as a character string
 * @param number The number we are passed
 * @returns Incremented version of the number
 */
char * negate(const char *a){
    int i,n=BINARY_SIZE;
    char *b=calloc((n+1),sizeof(char));
    for(i=0; i<n; i++){
      if(a[i]== '0')b[i]= '1';
      else if(b[i] = '0')b[i] = '0';
    }
    b[n]='\0';
    char *c = inc(b);
    free(b);
    return c;

}


/**
 * Add two BINARY_SIZE binary numbers expressed as
 * a character string. 
 * @param a First number to add
 * @param b Second number to add
 * @return a + b
 */
char *add(const char *a, const char *b)
{
  int i,n=BINARY_SIZE;
  char *c=calloc((n+1),sizeof(char));
  int flag=0;
  int val;
  for(i=n-1; i>=0; i--)
  {
    val=0;
    if(flag)val++;
    if(a[i]=='1')val++;
    if(b[i]=='1')val++;
    c[i]=(val%2)? '1':'0';
    flag=val/2;
  }
  c[n]='\0';
  return c;
}

/**
 * Subtract two BINARY_SIZE binary numbers expressed as
 * a character string.
 * @param a First number
 * @param b Second number 
 * @return a - b
 */
char *sub(const char *a, const char *b)
{
  int i,n=BINARY_SIZE;
  char *c=calloc((n+1),sizeof(char));
  int flag=0;
  int val;
  for(i=n-1; i>=0; i--)
  {
    val=0;
    if(flag)val--;
    if(a[i]=='1')val++;
    if(b[i]=='1')val--;
    c[i]=(val%2)? '1':'0';
    flag=(val<0);
  }
  c[n]='\0';
  return c;
}

