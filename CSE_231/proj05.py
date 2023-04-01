#####################################################################################################
# This is computer science project - 05
# This project finds the minimum and maximum of a given data and displays the necessary information. 
#####################################################################################################

#First Function
"""
It just opens file
"""
def open_file():
    while True:
        try:
            f_name = input("Input a file name: ") #Ask for File name
            fp = open(f_name,'r') #Try opening the file in read mode
            
            return fp #Return file Pointer if file opened Successfully
        
        except:
            print("Error: file not found. Please try again.") #If file not found

#Second Function
"""
The value for the overall United States MMR coverage is in the line with the label “United States.
returns the float value of MMR  coverage.
"""
def get_us_value(fp):
    fp.seek(0) #Make the File pointer at starting of file
    fp.readline() 
    fp.readline() #To Readline for skipping Heading of file
    data = fp.read() # Read all the data of the file
    data  = data.split('\n') #Split all the data of file from New lines
    del data[-1] # Delete last value(is just a blank value)
    
    for i in data:
        if('United States' in i): #Check if United States in i
            value = i[-4:] #Read last 4 characters (Is a float value as per Project PDF)
            return float(value) #Return Float value

#Third Function
"""
This function returns the minimum value in the file and the associated state.
"""
def get_min_value_and_state(fp):
    fp.seek(0)
    fp.readline()
    fp.readline()
    data = fp.read()
    data  = data.split('\n')
    del data[-1]
    
    min_value = 100 # initial value
    min_state = ''

    #print(data)
    
    for i in data:
        if 'NA' in i[-2:]:
            continue
        value = i[-4:]
        #print(value)
        value = float(value)
        if (value < min_value):
            min_value = value
            min_state = i[:15]
            min_state = min_state.strip() #Removing unwanted white spaces

    return  min_state, min_value

#Fourth Function
"""
This function returns the maximum value in the file and the associated state.
"""

def get_max_value_and_state(fp):
    fp.seek(0)
    fp.readline()
    fp.readline()
    data = fp.read()
    data  = data.split('\n')
    del data[-1]
    max_value = 0
    max_state = ''

    #print(data)
    
    for i in data:
        if 'NA' in i[-2:]:
            continue
        value = i[-4:]
        #print(value)
        value = float(value)
        if (value > max_value):
            max_value = value
            max_state = i[:15]
            max_state = max_state.strip() #Removing unwanted white spaces

    return max_state, max_value

#Fifth Function
"""
This function displays all the states whose coverage is less than 90%, the minimal value needed for measles herd immunity.
"""
def display_herd_immunity(fp):
    print("\nStates with insufficient Measles herd immunity.")
    fp.seek(0)
    fp.readline()
    fp.readline()
    data = fp.read()
    data  = data.split('\n')
    del data[-1]

    print("{:<25s}{:>5s}".format("State","Percent"))
    for i in data:
        if 'NA' in i[-2:]:
            continue
        value = i[-4:]
        #print(value)
        value = float(value)
        if (value < 90):
            state = i[:15]
            state = state.strip() #Removing unwanted white spaces
            print("{:<25s}{:>5.1f}%".format(state,value))
    print()

#Sixth Function
"""
This function writes into a file named herd.txt all the states whose coverage is less than 90%, the minimal value needed for measles herd immunity.
"""                             
def write_herd_immunity(fp):
    
    fp.seek(0)
    fp.readline()
    fp.readline()
    data = fp.read()
    data  = data.split('\n')
    del data[-1]

    herd = open("herd.txt",'w')
    herd.write("\nStates with insufficient Measles herd immunity.\n")
    herd.write("{:<25s}{:>5s}".format("State","Percent\n"))
    for i in data:
        if 'NA' in i[-2:]:
            continue
        value = i[-4:]
        #print(value)
        value = float(value)
        if (value < 90):
            state = i[:15]
            state = state.strip() #Removing unwanted white spaces
            herd.write("{:<25s}{:>5.1f}%\n".format(state,value))

    herd.close()

#Main Function
"""
This function prints the values and displays them.
"""
def main():

    #get file pointer from open_file function
    fp = open_file()
    print() # Print a blank line
    print(fp.readline()) #Print first line of file

    #Get US MMR coverage value from 'get_us_value' Function
    us_mmr = get_us_value(fp)
    print("Overall US MMR coverage: {}%".format(us_mmr))

    #Get state name and MMR coverage % from 'get_min_value_and_state' function
    min_st,min_val = get_min_value_and_state(fp)
    print("State with minimal MMR coverage: {} {}%".format(min_st,min_val))

     #Get state name and MMR coverage % from 'get_max_value_and_state' function
    max_st,max_val = get_max_value_and_state(fp)
    print("State with maximum MMR coverage: {} {}%".format(max_st,max_val))

    #Display herd immunity (states with MMR coverage < 90%) using 'display_herd_immunity' function
    display_herd_immunity(fp)
    
     #Write herd immunity (states with MMR coverage < 90%) to herd.txt using 'write_herd_immunity' function
    write_herd_immunity(fp)


if __name__ == "__main__":
    main()

                                                                            ###############################
                                                                            #     Project completed       #
                                                                            ###############################
