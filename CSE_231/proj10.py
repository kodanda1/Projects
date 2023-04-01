####################################################################################
# Computer Science Project- 10

#Algorithm
 #   Generate a Deck
 #   Display the Deck to User
 #   Prompt for User input
 #   If quit
 #       Quit the Game
 #   If Suffle
 #       Check and Suffle the Deck
 #   If move
 #       Check and move the Card
 #   Check for Win
 #   Display for Win
################################################################################### 
        


import cards, random
random.seed(100) #random number generator will always generate 
                 #the same random number (needed to replicate tests)
try:
    import cards_mimir
except:
    pass

def initialize():
    '''
        
        That function has no parameters. It creates, initializes, and returns the tableau.
        Parameters: None
        Returns -> A List of 4 list containing Card objects in it 
        
    '''
    
    my_deck = cards.Deck()
    try:
        my_deck = cards_mimir.Deck()
    except:
        pass
    my_deck.shuffle()

    #print(my_deck)
    l1 = list()
    l2 = list()
    l3 = list()
    l4 = list()

#    for i in range(2,14):
#        l1.append(cards.Card(i,1))
#    l1.append(cards.Card(1,1))
#
#    for i in range(2,14):
#        l2.append(cards.Card(i,2))
#    l2.append(cards.Card(1,1))
#
#    for i in range(2,14):
#        l3.append(cards.Card(i,3))
#    l3.append(cards.Card(1,1))
#
#    for i in range(2,14):
#        l4.append(cards.Card(i,4))
#    l4.append(cards.Card(1,1))

        

    for i in range(13):
        l1.append(my_deck.deal())
       
    for i in range(13):
        l2.append(my_deck.deal())
        
    for i in range(13):
        l3.append(my_deck.deal())
        
    for i in range(13):
        l4.append(my_deck.deal())
       



    tablu = list()
    tablu.append(l1)
    tablu.append(l2)
    tablu.append(l3)
    tablu.append(l4)

    return tablu

    
    
    
def display(tableau):
    '''
        This function displays the current state of the game.
        It display four rows of 13 cards with row and column labels.
        Ace is displayed with a blank.
        
        parameters: 
            tableau: data structure representing the tableau 
        
        Returns: None
    '''

    print("{:3s} ".format(' '), end = '')
    for col in range(1,14):
        print("{:3d} ".format(col), end = '')
    print()
        
    for r,row_list in enumerate(tableau):
        print("{:3d}:".format(r+1), end = '')
        for c in row_list:
            if c.rank() == 1:
                print("  {}{}".format(' ',' '), end = '')
            else:
                print("{:>4s}".format(str(c)),end = '')
        print()

def validate_move(tableau,source_row,source_col,dest_row,dest_col):
    '''
        The function is used to check whether the move which is to be taken is valid or not.
        Parameters:
            tableau: data structure representing the tableau
            source_row = The row number of Card which is to be moved
            source_col = The column number of Card which is to be moved
            dest_row = Row number of the Destination where Card is to be moved
            dest_col = Column number of the Destination where Card is to be moved
        Returns:
            Boolean

    '''
    #1,1 2,2
    if(0 <= source_row <= 3 and 0 <= source_col <= 12 and 0 <= dest_row <= 3 and 0 <= dest_col <= 12):


        if (tableau[dest_row][dest_col].rank() == 1):
            if(dest_col == 0 and tableau[source_row][source_col].rank() == 2):
                # print('good')
                return True

            elif(tableau[source_row][source_col].rank() == tableau[dest_row][dest_col-1].rank()+1 and tableau[source_row][source_col].suit() == tableau[dest_row][dest_col-1].suit()):
                # print('good2')
                return True
        # print('False1')
        return False
    # print('False2')
    return False

