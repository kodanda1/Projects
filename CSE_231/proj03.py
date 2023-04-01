########################################################
#CSE 231 PROJECT - 03
#This project calculates the tuition for MSU students.
########################################################                                                                             

# welcome message
print("2019 MSU Undergraduate Tuition Calculator.")

# loop to keep asking for input
while True:
    pg = None
    # while taking input only converting into lower 
    resident = input("\nResident (yes/no): ").lower()
    if resident == "yes":
        resident = "domestic"
    else:
        resident = input("International (yes/no): ").lower()
        if resident == "yes":
            resident = "international"
    # infinity loop to ask continuesly until found correct value 
    while True:
        level = input("Level—freshman, sophomore, junior, senior: ").lower()
        if level != "freshman" and level != "sophomore" and level != "junior" and level != "senior":
            print("Invalid input. Try again.")
        else:
            break
    # for junior and senior
    # ug variable is for college and pg is to track CMSE 
    if level == "junior" or level == "senior":
        ug = input("Enter college as business, engineering, health, sciences, or none: ").lower()
        if ug != "business" and ug != "engineering" and ug != "health" and ug != "sciences" and ug != "none":
            ug = "none"
        pg = input("Is your major CMSE (“Computational Mathematics and Engineering”) (yes/no): ").lower()
        if pg == "yes":
            pg = "CMSE"
        else:
            pg = None
    # for freshman and sophomore
    elif level == "freshman" or level == "sophomore":
        ug = input("Are you admitted to the College of Engineering (yes/no): ").lower()
        if ug == "yes":
            ug = "engineering"
        else:
            ug = "none"
    if ug == "none":
        ug = input("Are you in the James Madison College (yes/no): ").lower()
        if ug == "yes":
            ug = "JMC"
        else:
            # if masters is CMSE means UG should also be engineering
            if pg is not None:
                ug = "engineering"
            else:
                ug = "none"
    # reading credit 
    while True:
        credit = input("Credits: ")
        # credit should be more than 0 and digit
        if credit.isdigit() and int(credit) > 0:
            break
        print("Invalid input. Try again.")
    credit = int(credit)

    # initializing amount as 0
    amount = 0
    # '''checking each level one by one with different credit condition and
    # wheather the student is domestic or international'''
    # for freshman
    if level == "freshman":
        if resident == "domestic":
            if credit < 12:
                amount = credit * 482
            if 19 > credit > 11:
                amount = 7230
            if credit > 18:
                amount = 7230 + (credit-18) * 482
        if resident == "international":
            if credit < 12:
                amount = credit * 1325.50
            if 19 > credit > 11:
                amount = 19883
            if credit > 18:
                amount = 19883 + (credit-18) * 1325.50
            if credit < 5:
                amount += 375
            if credit > 4:
                amount += 750
        if ug == "CE":
            if credit < 5:
                amount = amount + 402
            if credit > 4:
                amount = amount + 670
    # for sophomore
    if level == "sophomore":
        if resident == "domestic":
            if credit < 12:
                amount = credit * 494
            if 19 > credit > 11:
                amount = 7410
            if credit > 18:
                amount = 7410 + (credit-18) * 494
        if resident == "international":
            if credit < 12:
                amount = credit * 1325.50
            if 19 > credit > 11:
                amount = 19883
            if credit > 18:
                amount = 19883 + (credit-18) * 1325.50
            if credit < 5:
                amount += 375
            if credit > 4:
                amount += 750
        if ug == "engineering":
            if credit < 5:
                amount = amount + 402
            if credit > 4:
                amount = amount + 670
    # for junior 
    if level == "junior":
        if (ug == "business" or ug == "engineering") and pg is None:
            if resident == "domestic":
                if credit < 12:
                    amount = credit * 573
                if 19 > credit > 11:
                    amount = 8595
                if credit > 18:
                    amount = 8595 + (credit-18) * 573
            if resident == "international":
                if credit < 12:
                    amount = credit * 1385.75
                if 19 > credit > 11:
                    amount = 20786
                if credit > 18:
                    amount = 20786 + (credit-18) * 1385.75
                if credit < 5:
                    amount += 375
                if credit > 4:
                    amount += 750
        else:
            if resident == "domestic":
                if credit < 12:
                    amount = credit * 555
                if 19 > credit > 11:
                    amount = 8325
                if credit > 18:
                    amount = 8325 + (credit-18) * 555
            if resident == "international":
                if credit < 12:
                    amount = credit * 1366.75
                if 19 > credit > 11:
                    amount = 20501
                if credit > 18:
                    amount = 20501 + (credit-18) * 1366.75
                if credit < 5:
                    amount += 375
                if credit > 4:
                    amount += 750
        if ug == "business":
            if credit < 5:
                amount += 113
            if credit > 4:
                amount += 226
        elif ug == "engineering" and pg is None:
            if credit < 5:
                amount += 402
            if credit > 4:
                amount += 670
        elif ug == "health":
            if credit < 5:
                amount += 50
            if credit > 4:
                amount += 100
        elif ug == "sciences":
            if credit < 5:
                amount += 50
            if credit > 4:
                amount += 100
        if pg == "CMSE":
            if credit < 5:
                amount += 402
            if credit > 4:
                amount += 670
    # for senior
    if level == "senior":
        if ug == "buisness" or ug == "engineering":
            if resident == "domestic":
                if credit < 12:
                    amount = credit * 573
                if 19 > credit > 11:
                    amount = 8595
                if credit > 18:
                    amount = 8595 + (credit-18) * 573
            if resident == "international":
                if credit < 12:
                    amount = credit * 1385.75
                if 19 > credit > 11:
                    amount = 20786
                if credit > 18:
                    amount = 20786 + (credit-18) * 1385.75
                if credit < 5:
                    amount += 375
                if credit > 4:
                    amount += 750
        else:
            if resident == "domestic":
                if credit < 12:
                    amount = credit * 555
                if 19 > credit > 11:
                    amount = 8325
                if credit > 18:
                    amount = 8325 + (credit-18) * 555
            if resident == "international":
                if credit < 12:
                    amount = credit * 1366.75
                if 19 > credit > 11:
                    amount = 20501
                if credit > 18:
                    amount = 20501 + (credit-18) * 1366.75
                if credit < 5:
                    amount += 375
                if credit > 4:
                    amount += 750
        if ug == "business":
            if credit < 5:
                amount += 113
            if credit > 4:
                amount += 226
        elif ug == "engineering":
            if credit < 5:
                amount += 402
            if credit > 4:
                amount += 670
        elif ug == "health":
            if credit < 5:
                amount += 50
            if credit > 4:
                amount += 100
        elif ug == "sciences":
            if credit < 5:
                amount += 50
            if credit > 4:
                amount += 100
        if pg == "CSME":
            if credit < 5:
                amount += 402
            if credit > 4:
                amount += 670
    # adding FM Radio tax
    amount += 3
    # state news tax 
    if credit > 5:
        amount += 5
    # ASMSU Tax since it's UG college all students are UG
    amount += 21
    # James Madison College Student Senate Tax 
    if ug == "JMC":
        amount += 7.50
    
    print("Tuition is ${:,.2f}.".format(amount))
    if input("Do you want to do another calculation (yes/no): ").lower() != "yes":
        break

                                                                                    #########################
                                                                                    #   Project Completed   #
                                                                                    #########################
