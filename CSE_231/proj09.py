##################################################################################################################
# Computer Science Project - 09
# This project analyzes data regarding the recent COVID-19 outbreak.
# This program gives a more detailed insight into lists, dictionaries and various data structures.
# It reads the information in the given file and projects it to the user in a simpler way.
##################################################################################################################

import csv
import matplotlib.pyplot as plt
plt.style.use("ggplot")
from operator import itemgetter


def open_file():
    '''The function will ask for the Filename from the user and will return file pointer.
If the input is blank then it will by default return file pointer for 'ncov.csv'
If the doesn't exist then the function will show error and again ask for filename.'''

    while True:
        try:
            a = input("Data file: ") #Ask for Filename from the User
            if(len(a)<1):
                a = 'ncov.csv'
            fp = open(a,encoding='utf-8')
            
            
            return fp
        except:
            print("Error. Try again.") #If file not found


def build_dictionary(fp):
    '''
        This function accepts the previously generated file pointer as input and returns the required
dictionary. The dictionary contains a list of dictionaries. Each dictionary within the list has the key as the
area within the country and value as a tuple. This tuple contains last updated date, numbers of
cases, number of deaths, and number of recovered respectively.
    '''

    D_temp  = dict()
    D_OP    = dict()
    
    reader = csv.reader(fp, dialect='excel') #Reader pointer for reading the csv file
    master_list = list() # Creating an empty list to store data

    for line in reader:
        try:
            country     = line[2].strip()
            area        = line[1].strip()
            if(len(area)<2):
                area = 'N/A'
            last_update = line[3].strip()
            cases       = int(line[4])
            deaths      = int(line[5])
            recovered   = int(line[6])
        except:
            continue

        D_temp = {area : (last_update,cases, deaths,recovered)}
        
        try:
             a = D_OP[country]
             a.append(D_temp)
             D_OP[country] = a
        except :
            D_OP[country] = list()
            a =  D_OP[country]
            a.append(D_temp)
            D_OP[country] = a

        D_temp = dict()
        
    return D_OP

    for i in sorted(D_OP.keys()):
        print(i,':',D_OP[i])
        
    

def top_affected_by_spread(master_dict):
    '''
        This function accepts the data dictionary as created by the function above and returns a sorted
list (in descending order) of the top 10 countries with the most areas affected by nCoV. The
returned list will contain 10 tuples, each tuple containing the country name and total areas
affected in that country.
    '''
    list_top_area = list()
    for i in sorted(master_dict.keys()):
        list_top_area.append((i,len(master_dict[i])))
        #print(i,':',len(master_dict[i]))

    
    list_top_area.sort(key = itemgetter(0))
    list_top_area.sort(key = itemgetter(1), reverse = True)

    return list_top_area[:10]
    #print(list_top_area[:10])


def top_affected_by_numbers(master_dict):
    '''
        This function accepts the data dictionary and produces a sorted list of the top 10 countries with
the most total people affected within every country. This is similar to the previous function,
except that instead of counting the total areas affected, we are counting the total people affected
in each country.
    '''

    list_top_cases = list()
    
    for i in sorted(master_dict.keys()):
        count = 0
        for j in master_dict[i]:
            temp = list(j.values())
            for k in temp:
                #print(k[1])
                count += k[1]
        list_top_cases.append((i,count))
        

    
    list_top_cases.sort(key = itemgetter(0))
    list_top_cases.sort(key = itemgetter(1), reverse = True)

    return list_top_cases[:10]
    print(list_top_cases[:10])
    
    

def is_affected(master_dict, country):
    '''
        This function takes in the data dictionary and the name of a country (string) and returns a
Boolean (True or False) depending on whether a country is affected by nCoV.
    '''
    
    list_country = list()
    for i in sorted(master_dict.keys()):
        list_country.append(i.strip().lower())
        
        

    
    list_country.sort()
    if(country.lower() in list_country):
        return True
    return False


