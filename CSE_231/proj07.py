##########################################################################################################################################
# Computer Science Project 07
# This project takes an input file and uses lists and tuples
# This program reads in a census file and displays each state and the number of representatives for the state based on that census file.
##########################################################################################################################################

''' Importing necessary libraries in the code.
1. Math module is used for calculation of square root values.
2. CSV module is used for reading data from .csv files.'''
import math
import csv

def open_file():
    '''The function will ask for the Filename from the user and will return file pointer.
If the doesn't exist then the function will show error and again ask for filename.'''

    while True:
        try:
            a = input("Enter filename: ") #Ask for Filename from the User
            #a = "Scoring_per_Game.csv"
            fp = open(a)
            
            return fp
        except:
            print("Error: file not found. Please try again.") #If file not found

def calc_multipliers():
    ''' The function is used to calculate multipliers and make a list of it.
The multiplier values will be used for further operations.'''
    multipliers = list()
    for i in range(2,61):
        multipliers.append(1/math.sqrt(i*(i-1)))

    multipliers.sort(reverse= True)
    return multipliers
        

def calc_priorities(s,p,m):
    ''' The function is used to calculate the priorituy value based on
the population o state and multiplier.'''
    m.sort(reverse= True)
    priorities = list()
    
    for i in m:
        priorities.append((int(p*i), s))

    return priorities
        
    

def read_file_make_priorities(fp, m = ' '): 
    ''' This function creates two list:
1. A list of lists where each list is a state and a count of representatives.
2. A list of priority tuples (priority, state) sorted in decreasing order of priority'''
    fp.readline()
    reader = csv.reader(fp) #Reader pointer for reading the csv file
    master_list = list() # Creating an empty list to store data

    state_reps = list()
    priorit = list()
    
    for row in reader: # Read Each and Every Row one by one
        if('District of Columbia' in row or 'Puerto Rico' in row):
            continue
        row[1]=str(row[1]).strip().replace('"','')
        master_list.append(row) #Append the row in mater_list
    #print(master_list)

    for i in master_list:
            state_reps.append([i[1],1])
        
    if(m == ' '):
        multipliers = calc_multipliers()
        if(len(state_reps)< 50):
            multipliers = multipliers[:len(state_reps)]
    else:
        multipliers = m
    #print(multipliers,'\n')    
    for i in master_list:
        try:
            s = i[1]
            p = int(i[2])
            m = multipliers
            temp = calc_priorities(s,p,m)
            for j in temp:
                priorit.append(j)
        except:
            pass

    priorit.sort(reverse=True)
    priorit = priorit[:385]
    #print(priorit)        
    state_reps.sort()    
    return state_reps, priorit
        
    
    

def add_to_state(state,states):
    ''' The function is used to find state name and the add 1 to it's
representative count'''
    for i in states:
        if(state in i):
            i[1] += 1

def display(states):
    ''' This function is used at last to display the output in proper order '''
    print("\n{:<15s}{:>4s}".format('State','Representatives'))
    for i in states:
        if('District of Columbia' in i or 'Puerto Rico' in i):
            continue
        print("{:<15s}{:>4d}".format(i[0],i[1]))
    

def main():
    ''' This function calls the above functions, first to calculate multipliers ,
then to open the file and read the data, then calculate the priority list.
Finally to Display the output.'''
    m = calc_multipliers()
    a = open_file()
    stateReps,PriorityList = read_file_make_priorities(a)
##    print(stateReps)
##    print()
##    print(PriorityList)
##    print()
    for i in PriorityList:
        state = i[1]
##        print(state)
        add_to_state(state,stateReps)
##    print(stateReps)
    display(stateReps)
    
    
if __name__ == "__main__":
    main()

########################
#  Project Completed   #
########################
