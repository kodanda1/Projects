###########################################################################
# Computer Science Project- 11

#Algorithm
#    Get a Filename for List of Classes
#    Display the intro to user
#    Prompt for User input
#    If U,D,L,R
#        Move to Given Direction
#    If S
#        Search for Items
#    If B
#        Show the Student Backpack
#    If P
#        Pickup an Item from Classroom
#    If DR
#        Drop the item in Classroom
#    If H
#        Print Help Menu
        
#    Check for Win
#    Display for Win
##########################################################################





MAP = {"U":"Up","D":"Down","L":"Left","R":"Right"}

class Student(object):
    '''
       A student knows the id of the room they are currently in,
        and has a list of its inventory.

        Methods:
            __init__(self, item_list, classroom_id):
            __repr__(self):
            __str__(self):
            place(self, classroom_id):
            add_item(self, item):
            remove_item(self, item):
            __eq__(self, S):
    '''
    def __init__(self, item_list=None, classroom_id=-1):
        '''Initializes yourself, with an empty backpack by default. The default position of the student is room -1.'''

        if item_list == None:
            self.backpack = []
        else:
            self.backpack = item_list
            
        self.classroom_id = classroom_id

    def __repr__(self):
        '''Returns a string representation of the student.'''

        return self.__str__()

    def __str__(self):
        '''Returns a string representing the student's inventory.'''
        s = "Backpack: "
        if len(self.backpack) == 0:
            s += "Empty"
        else:
            for item in self.backpack:
                s += item + ", "
            else:
                s = s[:-2] # remove trailing comma and space
        return s

    def __eq__( self, S ):
        '''
         Paramaters:
            self- Object Instance
            S - A Student Object
        Description:
                Returns True if Student's classroom id and backpack are equal to
                the classroom id and backpack of S. Otherwise, returns False. 
        '''
        if(self.classroom_id == S.classroom_id and self.backpack == S.backpack):
            return True
    
        return False
     
    def place(self, classroom_id):
        '''
            Paramaters:
            self- Object Instance
            classroom_id - The id of classroom where you want to place the student
        Description:
            Places a student in a classroom, but is implemented by
            adding a classroom ID to the student instance.
        '''
    
        self.classroom_id = classroom_id
    
    def add_item(self, item):
        '''
             Paramaters:
            self- Object Instance
            item - The item which we want to add
        Description:
           Adds the item to the student's backpack. If the backpack already
           has 6 items in it, print “Backpack is full.”
        '''
        if(len(self.backpack)>5):
            print("Backpack is full.")
        else:
            self.backpack.append(item)
        
            

    def remove_item(self, item):
        '''
            Paramaters:
            self- Object Instance
            item - The item which we want to remove
        Description:
           Removes the item from the student's backpack. If the item is in the backpack, remove it. 
        '''
        try:
            if(self.backpack.index(item)>=0):
                self.backpack.remove(item)
                return True
        except:
        
            print("Failed to remove item from backpack.")
            return False
        
            


