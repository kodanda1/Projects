##################################################################################################################################
# Computer Science Project- 08
# This project prints video game sales data for various platforms across the years.
# The program displays the results of the data as per the requirement of the the user by providing the user with possible options.
##################################################################################################################################

''' Importing necessary libraries in the code.
1. CSV module is used for reading data from .csv files.

'''

import csv
import pylab
from operator import itemgetter

def open_file():
    '''The function will ask for the Filename from the user and will return file pointer.
If the doesn't exist then the function will show error and again ask for filename.'''

    while True:
        try:
            a = input("\nEnter filename: ") #Ask for Filename from the User
            #a = 'video_game_sales_small.csv'
            fp = open(a,encoding='utf-8')
            
            
            return fp
        except:
            print("File not found! Please try again!") #If file not found


def read_file(fp):
    '''
        The function takes file pointer as input and then makes 3 Dictionaries ad per the guidelines.
        All the three Dictionaries are then returned which are used further throughout the program.
    '''
    
    #fp.readline()
    reader = csv.reader(fp, dialect='excel') #Reader pointer for reading the csv file
    master_list = list() # Creating an empty list to store data

    D1 = dict()
    D2 = dict()
    D3 = dict()

    for line in reader:
        try:
            name = line[0].lower().strip()
            platform = line[1].lower().strip()
            year = int(line[2].lower().strip())
            genre = line[3].lower().strip()
            publisher = line[4].lower().strip()
            na_sales = float(line[5].lower().strip())*1000000
            eur_sales = float(line[6].lower().strip())*1000000
            jpn_sales = float(line[7].lower().strip())*1000000
            other_sales = float(line[8].lower().strip())*1000000
        except:
            continue

        global_sales = na_sales+eur_sales+jpn_sales+other_sales

        try:
             a = D1[name]
             a.append((name, platform, year, genre, publisher,global_sales))
             D1[name] = a
        except :
            D1[name] = list()
            a =  D1[name]
            a.append((name, platform, year, genre, publisher,global_sales))
            D1[name] = a
            
        try:
             a = D2[genre]
             a.append((genre, year, na_sales, eur_sales,jpn_sales, other_sales, global_sales))
             D2[genre] = a
        except :
            D2[genre] = list()
            a =  D2[genre]
            a.append((genre, year, na_sales, eur_sales,jpn_sales, other_sales, global_sales))
            D2[genre] = a
            

        try:
             a = D3[publisher]
             a.append((publisher, name, year, na_sales,eur_sales, jpn_sales, other_sales, global_sales))
             D3[publisher] = a
        except :
            D3[publisher] = list()
            a =  D3[publisher]
            a.append((publisher, name, year, na_sales,eur_sales, jpn_sales, other_sales, global_sales))
            D3[publisher] = a
            

    D1_sorted = dict()
    D2_sorted = dict()
    D3_sorted = dict()
    
    for key in sorted(D1.keys()):
        D1_sorted[key] = D1[key]
        
    for key in sorted(D2.keys()):
        D2_sorted[key] = D2[key]
        
    for key in sorted(D3.keys()):
        D3_sorted[key] = D3[key]

    for key in sorted(D1_sorted.keys()):
        a = D1_sorted[key]
        a.sort(key = lambda x: x[-1],reverse = True)
        D1_sorted[key] = a

    for key in sorted(D2_sorted.keys()):
        a = D2_sorted[key]
        a.sort(key = lambda x: x[-1], reverse = True)
        D2_sorted[key] = a

    for key in sorted(D3_sorted.keys()):
        a = D3_sorted[key]
        a.sort(key = lambda x: x[-1], reverse = True)
        D3_sorted[key] = a

    

#    print(D1_sorted)
#    print("#"*50)
#    print(D2_sorted)
#    print("#"*50)
#    print(D3_sorted)

    return D1_sorted, D2_sorted, D3_sorted

   

def get_data_by_column(D1, indicator, c_value):
    '''
        This function iterates through the dictionary D1 and return a subset of the data.
        The indicator parameter is a string with two values: ‘year’ or ‘platform’.
If indicator equals to ‘year’, append all tuples whose value at the year column is equal
to c_value into the new list. Sort the new list by global sales (global_sales) in
descending order and then by the platform alphabetically.
If indicator equals to ‘platform’, append all tuples whose value at the platform
column is equal to c_value into the new list. Sort the new list by global sales
(global_sales) in descending order and then by the year in ascending order. 
    '''
    op = list()

    if(indicator == 'year'):
        for j in list(D1.values()):
            for i in j:
                #print(i)
                if i[2] == c_value:
                    op.append(i)
        
        op.sort(key = lambda x: x[-1], reverse = True)
        op.sort(key = lambda x: x[1])

            
                

    elif(indicator == 'platform'):
        c_value = str(c_value).lower()
        for j in list(D1.values()):
            #print(j)
            for i in j:
                if i[1] == c_value:
                    op.append(i)

        op.sort(key = lambda x: x[-1], reverse = True)
        op.sort(key = lambda x: x[2])

    return op
        
   

