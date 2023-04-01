"""
Project 4
CSE 331 S21 (Onsay)
Name
CircularDeque.py
"""

from __future__ import annotations
from typing import TypeVar, List
# from re import split as rsplit
import re

# for more information on typehinting, check out https://docs.python.org/3/library/typing.html
T = TypeVar("T")                                # represents generic type
CircularDeque = TypeVar("CircularDeque")        # represents a CircularDeque object

class CircularDeque:
    """
    Class representation of a Circular Deque
    """

    __slots__ = ['capacity', 'size', 'queue', 'front', 'back']

    def __init__(self, data: List[T] = [], capacity: int = 4):
        """
        Initializes an instance of a CircularDeque
        :param data: starting data to add to the deque, for testing purposes
        :param capacity: amount of space in the deque
        """
        self.capacity: int = capacity
        self.size: int = len(data)

        self.queue: list[T] = [None] * capacity
        self.front: int = None
        self.back: int = None

        for index, value in enumerate(data):
            self.queue[index] = value
            self.front = 0
            self.back = index

    def __str__(self) -> str:
        """
        Provides a string represenation of a CircularDeque
        :return: the instance as a string
        """
        if self.size == 0:
            return "CircularDeque <empty>"

        string = f"CircularDeque <{self.queue[self.front]}"
        current_index = self.front + 1 % self.capacity
        while current_index <= self.back:
            string += f", {self.queue[current_index]}"
            current_index = (current_index + 1) % self.capacity
        return string + ">"

    def __repr__(self) -> str:
        """
        Provides a string represenation of a CircularDeque
        :return: the instance as a string
        """
        return str(self)

    # ============ Modify below ============ #
    def __len__(self) -> int:
        """
        Function to Give Length of queue
        """
        if self.front is None and self.back is None:
            return 0
        temp = -1
        if self.back == -1 and self.front == 0:
            # print('Entered')
            # print('F:', self.front, 'B:', self.back, 'S:', self.size)
            temp = 0
        if self.back == self.capacity-1 and self.front == 0:
            # print('Entered2')
            # print('F:', self.front, 'B:', self.back, 'S:', self.size)
            if self.size == self.capacity:
                temp = self.capacity
            elif self.size == 0:
                temp = 0
        if self.front < 0:
            pos_front = len(self.queue) + self.front
        else:
            pos_front = int(self.front)
        if self.back < 0:
            pos_back = len(self.queue) + self.back
        else:
            pos_back = int(self.back)
        self.size = self.back - self.front + 1 if self.front <= self.back \
                    else self.capacity - (self.front - self.back) +1
        if self.front > self.back:
            newlist = self.queue[self.front:]+self.queue[:self.back]
            if None in newlist:
                self.size -= self.queue.count(None)
        # print('####____####')
        # print(self.queue)
        # print('F:',self.front, 'B:', self.back, 'S:', self.size)
        # print('####___####')
        if temp > -1:
            # print('Returning temp')
            self.size = temp
        self.front = pos_front
        self.back = pos_back
        return self.size
    def is_empty(self) -> bool:
        """
        Function to check if Queue is empty
        """
        self.__len__()
        if self.size == 0:
            return 1
        return 0

    def front_element(self) -> T:
        """
        Function to Give Element at start of queue
        """
        if self.front is None:
            return None
        if self.size == 0:
            return None
        # if self.back == self.capacity - 1 and self.front == 0:
        #     if self.size == 0:
        #         return None
        self.__len__()
        return self.queue[self.front]
    def back_element(self) -> T:
        """
        Function to Give Element at end of queue
        """
        if self.back is None:
            return None
        if self.size == 0:
            return None
        self.__len__()
        return self.queue[self.back]
    def front_enqueue(self, value: T) -> None:
        """
        Function to Add Element to CircularDeque from Front
        """
        if self.front is None:
            self.front = 1
        if self.back is None:
            self.back = 0
        # self.__len__()
        if (self.front == self.back) and (self.queue[self.front] is None or self.size == 0):
            self.front += 1
        self.front -= 1
        self.queue[self.front] = value
        temp = int(self.size)
        # print(self.queue, self.size, self.capacity)
        self.__len__()
        self.size = int(temp + 1)
        if self.size == self.capacity:
            # print('Growing')
            self.grow()
            self.front = 0
            self.back = (self.capacity//2) - 1
    def back_enqueue(self, value: T) -> None:
        """
        Function to Add Element to CircularDeque from Back
        """
        if self.front is None:
            self.front = 0
        if self.back is None:
            self.back = -1
        if self.front == self.back and (self.queue[self.back] is None or self.size == 0):
            self.back -= 1
        self.back += 1
        self.queue[self.back] = value
        temp = int(self.size)
        self.__len__()
        self.size = int(temp + 1)
        if self.size == self.capacity:
            self.grow()
            self.front = 0
            self.back = (self.capacity//2) - 1
    def front_dequeue(self) -> T:
        """
        Function to Deque the CircularDeque from Front
        """
        if self.size == 0:
            return None
        elem = self.queue[self.front]
        self.front += 1
        self.front %= self.capacity
        temp = int(self.size)
        self.__len__()
        self.size = int(temp - 1)
        if self.size == self.capacity//4:
            if self.capacity > 4:
                self.shrink()
                self.back = 1
            # self.size = 0
        # print('Element:', elem)
        return elem
    def back_dequeue(self) -> T:
        """
        Function to Deque the CircularDeque from Back
        """
        if self.size == 0:
            return None
        elem = self.queue[self.back]
        self.back -= 1
        temp = int(self.size)
        self.__len__()
        self.size = int(temp - 1)
        return elem
    def grow(self) -> None:
        """
        Function to Growthe CircularDeque
        """
        # print(self.queue)
        self.__len__()
        offset = self.front
        # print(offset)
        self.queue = self.queue[offset:]+self.queue[:offset]
        self.queue.extend([None]*self.capacity)
        self.capacity *= 2
        # print(self.queue)
    def shrink(self) -> None:
        """
        Function to Shrink the CircularDeque
        """
        # print(self.front, self.back)
        self.__len__()
        offset = self.front
        self.queue = self.queue[offset:] + self.queue[:offset]
        # print(self.queue)
        # print('#####')
        self.queue = self.queue[0:(self.capacity // 4)]  # correct queue order
        self.queue.extend([None] * (self.capacity // 4))  # add extra space
        self.capacity //= 2
        self.front %= self.capacity
def LetsPassTrains102(infix: str) -> str:
    """
    Function to Convert Infix to Postfix
    """
    infixlist = infix.split(' ')
    re.search("+", infix).start()
    for i in infixlist:
        if i == '+':
            infixlist[i], infixlist[i+1] = infixlist[i+1], infixlist[i]