class Classroom(object):
    '''
        Classroom is the class that represents a single classroom at a time. Associated with each
        classroom is a unique id, an int, and a course, a string.
        It may also
        have one or more directions to other rooms in the hallway – which gives many options to run to
        other classrooms – and there are one or more items in the classrooms.

        Methods:
            __init__(self, text_desc ="0 empty"):
            __repr__(self):
            __str__(self):
            add_item(self, item):
            remove_item(self, item):
            get_room(self, direction):
            __eq__(self, C):
    '''
    def __init__(self, text_desc="0 empty"):
        '''Initialzes a classroom. By default it has id 0 and is a "empty" room with no inventory or exits.'''
        description = text_desc.split()
        
        #print("Description", description)
        
        self.id = int(description[0])
        self.course = description[1]

        # Initialize a dictionary of potential exits as empty
        self.exits = {}

        # Initialize a "backpack" of items as empty list
        self.backpack = []
        
        #ADD YOUR CODE HERE
        
        for i in description[2:]:
            # print('I Value',i)

            if(i[0].islower()):
                self.backpack.append(i)
            else:
                #print('I value',i, i[1:])
                self.exits[i[0]] = int(i[1:])
            

    def __repr__(self):
        '''Returns a string representation of the classroom.'''
        classroom_repr = '''Classroom("''' + repr(self.id) + " " + self.course

        for direction in self.exits:
            classroom_repr += " {}".format(direction) + repr(self.exits[direction])

        for item in self.backpack:
            classroom_repr += " " + item

        classroom_repr += '''")'''

        return classroom_repr

    def __str__(self):
        '''Returns a string representing the room in a nice conversational style.'''

        # Basic classroom description
        classroom_str = "You see a " + self.course + " classroom."

        # List the things in the classroom
        if len(self.backpack) == 1:
            classroom_str += " On the desk you see a " + \
                             self.backpack[0] + "."
        if len(self.backpack) == 2:
            classroom_str += " On the desk you see a " + \
                             self.backpack[0] + \
                             " and a " + self.backpack[1] + "."
        elif len(self.backpack) > 2:
            classroom_str += " On the desk you see "
            for item in self.backpack[:-1]:
                classroom_str += "a " + item + ", "
            classroom_str += "and a " + self.backpack[-1] + "."

        # List the exits
        if len(self.exits) == 0:
            classroom_str += " Run through the classroom grab what you need (if possible). Exit and run to the exam!"
        elif len(self.exits) == 1:
            classroom_str += " Run through the classroom grab what you need (if possible). Now, run into the hallway and go " + \
                             MAP[list(self.exits.keys())[0]] + "."
        elif len(self.exits) == 2:
            classroom_str += " Run through the classroom grab what you need (if possible). Now, run into the hallway and go " + \
                             MAP[list(self.exits.keys())[0]] + " or " + MAP[list(self.exits.keys())[1]] + "."
        elif len(self.exits) > 2:
            classroom_str += " Run through the classroom grab what you need (if possible). Now, run into the hallway and go "
            for direction in list(self.exits.keys())[:-1]:
                classroom_str += MAP[direction] + ", "
            classroom_str += "or " + MAP[list(self.exits.keys())[-1]] + "."

        return classroom_str
    
    def __eq__( self, C ):
        '''
            Paramaters:
            self- Object Instance
            C - A Class Object

        Description:
            Returns True if Classroom id, course, exits and backpack are equal
            to the id, course, exits and backpack of C. Otherwise, returns False.
        '''
        if(self.id == C.id and self.course == C.course and self.backpack == C.backpack):
            return True
        return False
    
    def add_item(self, item):
        '''
            Paramaters:
            self- Object Instance
            item - The item which we want to add
        Description:
           Adds the item to the class's backpack.
        '''
        self.backpack.append(item)
        pass

    def remove_item(self, item):
        '''
            Paramaters:
            self- Object Instance
            item - The item which we want to remove
        Description:
           Removes the item from the class's backpack. If the item is in the backpack, remove it. 
        '''
        try:
            if(self.backpack.index(item)>=0):
                self.backpack.remove(item)
                return True
        except:
            print("Failure to find the item in the classroom.")
            return False
    

    def get_room(self, direction):
        '''
           Parameters:
            self- Object Instance
            direction- The direction in which the student have to move
        Description:
                Returns the room id in the given direction, or False if
                there is no such room. The direction must be a valid key into self.exits, i.e. U, D, R, L;
                returns False, if not valid.
        '''
        try:
            if direction in sorted(self.exits.keys()):
                # print(self.exits[direction])

                return int(self.exits[direction])
        except:
            return False
        
    

        