def get_publisher_data(D3, publisher):
    '''
        This function iterates through the dictionary D3.
        It will return a list of all tuples where the publisher key equals
the publisher parameter. 
        
    '''

    #((publisher, name, year, na_sales,eur_sales, jpn_sales, other_sales, global_sales))
    op = list()
    
    for j in list(D3.values()):
        for i in j:
            #print(i)
            if i[0] == publisher:
                op.append(i)
        
    op.sort(key = lambda x: x[1])
    op.sort(key = lambda x: x[-1], reverse = True)

    return op
    
    

def display_global_sales_data(L, indicator):
    '''
        This function prints a table of all the global game sales stored in L1 by either all
platforms in a single year or all years for a single platform.
    '''
    
    header1 = ['Name', 'Platform', 'Genre', 'Publisher', 'Global Sales']
    header2 = ['Name', 'Year', 'Genre', 'Publisher', 'Global Sales']
    total_sales = 0
    
    if(indicator == 'year'):
        print("{:30s}{:10s}{:20s}{:30s}{:12s}".format(header1[0],header1[1],header1[2],header1[3],header1[4]))
        for i in L:
            print("{:30s}{:10s}{:20s}{:30s}{:<12,.02f}".format(i[0][:25],i[1],i[3][:15],i[4][:25],i[5]))
            total_sales += i[5]

    elif(indicator == 'platform'):
        print("{:30s}{:10s}{:20s}{:30s}{:12s}".format(header2[0],header2[1],header2[2],header2[3],header2[4]))
        for i in L:
            print("{:30s}{:10s}{:20s}{:30s}{:<12,.02f}".format(i[0][:25],str(i[2]),i[3][:15],i[4][:25],i[5]))
            total_sales += i[5]

    print("\n{:90s}{:<15,.02f}".format('Total Sales',total_sales))
    
    

def get_genre_data(D2, year):
    '''
        This function iterates through the dictionary D2 and return a list of the total regional sales per genre whose value at the year
column is equal to ‘year’. 
    '''
    
    #((genre, year, na_sales, eur_sales,jpn_sales, other_sales, global_sales))
    op = list()
    count = 0
    total_na_sales = 0
    total_eur_sales = 0
    total_jpn_sales = 0
    total_other_sales = 0
    total_global_sales = 0
    #print("D2", list(sorted(D2.values())))
    
    for j in sorted(D2.values()):
        for i in j:
            if i[1] == year:
                #print(i)
                count += 1
                total_na_sales += i[2]
                total_eur_sales += i[3]
                total_jpn_sales += i[4]
                total_other_sales += i[5]
                total_global_sales += i[6]
        #print("#"*60)        
        a = (i[0],count, total_na_sales, total_eur_sales,total_jpn_sales, total_other_sales, total_global_sales)
        if(count > 0):
            op.append(a)

        
        count = 0
        total_na_sales = 0
        total_eur_sales = 0
        total_jpn_sales = 0
        total_other_sales = 0
        total_global_sales = 0

    op.sort()
    op.sort(key = lambda x: x[-1], reverse = True)

    return op

    
    
def display_genre_data(genre_list):
    '''
       This function prints a table of all the total regional sales for each genre stored in
genre_list.
    '''
    
    header = ['Genre', 'North America', 'Europe', 'Japan', 'Other', 'Global']
    total_sales = 0

    print("{:30s}{:15s}{:15s}{:15s}{:15s}{:15s}".format(header[0],header[1],header[2],header[3],header[4],header[5]))
    for i in genre_list:
        print("{:30s}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}".format(i[0],i[2],i[3],i[4],i[5],i[6]))
        total_sales += i[6]

    print("\n{:90s}{:<15,.02f}".format('Total Sales',total_sales))
    

def display_publisher_data(pub_list):
    '''
        This function prints a table of all the total regional sales for each genre stored in
pub_list.
    '''

    #((publisher, name, year, na_sales,eur_sales, jpn_sales, other_sales, global_sales))
    
    pub = pub_list[0][0]
    header = ['Title', 'North America', 'Europe', 'Japan', 'Other', 'Global']

    total_sales = 0

    print("{:30s}{:15s}{:15s}{:15s}{:15s}{:15s}".format(header[0],header[1],header[2],header[3],header[4],header[5]))
    for i in pub_list:
        print("{:30s}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}".format(i[1][:25],i[3],i[4],i[5],i[6],i[7]))
        total_sales += i[7]

    print("\n{:90s}{:<15,.02f}".format('Total Sales',total_sales))
    