def plot_by_numbers(list_of_countries, list_of_numbers):
    '''
        This function plots the number of areas/people inffected by country.
        
        parameters: 
            list_of_countries: list of countries
            list_of_numbers: list of the number of areas/people inffected
            
        Returns: None
    '''
    fig, ax = plt.subplots()
    
    x_pos = [i for i, _ in enumerate(list_of_countries)]
    
    ax.barh(x_pos, list_of_numbers, align='center', color='red')
    ax.set_yticks(x_pos)
    ax.set_yticklabels(list_of_countries)
    ax.invert_yaxis()
    ax.set_xlabel('Count')
    ax.set_title('Novel Coronavirus statistics')
    
    plt.show()


def affected_states_in_country(master_dict, country):

    '''
        This function takes in the data dictionary and the name of a country (string) and returns a set
of affected areas within a country.
    '''
    
    list_states = list()
    for i in sorted(master_dict.keys()):
        count = 0
        if(country.strip().lower() == i.strip().lower()):
            for j in master_dict[i]:
                temp = list(j.keys())
                #print(temp)
                if(temp != 'n/a'):
                    list_states.append(temp[0])
        

    
    list_states.sort()

    return set(list_states)
    #print(list_states)


def main():
    BANNER = '''
.__   __.   ______   ______   ____    ____
|  \ |  |  /      | /  __  \  \   \  /   /
|   \|  | |  ,----'|  |  |  |  \   \/   / 
|  . `  | |  |     |  |  |  |   \      /  
|  |\   | |  `----.|  `--'  |    \    /   
|__| \__|  \______| \______/      \__/  
    '''
    print(BANNER)
    MENU = ''' 
[1] Countries with most areas infected
[2] Countries with most people affected
[3] Affected areas in a country
[4] Check if a country is affected
[5] Exit

Choice: '''

    fp = open_file()
    master_dict = build_dictionary(fp)
    while True:
        try:
            inp = int(input(MENU))

            if(inp == 1):
                area_num = top_affected_by_spread(master_dict)

                l_country = list()
                l_areas = list()
                print("{:<20s} {:15s}".format("Country", "Areas affected"))
                print("-"*40)
                for i in area_num:
                    #print(i)
                    print("{:<20s} {:5d}".format(i[0],i[1]))
                    l_country.append(i[0])
                    l_areas.append(i[1])
                p = input('Plot? (y/n) ')
                if(p.lower() == 'y'):
                    plot_by_numbers(l_country[:5], l_areas[:5])

            elif(inp == 2):
                cases_num = top_affected_by_numbers(master_dict)

                l_country = list()
                l_people = list()
                
                print("{:<20s} {:15s}".format("Country", "People affected"))
                print("-"*40)
                for i in cases_num:
                    print("{:<20s} {:5d}".format(i[0],i[1]))
                    l_country.append(i[0])
                    l_people.append(i[1])
                    
                p = input('Plot? (y/n) ')
                if(p.lower() == 'y'):
                    plot_by_numbers(l_country[:5], l_people[:5])
                    

            elif(inp == 3):
                country = input("Country name: ")
                aff_states = affected_states_in_country(master_dict, country)
                print("-"*30)
                
                list_aff_states = list(aff_states)
                if(len(list_aff_states) > 0):
                    list_aff_states.sort()
                    print("{:<30s}".format("Affected area"))
                    print("-"*30)
                    count = 1
                    for i in list_aff_states:
                        print("[{:02d}] {:<30s}".format(count,i))
                        count += 1
                else:
                    print("Error. Country not found.")

            elif(inp == 4):
                country = input("Country name: ")
                a = is_affected(master_dict, country)
                print("-"*30)
                if(a == True):
                    print("{} is affected.".format(country))
                else:
                    print("{} is not affected.".format(country))
                

            elif(inp == 5):
                break

            else:
                print("Error. Try again.")
                    
                    
                
            
        except Exception as e:
            #print(e)
            print("Error. Try again.")

    
    print("Stay at home. Protect your community against COVID-19")
    
    

    
if __name__ == "__main__":
    
    main()

#    fp = open_file()
#    master_dict = build_dictionary(fp)
#    area_num = top_affected_by_spread(master_dict)
#    cases_num = top_affected_by_numbers(master_dict)
#    aff_states = affected_states_in_country(master_dict, 'US')
#    a = is_affected(master_dict, 'Usss')

#############################
#     Project Completed     #
#############################