def move(tableau,source_row,source_col,dest_row,dest_col):
    '''
        The move function is used for moving the cards while playing game.
        It swaps the source card with the destination card (an ace) so the source now becomes an empty space.
        Affects and modifies the tableau object.
        Parameters:
            tableau: data structure representing the tableau
            source_row = The row number of Card which is to be moved
            source_col = The column number of Card which is to be moved
            dest_row = Row number of the Destination where Card is to be moved
            dest_col = Column number of the Destination where Card is to be moved
        Returns:
            Boolean
    '''
 
    if(0 <= source_row <= 3 and 0 <= source_col <= 12 and 0 <= dest_row <= 3 and 0 <= dest_col <= 12):
        
        if(tableau[dest_row][dest_col].rank()==1 and tableau[source_row][source_col].rank() == tableau[dest_row][dest_col-1].rank()+1 and tableau[source_row][source_col].suit() == tableau[dest_row][dest_col-1].suit()):
            tableau[source_row][source_col], tableau[dest_row][dest_col] = tableau[dest_row][dest_col], tableau[source_row][source_col]
            return True
        
        elif(dest_col== 0 and tableau[source_row][source_col].rank() == 2):
            tableau[source_row][source_col], tableau[dest_row][dest_col] = tableau[dest_row][dest_col], tableau[source_row][source_col]
            return True
        else:
            return False

    return False


  
def shuffle_tableau(tableau):
    '''
        That function has five parameters: the data structure representing the tableau and four ints the
        source row & column and the destination row & column. 
        It willswap the source card with the destination card (an ace) so the source now becomes an empty space.

        Parameters:
            tableau: data structure representing the tableau
            source_row = The row number of Card which is to be moved
            source_col = The column number of Card which is to be moved
            dest_row = Row number of the Destination where Card is to be moved
            dest_col = Column number of the Destination where Card is to be moved
        Returns:
            Boolean

        
    '''
    shuffle = list()
    shuffle1 = list()
    shuffle2 = list()
    shuffle3 = list()
    shuffle4 = list()
    
    l1 = tableau[0]
    l2 = tableau[1]
    l3 = tableau[2]
    l4 = tableau[3]

#    print('l1', l1)
#    print('l2', l2)
#    print('l3', l3)
#    print('l4', l4)

    l1_temp = list()
    l2_temp = list()
    l3_temp = list()
    l4_temp = list()
    
    
    seq = 1
    for i in range(len(l1)):
        if(l1[i].rank()==i+2 and l1[0].suit() == l1[i].suit() and seq == 1):
            l1_temp.append(l1[i])
        else:
            seq = 0
            
            shuffle1.append(l1[i])

    seq = 1
    for i in range(len(l2)):
        if(l2[i].rank()==i+2 and l2[0].suit() == l2[i].suit() and seq == 1):
            l2_temp.append(l2[i])
        else:
            seq = 0
            shuffle2.append(l2[i])

    seq = 1
    for i in range(len(l3)):
        if(l3[i].rank()==i+2 and l3[0].suit() == l3[i].suit() and seq == 1):
            l3_temp.append(l3[i])
        else:
            seq = 0
            shuffle3.append(l3[i])

    seq = 1
    for i in range(len(l4)):
        if(l4[i].rank()==i+2 and l4[0].suit() == l4[i].suit() and seq == 1):
            l4_temp.append(l4[i])
        else:
            seq = 0
            shuffle4.append(l4[i])

    shuffle = shuffle1 + shuffle2 + shuffle3 + shuffle4
            

#    print('l1 temp',l1_temp)
#    print('Shuffle1', shuffle1)
#
#    print('l2 temp',l2_temp)
#    print('Shuffle2', shuffle2)
#
#    print('l3 temp',l3_temp)
#    print('Shuffle3', shuffle3)
#
#    print('l4 temp',l4_temp)
#    print('Shuffle4', shuffle4)
#
#    print("Shuffle", shuffle)
    
    random.shuffle(shuffle)

#    print("RShuffle", len(shuffle))

    temp = list()
    count = 0
    for i in shuffle:
        if(i.rank() != 1):
            temp.append(i)
        else:
            if(count == 0):
                l1_temp.append(i)
            if(count == 1):
                l2_temp.append(i)
            if(count == 2):
                l3_temp.append(i)
            if(count == 3):
                l4_temp.append(i)
            count += 1
            
