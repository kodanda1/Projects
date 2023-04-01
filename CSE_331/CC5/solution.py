"""
Varuntej Kodandapuram
Coding Challenge 5
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from typing import List


def check_walls_cover(walls: List[int]) -> List[int]:
    """
check_walls_cover function returns the list of number of
walls which are visible from individual wall.
The function takes the list of height of walls.
It returns the list consisting of the number walls visible
from each wall.
Parameters:
walls: List[int]): A Python list of length n, containing integers,
that represents the height of the walls.
Returns:
List[int]:A Python list of length n, containing integers, consisting
of the number of walls visible from each wall.
    """
    def calculate(walls):
        """
            helper function for calculation.
        """
        length = len(walls)
        temp = [0] * length
        slist = []
        for _ in range(length):
            if len(slist) == 0:
                temp[_] = 0
            elif slist[-1] > walls[_]:
                temp[_] = len(slist)
            else:
                while len(slist) > 0 and slist[-1] < walls[_]:
                    slist.pop()
                temp[_] = len(slist)
            slist.append(walls[_])
        return temp
    symmetric = 0
    rwalls = walls[::-1]
    if walls == rwalls and len(walls) % 2 == 0:
        symmetric = 1
    score_normal = calculate(walls)
    score_reverse = calculate(rwalls)
    score_reverse.reverse()
    output = list()
    if symmetric == 0:
        for data1, data2 in zip(score_normal, score_reverse):
            output.append(data1 + data2)
    else:
        for data1, data2 in zip(score_normal, score_reverse):
            output.append(data1 + data2 - 1)
    return output
