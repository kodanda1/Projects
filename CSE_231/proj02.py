###########################################################################################################################################################################################################
############################################################### Project 2 ###############################################################################################################################
print('''Welcome to car rentals.
At the prompts, please enter the following:
        Customer's classification code (a character: BDW)
        Number of days the vehicle was rented (int)
        Odometer reading at the start of the rental period (int)
        Odometer reading at the end of the rental period (int)''')



while True:
    answer = input('\nWould you like to continue (Y/N)? ')
                                                                          #####################
    if answer.lower() == "y":                                             #     User input    #
                                                                          #####################
            cus_id = input("Customer code (BDW): ")

            while cus_id != "B" and cus_id != "D" and cus_id != "W":
            
                 print("     *** Invalid customer code. Try again. ***")    # When user inputs a wrong customer code (cus_id).
                 
                 cus_id = input('Customer code (BDW): ')
                 

    
            if cus_id == "B" or cus_id == "D" or cus_id == "W":
                duration = int(input("Number of days: "))
                meter_start = int(input("Odometer reading at the start: "))
                meter_end = int(input("Odometer reading at the end:  "))

                ######################################
                # Calculation for the correct output #
                ######################################
                if meter_end >= meter_start:
                    meter = (meter_end - meter_start)/10
                else:
                    meter = ((1000000 - meter_start) + meter_end)/10.0
                if cus_id == "B":                                                        # When customer code is B
                    charge = (40 * duration) + (0.25 * meter)                            # Charge is 40 dollars per day plus mileage charge is 25 cents per mile

                elif cus_id == "D":                                                      # When customer code is D              
                    distance_charge = (((meter/duration)-100)*0.25) * duration
                    if distance_charge > 0:
                        charge = (60 * duration) + distance_charge                       # Charge is 60 dollars per day and distance charge is 0 for first 100 miles and then its 25 cents per mile
                    else:
                        charge = (60 * duration)

                elif cus_id == "W":                                                      # When customer code is W
                    weeks = duration//7
                    if duration%7 != 0:
                        weeks += 1
                    distancePerWeek = meter/weeks
                    if distancePerWeek <= 900:
                        charge = 190 * weeks                                             # Charge is 190 dollars per week
                    elif 900 < distancePerWeek <= 1500:                                  # Mileage charge is 0 if distance per week is less than 900  
                        charge = (190 * (weeks))+(100 * (weeks))                         # Mileage charge is 100 dollars per week if distance per week is less than 1500 but more than 900 
                    elif distancePerWeek > 1500:
                        charge = (190 * (weeks))+(200 * (weeks)) + (((distancePerWeek-1500) * 0.25)*(weeks))   # If it exceeds 1500 miles its 200 dollars per week and a additional charge of 25 cents per mile
               ##################################
               #   Output print prompts below   #
               ##################################
                print("\nCustomer summary:")
                print("\tclassification code:",cus_id)
                print("\trental period (days):",duration)
                print("\todometer reading at start:",meter_start)
                print("\todometer reading at end:  ",meter_end)
                print("\tnumber of miles driven: ",meter)
                print("\tamount due: $",float(charge))
    
    
             
    
    
    elif answer.lower() == "n":
        print("Thank you for your loyalty.")
        break
    else:
        print('Unknown input command, enter only "Y" or "N"')

        ###############################
        #    Project Completed        #
        ###############################
 



    

       
