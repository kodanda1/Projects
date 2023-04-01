"""
Name: Varuntej Kodandapuram
Coding Challenge 4
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from typing import List


def challenger_finder(stocks_list: List[int], k: int) -> List[int]:
    """
challenger_finder function returns the list of number of
oppenents each player can play with.
The function takes the list of stocks and the allowed range as input.
It returns the list consisting of the number of available opponents
for each player.
Parameters:
stocks_list (List[int]): A Python list of length n, containing integers,
that represents the stocks taken in each player's last match. Each index
represents a player.
k (int):Integer indicating the range that will be used to determine
all available opponents for each player.
Returns:
List[int]:A Python list of length n, containing integers, consisting
of the number of available opponents for each player.
"""
    output = [0] * len(stocks_list)
    if k >= max(stocks_list):
        return [len(stocks_list) - 1] * len(stocks_list)
    if k == 0:
        return output
    new_list = list(stocks_list)
    index1 = 0
    while True:
        if len(new_list) > 0:
            player = new_list.pop(0)
        else:
            return output
        select_range = [player - k, player + k]
        index2 = index1
        for _ in range(len(new_list)):
            index2 += 1
            if select_range[0] <= new_list[_] <= select_range[1]:
                output[index1] += 1
                output[index2] += 1
        index1 += 1
