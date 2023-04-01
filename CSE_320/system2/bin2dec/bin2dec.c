#include "bin2dec.h"

/**
 * Convert a binary representation of a 
 * number to an unsigned integer. 
 * 
 * For this function, the values Y and N represent 
 * true (1) and false (0) respectfully. So, the string:
 * 
 * YYNY is equal to 1101 binary, which is equal to 13.
 *
 * Unexpected characters are ignored. Only Y's and N's are
 * considered to be valid. Stop converting when you get
 * to a space character or the end of the string. The 
 * representation is case-sensitive (only Y/N are valid 
 * true and false values).
 *
 * 'aYNcY YY' should convert to 5
 * 'NYNYny' should convert to 5
 *
 * @param binary Binary number as a string of 'Y's and 'N's
 * and other characters.
 * @returns unsigned int result
 */
unsigned int bin2dec(const char *binary)
{
      unsigned int value =0;
        for(;*binary; binary++)
        {
          if(*binary == 'Y')
          {
            value = value*2+1;
          }
          else if(*binary == 'N')
          {
            value = value*2;
          }
          
        }
        return value;
}