#    print('Temp',len(temp))

    while(len(l1_temp) != 13):
        l1_temp.append(temp.pop(0))

        
    while(len(l2_temp) != 13):
        l2_temp.append(temp.pop(0))

        
    while(len(l3_temp) != 13):
        l3_temp.append(temp.pop(0))

        
    while(len(l4_temp) != 13):
            l4_temp.append(temp.pop(0))


#    print('l1 temp',l1_temp)
#    print('l2 temp',l2_temp)
#    print('l3 temp',l3_temp)
#    print('l4 temp',l4_temp)

    
    tableau[0] = l1_temp
    tableau[1] = l2_temp
    tableau[2] = l3_temp
    tableau[3] = l4_temp
    
                
                

    

def check_win(tableau):
    '''
        That function has one parameter: the data structure representing the tableau.
        The function checks whether the game is won or not and returns a boolean accordingly.

        Parameters:
            tableau: data structure representing the tableau
        Returns:
            Boolean
    '''

    for i in range(len(tableau)):
        if(tableau[i][0].rank() == 2 and tableau[i][-1].rank() == 1):
            for j in range(len(tableau[i])-2):
                if(tableau[i][j].rank() == tableau[i][j+1].rank()-1 and tableau[i][j].suit() == tableau[i][j+1].suit()):
                    pass
                else:
                    return False
        else:
            return False


    return True
             
def main():
    '''
        Main Function to execute the program.
        Algorithm:
            a) Your program should start by initializing the tableau.
            b) Display the tableau.
            c) Ask to input an option and check the validity of the input.
            d) If ‘Q’, quit the game
            e) If ‘S’, shuffle the tableau and display the tableau
            f) If ‘Sr Sc Dr Dc’, move card from Tableau (Sr, Sc) to empty Tableau (Dr, Dc).
            g) If none of these options, the program should display an error message.
            h) The program should repeat until the user won or quit the game.
            i) Then ask if the user wants another game
            j) Display a goodbye message.
            
        Parameters:
            None
        Returns:
            None
    '''
    s_count = 0
    tablu = initialize()
    print("Montana Solitaire.")
    display(tablu)
    c = 0
    while True:
        print()
        inp = input("Enter choice:\n (q)uit, (s)huffle, or space-separated: source_row,source_col,dest_row,dest_col: ")
        
        if('q' == inp.lower()):
            print()
            if(input("Do you want to play again (y/n)?").lower() == 'y'):
                tablu = initialize()
                print("Montana Solitaire.")
                display(tablu)
                print()
            else:
                break

        elif('s' == inp.lower()):
            if(s_count < 2):
                shuffle_tableau(tablu)
                s_count += 1
                display(tablu)
            else:
                print("No more shuffles remain.")
        
        elif(len(inp.split())==4):
            li = inp.split()
            try:
                li[0] = int(li[0])-1
                li[1] = int(li[1])-1
                li[2] = int(li[2])-1
                li[3] = int(li[3])-1
            

                if(not (0 <= li[0] <= 3 and 0 <= li[1] <= 12 and 0 <= li[2] <= 3 and 0 <= li[3] <= 12)):
                    print("Error: row and/or column out of range. Please Try again.")
                    
                else:

                    if(validate_move(tablu,li[0],li[1],li[2],li[3])):
                        if(move(tablu,li[0],li[1],li[2],li[3])):
                            display(tablu)
                            print()
                        else:
                            print("Error: invalid move.  Please try again.")
                    else:
                        print("Error: invalid move.  Please try again.")
            except Exception as e:
                print("Error: invalid input.  Please try again.")
                
        else:
            print("Error: invalid input.  Please try again.")
    
        win = check_win(tablu)
        #print('Win',win)
        if(win):
            print("You won!")
            print()
            if(input("Do you want to play again (y/n)?").lower() == 'y'):
                s_count = 0
                tablu = initialize()
                print("Montana Solitaire.")
                display(tablu)
                
            else:
                break
            
    print("Thank you for playing.")
     

if __name__ == "__main__":

    main()

#############################
#     Project Completed     #
#############################
    
