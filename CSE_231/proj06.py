#####################################################################################
#Computer Science Project 06
#This python code extracts and displays statistics from a data file.
#All the data would be read into list of lists and then extract the data of interest.
#####################################################################################

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

def read_file(fp):
    '''This function will read the csv file from file pointer and return the csv file in list of list format'''


    reader = csv.reader(fp) #Reader pointer for reading the csv file
    next(reader,None)
    master_list = list() # Creating an empty list to store data
    
    for row in reader: # Read Each and Every Row one by one
        master_list. append(row) #Append the row in master_list
        
    return master_list # Return the final master_list

def shoots_left_right(master_list):
    '''This function will count and return number of left shooter and right shooters using 2 integers'''
    
    lshoot = 0 # Variables to hold count value for left shooters
    rshoot = 0 # Variables to hold count value for right shooters

    ind = 1 #Find index number of "S/C"
    
    for i in range(0,len(master_list)): #Run a for loop for number of data row times
        
        if('L' in master_list[i][ind]): #if found 'L' then increment left shooter count
            lshoot += 1 
        elif('R' in master_list[i][ind]):#if found 'R' then increment right shooter count
            rshoot += 1
            
    return lshoot,rshoot #return both values


def position(master_list):
    '''This function accepts as input the master list and returns four integers
representing the count of players who play positions left-wing (“L”),
right-wing (“R”), center (“C”), and defense (“D”)'''
    
    lwing = 0 # Variables to hold count value for left-wing players
    rwing = 0 # Variables to hold count value for right-wing players
    cwing = 0 # Variables to hold count value for center players
    dwing = 0 # Variables to hold count value for defence players
    
    ind1 = 2 #Find index number of "Pos"
    
    for i in range(0,len(master_list)): #if found 'L' then increment left-wing player count
        if('L' in master_list[i][ind1]):
            lwing += 1
        elif('R' in master_list[i][ind1]):#if found 'R' then increment right-wing player count
            rwing += 1
        elif('C' in master_list[i][ind1]):#if found 'C' then increment center player count
            cwing += 1
        elif('D' in master_list[i][ind1]):#if found 'D' then increment defense player count
            dwing += 1
            
    return lwing,rwing,cwing,dwing #return all 4 integer values

def off_side_shooter(master_list):
    '''This function accepts as input the master list and returns two integers
representing the count of players who play the left-wing position (“L”) but
shoot right (“R”) and those who play the right-wing position (“R”) but shoot left (“L”)'''

    lwingr = 0
    rwingl = 0

    ind = 1 # Shoot Direction
    ind1 = 2 # Lwing Rwing
    
    for i in range(0,len(master_list)):
        if('L' in master_list[i][ind1] and 'R' in master_list[i][ind]):
            lwingr += 1
        elif('R' in master_list[i][ind1] and 'L' in master_list[i][ind]):
            rwingl += 1
        
            
    return lwingr,rwingl

def points_per_game(master_list):
    '''This function accepts as input the master list and returns
a sorted list of tuples.'''

#    ls = list()
#    for i in range(1,len(master_list)):
#        tup = (float(master_list[i][18]),master_list[i][0],master_list[i][2])
#        ls.append(tup)
#
#
    #List Comprehension for same above function
    ls = [(float(master_list[i][18]),master_list[i][0],master_list[i][2]) \
          for i in range(0,len(master_list))]
    ls.sort(reverse=True)
    return(ls[0:10])
    

def games_played(master_list):
    '''This function accepts as input the master list and returns a sorted list of tuples'''
    
    ls = [(int(master_list[i][3].replace(',','')),master_list[i][0]) \
          for i in range(0,len(master_list))]
    ls.sort(reverse=True)
    return(ls[0:10])

def shots_taken(master_list):
    '''This function accepts as input the master list and returns a sorted list of tuples'''
    
    ls = [  (int(master_list[i][9].replace(',','')),master_list[i][0]) \
            for i in range(0,len(master_list)) if (master_list[i][9] != "--")]
    ls.sort(reverse=True)
    return(ls[0:10])

def main():
    '''his function calls the above functions, first to open the file and read the data,
and then to display the values. Data will be displayed in the order of the functions above.'''

    fp = open_file()
    master_list = read_file(fp)

   
    lshoot, rshoot = shoots_left_right(master_list)
    print("\n{:>9}".format("Shooting"))
    print("{:<9}{}\n{:<9}{}".format("left:",lshoot,"right:",rshoot))
    
    lwing,rwing,cwing,dwing = position(master_list)
    print("\n  Position")
    print("{:<10}{:>3}\n{:<10}{:>3}\n{:<10}{:>3}\n{:<10}{:>3}"\
          .format("left:",lwing,"right:",rwing,"center:",cwing,"defense:",dwing))
    
    lwingr,rwingl = off_side_shooter(master_list)
    print("\n    Off-side Shooter")
    print("{:<25}{:>5}\n{:<25}{:>5}"\
          .format("left-wing shooting right:",lwingr,"right-wing shooting left:",rwingl))
    #print(lwingr,rwingl)

    
    ppg = points_per_game(master_list)
    print("\n      Top Ten Points-Per-Game")
    print("{:<20}{:>8}{:>16}".format("Player","Position","Points Per Game"))
    for i in ppg:
        print("{:<20}{:>8}{:>16.2f}".format(i[1],i[2],i[0]))

    gp = games_played(master_list)
    print('\n        Top Ten Games-Played')
    print("{:<24}{:>12}".format("Player","Games Played"))
    for i in gp:
       
        print("{:<24}{:>12,d}".format(i[1],i[0]))

    st = shots_taken(master_list)
    print("\n        Top Ten Shots-Taken")
    print("{:<25}{:>11}".format("Player","Shots Taken"))
    for i in st:
        print("{:<25}{:>11,d}".format(i[1],i[0]))
    
    

    

if __name__ == "__main__":
    main()
    
                            #####################
                            # PROJECT COMPLETED #
                            #####################
