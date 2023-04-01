#include <stdio.h>

long first(long);
long second(long, long);
long min(long, long);
long bit_counter(long);
int main() 
{
    long value = 27;
    long result = first(value);
    printf("first(%ld) = %ld\n", value, result);
    result = second(12, 22);
    printf("second(12, 22) = %ld\n", result);
    result = min(73, 12);
    printf("min(73, 12) = %ld\n", result);
    result = bit_counter(753);
    printf("bit_counter(753) = %ld\n", result);
            
    return 0;

}