def get_totals(L, indicator):
    '''
        This function receives a list L of tuples with global sales that was generated by the
get_data_by_column function. The function returns two lists: L1, the one with the
strings of each platform name (if indicator == “year” ) or the integers of each
year (if indicator == “platform” ), and the other, L2, is the corresponding
global sales.
    '''
    DPY = dict()
    L1 = list()
    L2 = list()
    
    #(name, platform, year, genre, publisher,global_sales)
    if(indicator == 'year'):
        for i in L:
            platform = i[1]
            try:
                 a = DPY[platform]
                 a += i[5]
                 DPY[platform] = a
            except :
                DPY[platform] = i[5]

        
                
            
        

    elif(indicator == 'platform'):
        for i in L:
            year = i[2]
            try:
                 a = DPY[year]
                 a += i[5]
                 DPY[year] = a
            except :
                DPY[year] = i[5]

    #print(DPY)
    for i in sorted(DPY.keys()):
        L1.append(i)

    for i in L1:
        L2.append(DPY[i])

    #print(L1)
    #print(L2)

    return L1,L2
        

    

def prepare_pie(genres_list):
    '''
       This function receives a list of global sales per genre for a particular year (that is, the list
L comes from a call to get_genre_data for a particular year, the call being done in
option 3 of main). It returns two lists: L1, one with the strings of each genre name, and
the other, L2, is total global sales in that year. These two lists will be used for plotting.
    '''
    
    #(genre,count, total_na_sales, total_eur_sales,total_jpn_sales, total_other_sales, total_global_sales)

    genres_list.sort(key = lambda x: x[1])
    genres_list.sort(key = lambda x: x[-1], reverse = True)

    DG = dict()
    L1 = list()
    L2 = list()

    for i in genres_list:
        L1.append(i[0])
        L2.append(i[-1])

    #print(L1)
    #print(L2)

    return L1, L2

    

def plot_global_sales(x,y,indicator, value):
    '''
        This function plots the global sales per year or platform.
        
        parameters: 
            x: list of publishers or year sorted in ascending order
            y: list of global sales that corresponds to x
            indicator: "publisher" or "year"
            value: the publisher name (str) or year (int)
        
        Returns: None
    '''
    
    if indicator == 'year':    
        pylab.title("Video Game Global Sales in {}".format(value))
        pylab.xlabel("Platform")
    elif indicator == 'platform':    
        pylab.title("Video Game Global Sales for {}".format(value))
        pylab.xlabel("Year")
    
    pylab.ylabel("Total copies sold (millions)")
    
    pylab.bar(x, y)
    pylab.show()

def plot_genre_pie(genre, values, year):
    '''
        This function plots the global sales per genre in a year.
        
        parameters: 
            genre: list of genres that corresponds to y order
            values: list of global sales sorted in descending order 
            year: the year of the genre data (int)
        
        Returns: None
    '''
            
    pylab.pie(values, labels=genre,autopct='%1.1f%%')
    pylab.title("Video Games Sales per Genre in {}".format(year))
    pylab.show()
    
