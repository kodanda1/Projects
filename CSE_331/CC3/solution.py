"""
Name: Varuntej Kodandapuram
Coding Challenge 3
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from typing import List

def finding_best_bot(bots_list: List[int]) -> int:
    """The function will receive a python list of integers that
represents the number of salmonids that my bot defeated. The
function is supposed to find the index of the bot where the
salmonid defeat count stopped increasing in the given input list.
Parameters:
bots_list: List[int]:The python list of integer of size n that
represents the number of salmonids that your bot defeated.
Returns:
int: list_length  integer that represents the bot’s index where
the salmonid defeat count stopped increasing in the given python
list, in the other words,the last bot where defeat count increased."""
    def finding_best_bot_helper(start: int, end: int):
        """The function is being used to find the output for the
finding_best_bot. This function is a recursion based function
and hence it uses recursion to find the output."""
        mid = (start+ end) // 2
        if mid+1 == length:
            return mid+1
        if bots_list[mid-1] < bots_list[mid] < bots_list[mid+1]:
            return finding_best_bot_helper(mid+1, end)
        if bots_list[mid-1] > bots_list[mid] > bots_list[mid+1]:
            return finding_best_bot_helper(start, mid)
        if bots_list[mid-1] < bots_list[mid] > bots_list[mid+1]:
            return mid+1
    length = len(bots_list)
    return finding_best_bot_helper(0, length-1)
