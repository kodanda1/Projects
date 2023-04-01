######################################################################################

# Computer Science Project 04
#This project calculates and approximates values of selected mathematical functions.

######################################################################################
import math


EPSILON = 1.0e-7
# function to calculate sum of squares
def sum_natural_squares(n):
    try:
        n = int(n)
        if n != 0:
            return (n * (n + 1) * (2 * n + 1)) // 6
        else:
            return None
    except:
        return None
   

# actual function to calculate pi
def approximate_pi():
    k=1
    n=0
    approximate =0.0
    while abs(k)>EPSILON:
       k=(((-1)**n)/((2*n)+1))
       approximate +=k
       n +=1
    
    return round(4*(approximate-k), 10)

#assining to variable for easy access of function to calculate factorial for sin and cos
factorial  = math.factorial


# function to calculate sin 
def approximate_sin(x):
    try:
        x = float(x)
        k=1.0
        n=0
        approximate = 0.0
        while abs(k)>EPSILON:
            approximate += k
            k=(((-1)**n)*(x**(2*n+1)))/math.factorial(2*n+1)
            n += 1
        return round(approximate-1,10)
    except:
        return None

# function to calculate cos 
def approximate_cos (x):
    try:
        x = float(x)
    
        k=1.0
        n=1
        approximate = 0.0
        while abs(k)>EPSILON: 
            approximate += k
            k=(((-1)**n)*(x**(2*n)))/math.factorial(2*n)
            n += 1
        return round(approximate,10)
    except:
        return None

# function to print options
def option():
    print('''Please choose one of the options below:\n                A. Display the sum of squares of the first N natural numbers.\n                B. Display the approximate value of Pi.\n                C. Display the approximate value of the sine of X.\n                D. Display the approximate value of the cosine of X.\n                M. Display the menu of options.\n                X. Exit from the program.''')
# main execution function 
def main():
    
    # asking user choice 
    choice = input("Enter option: ").lower()
    # below checking the user choices and performing respective choices 
    if choice == "x":
        print("Hope to see you again.")
        return
    elif choice == "a":
        n = input("Enter N: ")
        if n.isdigit() and int(n)>0:
            print("The sum: ",sum_natural_squares(n))
            main()
        else:
            print(f"Error: N was not a valid natural number. [{n}]")
            main()
    elif choice == "b":
        a = approximate_pi()
        m = math.pi
        print(f"Approximation: {a:.10f}")
        print(f"Math module: {m:.10f}")
        print(f"difference: {abs(m-a):.10f}")
        main()
    elif choice == "c":
        x = input("Enter X: ")
        if x.isalpha():
            print(f"Error: X was not a valid float. [{x}]")
            main()
        else:
            x = float(x)
            a = approximate_sin(x)
            m = math.sin(x)
            print(f"Approximation: {a:.10f}")
            print(f"Math module: {m:.10f}")
            print(f"difference: {math.fabs(m-a):.10f}")
            main()
    elif choice == "d":
        x = input("Enter X: ")
        if x.isalpha():
            print(f"Error: X was not a valid float. [{x}]")
            main()
        else:
            x = float(x)
            a = approximate_cos(x)
            m = math.cos(x)
            print(f"Approximation: {a:.10f}")
            print(f"Math module:  {m:.10f}")
            print(f"difference:  {math.fabs(m-a):.10f}")
            main()
    elif choice == "m":
        option()
        main()
    elif choice not in ["m", "x", "a", "b", "c", "d"]:
        choice = choice.upper()
        print(f"Error:  unrecognized option [{choice}]")
        option()
        main()

    



if __name__ == "__main__":
    option()
    main()
                                                   ###################
                                                   #PROJECT COMPLETED#
                                                   ###################