def main():

    fp = open_file()
    D1,D2,D3 = read_file(fp)
    
    # Menu options for the program
    MENU = '''Menu options
    
    1) View data by year
    2) View data by platform
    3) View yearly regional sales by genre
    4) View sales by publisher
    5) Quit
    
    Enter choice: '''

    choice = '1'
                   
    while choice != '5':

        choice = input(MENU)
        
        #Option 1: Display all platforms for a single year
        if(choice == '1'):
            #print()
            y = input("Enter year: ")
            try:
                y = int(y)
                a = get_data_by_column(D1, 'year', y)
                #if the list of platforms for a single year is empty, show an error message
                if(len(a)<1):
                    print("The selected year was not found in the data.")
                    print()
                else:
                    print("\n{:^80s}".format("Video Game Sales in {}".format(y)))
                    display_global_sales_data(a, 'year')
                    if('y' == input("Do you want to plot (y/n)? ")):
                        L1, L2 = get_totals(a,'year')
                        plot_global_sales(L1,L2,'year',y)
            
            except ValueError:
                print("Invalid year.")

        elif(choice == '2'):
            #print()
            p = input("Enter platform: ")
            if(p.isnumeric()):
                print("Invalid platform.")
            else:
                a = get_data_by_column(D1, 'platform', p)
                if(len(a)<1):
                    print("The selected platform was not found in the data.")
                    print()
                else:
                    print("\n{:^80s}".format("Video Game Sales for {}".format(p)))
                    display_global_sales_data(a, 'platform')
                    if('y' == input("Do you want to plot (y/n)? ")):
                        L1, L2 = get_totals(a,'platform')
                        plot_global_sales(L1,L2,'platform',p)
                    
            
        elif(choice == '3'):
            #print()
            y = input("Enter year: ")
            try:
                y = int(y)
                c = get_genre_data(D2, y)
                if(len(c)<1):
                    print("The selected year was not found in the data.")
                    print()
                else:
                    print("\nRegional Video Games Sales per Genre")
                    display_genre_data(c)
                    if('y' == input("Do you want to plot (y/n)? ")):
                        L11, L22 = prepare_pie(c)
                        plot_genre_pie(L11, L22, y)
            except:
                print("Invalid year")
                print()
            
        
                
        #Option 4: Display publisher data
        elif(choice == '4'):
            
                # Enter keyword for the publisher name
                kw = input("\nEnter keyword for publisher: ")
                
                # search all publisher with the keyword
                match = []
                match_set = set()
                data_list = list()
                total_sales = 0

                #fp.readline()
                fp.seek(0)
                reader = csv.reader(fp, dialect='excel') #Reader pointer for reading the csv file
                master_list = list() # Creating an empty list to store data
                

                for line in reader:
                    try:
                        #print(line)
                        name = line[0].lower().strip()
                        platform = line[1].lower().strip()
                        year = int(line[2].lower().strip())
                        genre = line[3].lower().strip()
                        publisher = line[4].lower().strip()
                        na_sales = float(line[5].lower().strip())*1000000
                        eur_sales = float(line[6].lower().strip())*1000000
                        jpn_sales = float(line[7].lower().strip())*1000000
                        other_sales = float(line[8].lower().strip())*1000000
                        global_sales = na_sales+eur_sales+jpn_sales+other_sales

                        

                        if(kw in publisher):
                            #print(publisher)
                            match_set.add(publisher)
                            data_list.append([publisher,name,na_sales,eur_sales,jpn_sales,other_sales,global_sales])
                        else:
                            #print(publisher)
                            pass
                    except:
                        continue
                match = list(match_set)
                match.sort()

                data_list.sort(key = lambda x: x[1])
                data_list.sort(key = lambda x: x[-1], reverse = True)

                #print(len(match))
                # print the number of matches found with the keywords
                if len(match) > 1:    
                    print("There are {} publisher(s) with the requested keyword!".format(len(match)))
                    for i,t in enumerate(match):
                        print("{:<4d}{}".format(i,t))
                    
                    # PROMPT USER FOR INDEX
                    ind = int(input("Select the index for the publisher to use: "))
                    pub_selected = match[ind]
                    
                    #print("\n{:^80s}".format("Video Game Sales for {}".format(pub_selected)))
                    print("\n{}".format("Video Games Sales for {}".format(pub_selected)))
                    print("{:30s}{:15s}{:15s}{:15s}{:15s}{:15s}".format("Title",'North America', 'Europe', 'Japan', 'Other' ,'Global' ))
                    for i in data_list:
                        if(pub_selected in i[0]):
                            print("{:30s}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}{:<15,.02f}".format(i[1][:25],i[2],i[3],i[4],i[5],i[6]))
                            total_sales += i[6]
                            #print(i)
                    
                    print("\n{:90s}{:<15,.02f}".format('Total Sales',total_sales))
                    
                else:
                    index = 0
                    print('No publisher name containing "{}" was found!'.format(kw))
                    print()
                    
        elif(choice == '5'):
            pass
        else:
            print("Invalid option. Please Try Again!")
            print()
                
    
    print("\nThanks for using the program!")
    print("I'll leave you with this: \"All your base are belong to us!\"")

if __name__ == "__main__":
#    fp = open_file()
#    D1,D2,D3 = read_file(fp)
#    a = get_data_by_column(D1, 'year', 1999)
#    print(a)
#    pub_list = get_publisher_data(D3, 'atari')
#    print(b)
#    display_global_sales_data(a, 'year')
#    c = get_genre_data(D2, 2016)
#    display_genre_data(c)
#    display_publisher_data(pub_list)
#    print(a)
#    L1, L2 = get_totals(a,'year')

#    L11, L22 = prepare_pie(c)
        
        
    main()

    #########################
    #   Project Completed   #
    #########################