class Rush(object):
    '''
       Rush is the class that governs the escapade itself. It is responsible for interactions between
        the user, the character, and the rooms.
        
        Methods:
            __init__(self, filename):
            __repr__(self):
            __str__(self):
            intro(self):
            print_help(self):
            prompt(self):
            search(self):
            backpack(self):
            pickup(self, item):
            drop(self, item):
            move(self, direction):
            win(self):
    '''

    def __init__(self, filename="rushing.txt"):
        '''Initializes the student rushing to class.  The student starts in the classroom with the lowest id.'''

        # First make a student start with an empty inventory
        self.student = Student()

        # Create classrooms are an empty dictionary
        self.classrooms = {}
        
        # Now read the file to get the classroom lines
        
        #ADDED YOUR CODE HERE
        
       
        fp = open(filename,encoding='utf-8')
            
        data = fp.read().split('\n')
    
        for i in data:
            if(len(i)<2):
                continue
            j = i.split(' ')
            #print("Value I", i, j[0])
            self.classrooms[int(j[0])] = Classroom(i)
        
    
        # Place the student in the room with lowest id
        self.student.place(min(self.classrooms.keys()))
        

    def __repr__(self):
        '''Returns a string representation.'''

        return self.__str__()

    def __str__(self):
        '''Returns a string representing the journey to the class, simply giving the number of rooms.'''
        search_str = "You are searched in "
        if len(self.classrooms) == 0:
            search_str += "no classrooms at all, you are in the hallway. You are late run in a random class and get items from the desks."
        elif len(self.classrooms) == 1:
            search_str += "a classroom."
        else:
            search_str += "a set of " + str(len(self.classrooms)) + \
                          " classrooms."

        return search_str

    def intro(self):
        '''Prints an introduction to the search for items because you are late
        This prompt includes the commands.'''
        print("\nAHHHH! I'm late for class\n")
        print("*runs out the house to catch the bus with an empty backpack*")

        print("\nYou're popular and have friends in many classes. Find and collect any items you find useful for your exam.")
        print("You are already late, and have a CSE231 Final Exam in 10 mins.\n")
        self.print_help()


    def print_help(self):
        '''Prints the valid commands.'''
        print("Use your instincts: ")
        print("*thinks*.. *thinks*.. what to do?!?!?!?!")
        print("*running*")
        print("S or search -- prints a description of the classroom you ran into")
        print("B or backpack - prints a list of items in your backpack")
        print("P pencil or pickup pencil - *mental* instruction to pick up an item called pencil")
        print("DR pencil or drop pencil - *mental* instruction to drop off an item called pencil")
        print("U or up - *mental* instruction to up the hallway to find another classroom")
        print("D or down - *mental* instruction to down the hallway to find another classroom")
        print("R or right - *mental* instruction to right in the hallway to find another classroom")
        print("L or left - *mental* instruction to left in the hallway to find another classroom")
        print("G or giveup - I have no more time, I need to get to class!!!")
        print("H or help - prints this list of options again")
        print()
        print("Remember that uppercase and lowercase SHOULD NOT matter. ")
        print("JUST GRAB WHAT YOU NEED AND GET TO CLASS TO START YOUR FINAL EXAM!!! HURRYYYY!!!")
        print()

    def prompt(self):
        '''Prompts for input and handles it, whether by error message or handling a valid command.
        Returns True as long as the user has not chosen to quit, False if they have.'''

        print("In room {} with course {}".format(self.student.classroom_id,self.classrooms[self.student.classroom_id].course))
        print(self.student)
        
        
        user_input = input("Enter a command (H for help): ")
        print()

        # Handle input: split for pickup/drop, capitalization unimportant for commands
        input_list = user_input.split()

        if len(input_list) == 0:
            user_input = "?"  # No command is not a valid command
            return False
        else:
            try:
                command = input_list[0].upper()  # The command
                if len(input_list) > 1:
                    item = input_list[1]
                if command == 'S':
                    self.search()
                elif command == 'B':
                    self.backpack()
                elif command == 'P':
                    self.pickup(item)
                elif command == 'DR':
                    self.drop(item)
                elif command in "UDLR":
                    self.move(command)
                elif command == 'G':
                    print("I have no more time, I need to get to class!!!")
                    return False
                elif command == 'H':
                     self.print_help() 
                else:
                    print("Unfortunately, that's not a valid option.")
                    return False
            except Exception as e:
                print("Problem with the option or the item.",e)
                return False
        if self.win():
            return "win"
        return True

    def search(self):
        '''Prints the description of the current room.'''
        current_classroom = self.classrooms[self.student.classroom_id]
        print(current_classroom)

    def backpack(self):
        '''
            Parameters:
            self- Object Instance
            
        Description:
            This method prints the student’s inventory in their backpack, using the
            method you wrote for Student.
        '''
        a = self.student
        # a = Student(self)
        print(a)
        pass

    def pickup(self, item):
        '''
          Parameters:
            self- Object Instance
            item - The item to pickup
        Description:
            This method coordinates the student with their current classroom to
            remove the item from the classroom and add it to the student’s backpack. If the item is not
            present in the classroom (removal returns False), it must not be added to the student’s backpack. 
        '''
        current_classroom = self.classrooms[self.student.classroom_id]
        # print(current_classroom)
        try:
            if(current_classroom.backpack.index(item)>=0):
                if(current_classroom.remove_item(item)):
                    self.student.add_item(item)
        except:
            print("Failure to find the item in the classroom.")
            return False
    
        
            
    
    def drop(self, item):
        '''
           Parameters:
            self- Object Instance
            item - The item to drop
        Description:
             This method coordinates the student with their current classroom and
             removes the item from the student’s backpack and places it in the classroom.

        '''
        current_classroom = self.classrooms[self.student.classroom_id]
        if(self.student.remove_item(item)):
            current_classroom.add_item(item)

        pass

    def move(self, direction):
        '''
           Parameters:
            self- Object Instance
            direction - The direction in which the Student wants to move
        Description:
              This method moves the student in the specified direction if the
              current classroom has that direction in its attributes. If not, the move fails,
              and this method will print an error message.

        '''
        current_classroom = self.classrooms[self.student.classroom_id]
        old_id = self.student.classroom_id
        old_classroom = current_classroom
        # print(current_classroom.get_room(direction))
        self.student.classroom_id = current_classroom.get_room(direction)

        
        

        try:
            current_classroom = self.classrooms[self.student.classroom_id]
            print("You went " + MAP[direction] + " and found a new classroom.")
        except:
            errMsg = "Unfortunately, you went " + MAP[direction] + " and there was no classroom."
            print(errMsg)
            self.student.classroom_id = old_id
            
            
       

    def win(self):
        '''
            Parameters:
            self- Object Instance
        Description:
              This method checks that the student has entered the CSE231 classroom and has
              in their backpack the cheatsheet, eraser, paper, and pencil. If so, it returns True,
              else it returns False.
        '''
        winning_backpack = ['cheatsheet', 'eraser', 'paper', 'pencil']
        li = sorted(self.student.backpack)
        try:
            current_classroom = self.classrooms[self.student.classroom_id]
            
            if(winning_backpack == li):
                if('CSE231' in str(current_classroom)):
                    return True
            return False
        except:
            return False
        # print(current_classroom)

        
            

    
def main():
    '''
    Prompts the user for a file, then plays that file until the user chooses to give up.
    Does not check formatting of input file.
    '''

    while True:
        try:
            filename = input("Enter a text filename: ")
            escapade = Rush(filename)
            break
        except IOError:
            print("Cannot open file:{}. Please try again.".format(filename))
            continue
    
    escapade.intro()
    escapade.__str__()
    escapade.search()
    
    keep_going = True
    while keep_going:
        keep_going = escapade.prompt()
        if keep_going == 'win':
            break
    if keep_going == 'win':
        print("You succeeded!")
    else:
        print("Thank you for playing")

if __name__ == "__main__":    
    main()


##############################
#     Project Completed      #
##############################
