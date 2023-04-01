#include "decoder.h"
#include <string.h>

/**
 * Decode an encoded string into a character stream.
 * @param encoded The input string we are decoding
 * @param decoded The output string we produce
 * @param maxLen The maximum size for decoded
 */
  void decoder(const char *encoded, char *decoded, int maxLen)
  {
        int i,j,k;
        char temp[maxLen*3];
        char a;
        temp[0]='\0';
        for(i=0; encoded[i]!='\0';i++)
        {
          if(encoded[i]=='%')
          {
            strcat(temp,"000");
          }
          else if(encoded[i]=='^')
          {
            strcat(temp,"001");
          }
          else if(encoded[i]=='!')
          {
            strcat(temp,"010");
          }
          else if(encoded[i]=='B')
          {
            strcat(temp,"011");
          }
          else if(encoded[i]=='G')
          {
            strcat(temp,"100");
          }
          else if(encoded[i]=='c')
          {
            strcat(temp,"101");
          }
          else if(encoded[i]=='p')
          {
            strcat(temp,"110");
          }
          else if(encoded[i]=='M')
          { 
            strcat(temp,"111");
          }
          else if(encoded[i]=='Z')
          {
            strcat(temp,"00");
          }
          else if(encoded[i]=='f')
          {
            strcat(temp,"01");
          }
          else if(encoded[i]=='w')
          {
            strcat(temp,"10");
          } 
          else if(encoded[i]=='g')
          { 
            strcat(temp,"11");
          } 
        }
        for(i=0;i<strlen(temp);i+=8)
        {
          k=128;
          a=0;
          for(j=i;j<i+8 && j<strlen(temp);j++,k=k/2)
          {
            if(temp[j]=='1')
            {
              a+=k;
            }
          }
          decoded[i/8]=a;
          decoded[i/8+1]='\0';
        }

  }


