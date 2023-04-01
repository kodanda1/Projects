"""
Name: Varuntej Kodandapuram
Coding Challenge 6
CSE 331 Spring 2021
Professor Sebnem Onsay
"""

def gates_needed(departures, arrivals):
    """
    The function calculates the arrival and departure time list of flights
    and returns the number of required maximum number of gates
    needed at any point during the day of these departures and arrivals.
    param: departures: List[float]: A python list of floats containing
    departure times of flights at the airport.
    param: arrivals: List[float]: A python list of floats containing
    arrival times of flights at the airport.
    Return: An integer that represents the maximum number of gates
    needed at any point during the day of these departures and arrivals.
    """
    gates = 0
    dlen = len(departures)
    alen = len(arrivals)
    if dlen == 0:
        return len(arrivals)
    if alen == 0:
        return 0
    anew = list(arrivals[::-1])
    dnew = list(departures[::-1])
    while True:
        atemp = anew.pop()
        gates += 1
        dnewlen = len(dnew)
        if(dnewlen != 0):
            dtemp = dnew[-1]
            if atemp < dtemp:
                pass
            if atemp >= dtemp:
                gates -= 1
                dnew.pop()
        anewlen = len(anew)
        if anewlen == 0:
            return gates
