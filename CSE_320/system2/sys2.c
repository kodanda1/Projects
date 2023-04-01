/**
 *   * My first C program
 *     * @author Varuntej Kodandapuram
 */

#include <stdio.h>
int factorial(int n);
double square(double x);
/**
  *   * Main entry point
  */
int main() 
{
    printf("The factorial of 4 is %d\n", factorial(4));
    printf("The square of 22 is %f\n", square(22));
    return 0;
}
/**
  * Compute the factorial of a number
  */
int factorial(int n)
{
    int f = 1;
    int i;
    for(i=1; i<=n; i++)
    {
      f *= i;
    }
    return f;
}
/**
  * Compute the square of a number
  */
double square(double x)
{
    return x * x;
}

