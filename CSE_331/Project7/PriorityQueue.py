"""
Varuntej Kodandapuram
Project 5 - PriorityHeaps - Solution Code
CSE 331 Fall 2020
Dr. Sebnem Onsay
"""

from typing import List, Any
from Project7.PriorityNode import PriorityNode, MaxNode, MinNode


class PriorityQueue:
    """
    Implementation of a priority queue - the highest/lowest priority elements
    are at the front (root). Can act as a min or max-heap.
    """

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   DO NOT MODIFY the following attributes/functions
    #   Modify only below indicated line
    __slots__ = ["_data", "_is_min"]

    def __init__(self, is_min: bool = True):
        """
        Constructs the priority queue
        :param is_min: If the priority queue acts as a priority min or max-heap.
        """
        self._data = []
        self._is_min = is_min

    def __str__(self) -> str:
        """
        Represents the priority queue as a string
        :return: string representation of the heap
        """
        return F"PriorityQueue [{', '.join(str(item) for item in self._data)}]"

    __repr__ = __str__

    def to_tree_str(self) -> str:
        """
        Generates string representation of heap in Breadth First Ordering Format
        :return: String to print
        """
        string = ""

        # level spacing - init
        nodes_on_level = 0
        level_limit = 1
        spaces = 10 * int(1 + len(self))

        for i in range(len(self)):
            space = spaces // level_limit
            # determine spacing

            # add node to str and add spacing
            string += str(self._data[i]).center(space, ' ')

            # check if moving to next level
            nodes_on_level += 1
            if nodes_on_level == level_limit:
                string += '\n'
                level_limit *= 2
                nodes_on_level = 0
            i += 1

        return string

    def is_min_heap(self) -> bool:
        """
        Check if priority queue is a min or a max-heap
        :return: True if min-heap, False if max-heap
        """
        return self._is_min

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   Modify below this line
    def __len__(self) -> int:
        """
        Returns number of elements in the priority Queue
        :param self: The Object itself
        :return: number of elements in the priority Queue
        """
        return len(self._data)

    def empty(self) -> bool:
        """
         Returns if the Queue is Empty or Not
        :param self: The Object itself
        :return: True if Empty else False
        """
        if len(self) == 0:
            return True
        return False

    def peek(self) -> PriorityNode:
        """
         Returns if the First Node in the Queue
        :param self: The Object itself
        :return: The first Node in the Queue
        """
        if len(self) == 0:
            return None
        return self._data[0]

    def get_left_child_index(self, index: int) -> int:
        """
         Returns the index number of left child
        :param self: The Object itself
        :param index: The index of the Parent
        :return int: The index of the left child if available else None
        """
        outindex = (2 * index) + 1
        if outindex < len(self):
            return outindex
        return None

    def get_right_child_index(self, index: int) -> int:
        """
        Returns the index number of right child
        :param self: The Object itself
        :param index: The index of the Parent
        :return int: The index of the right child if available else None
        """
        outindex = (2 * index) + 2
        if outindex < len(self):
            return outindex
        return None

    def get_parent_index(self, index: int) -> int:
        """
         Returns the index number of the Parent
        :param self: The Object itself
        :param index: The index of the Chile
        :return int: The index of the PArent if available else None
        """
        if index == 0:
            return None
        parent = (index - 1) // 2
        if parent < 0:
            parent = 0
        return parent

    def push(self, priority: Any, val: Any) -> None:
        """
         Add a Node in the queue
        :param self: The Object itself
        :param priority: Priority of the Node
        :param val: Value of the Node
        :return : None
        """
        if self.is_min_heap():
            node = MinNode(priority, val)
        else:
            node = MaxNode(priority, val)
        self._data.append(node)
        endindex = len(self._data) - 1
        self.percolate_up(endindex)

    def pop(self) -> PriorityNode:
        """
         Deletes and returns the Top Node
        :param self: The Object itself
        :return PriorityNode: Returns the Top Node
        """
        if len(self._data) > 0:
            self._data[0], self._data[-1] = self._data[-1], self._data[0]
            op = self._data.pop()
            self.percolate_down(0)
            return op
        return None

    def get_minmax_child_index(self, index: int) -> int:
        """
        Returns value of the min child
        :param self: The Object itself
        :param index: Index of the Parent
        :return int: index of the min child
        """
        loutindex = (2 * index) + 1
        if loutindex >= len(self):
            loutindex = None
        routindex = (2 * index) + 2
        if routindex >= len(self):
            routindex = None
        if loutindex is None:
            return routindex
        elif routindex is None:
            return loutindex
        else:
            if self._data[routindex] < self._data[loutindex]:
                return routindex
            return loutindex

    def percolate_up(self, index: int) -> None:
        """
        Performs Percolate up operation on Queue for the given Node index
        :param self: The Object itself
        :param index: Index of the Node on which operation needs to be performed
        :return: None
        """
        parent = self.get_parent_index(index)
        if parent is None:
            # print("Parent None")
            return
        # print("Parent", self._data[parent])
        if self._data[index] < self._data[parent]:
            self._data[index], self._data[parent] = \
                self._data[parent], self._data[index]
            self.percolate_up(parent)
        else:
            return

    def percolate_down(self, index: int) -> None:
        """
        Performs Percolate down operation on Queue for the given Node index
        :param self: The Object itself
        :param index: Index of the Node on which operation needs to be performed
        :return: None
        """
        parent = index
        left = self.get_left_child_index(index)
        right = self.get_right_child_index(index)
        if left is not None:
            small_child = left
            if right is not None:
                if self._data[right] < self._data[left]:
                    small_child = right
            if self._data[small_child] < self._data[parent]:
                self._data[small_child], self._data[parent] = \
                    self._data[parent], self._data[small_child]
                self.percolate_down(small_child)


class MaxHeap:
    """
    Implementation of a max-heap - the highest value is at the front (root).

    Initializes a PriorityQueue with is_min set to False.

    Uses the priority queue to satisfy the min heap properties by initializing
    the priority queue as a max-heap, and then using value as both the priority
    and value.
    """

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   DO NOT MODIFY the following attributes/functions
    #   Modify only below indicated line

    __slots__ = ['_pqueue']

    def __init__(self):
        """
        Constructs a priority queue as a max-heap
        """
        self._pqueue = PriorityQueue(False)

    def __str__(self) -> str:
        """
        Represents the max-heap as a string
        :return: string representation of the heap
        """
        # NOTE: This hides implementation details
        return F"MaxHeap [{', '.join(item.value for item in self._pqueue._data)}]"

    __repr__ = __str__

    def to_tree_str(self) -> str:
        """
        Generates string representation of heap in Breadth First Ordering Format
        :return: String to print
        """
        return self._pqueue.to_tree_str()

    def __len__(self) -> int:
        """
        Determine the amount of nodes on the heap
        :return: Length of the data inside the heap
        """
        return len(self._pqueue)

    def empty(self) -> bool:
        """
        Checks if the heap is empty
        :returns: True if empty, else False
        """
        return self._pqueue.empty()

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   Modify below this line
    def peek(self) -> Any:
        """
        Returns if the value of First Node in the Heap
        :param self: The Object itself
        :return Any: The value of first Node in the Queue
        """
        return self._pqueue.peek().value


    def push(self, val: Any) -> None:
        """
        Add a Max Heap Node in the Heap
        :param self: The Object itself
        :param val: Value and Priority of the Node
        :return : None
        """
        self._pqueue.push(val, val)


    def pop(self) -> Any:
        """
        Deletes and returns the value of Top Node in Heap
        :param self: The Object itself
        :return Any: Returns the value of the Top Node in Heap
        """
        output = self._pqueue.pop()
        if output is not None:
            return output.value
        return None


class MinHeap(MaxHeap):
    """
    Implementation of a max-heap - the highest value is at the front (root).

    Initializes a PriorityQueue with is_min set to True.

    Inherits from MaxHeap because it uses the same exact functions, but instead
    has a priority queue with a min-heap.
    """

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   DO NOT MODIFY the following attributes/functions
    __slots__ = []

    def __init__(self):
        """
        Constructs a priority queue as a min-heap
        """
        super().__init__()
        self._pqueue._is_min = True


def heap_sort(array: List[Any]) -> None:
    """
    Sorts the Input List using Heap (MaxHeap)
    :param array: The input array which needs to be sorted
    :return : None
    """
    maxh = MaxHeap()
    for i in array:
        maxh.push(i)
    for i in range(len(maxh)):
        array[-i - 1] = maxh.pop()

def current_medians(array: List[int]) -> List[int]:
    """
    Takes an array as input and send a list of current medians by utilising
    any of PriorityQueue, MaxHeap or MinHeap
    :param array: The input array whose current Medians needs to be calculated
    :return List: List of all the Current Medians of thr given input List
    """
    output = list()
    templist = list()
    maxh = MaxHeap()
    for element in array:
        maxh.push(element)
        templist.append(maxh.peek())
        if templist[len(templist)-1] != element:
            templist[len(templist)-1] = element
            templist.sort()
        if len(templist) % 2 != 0:
            index = int(len(templist) / 2)
            output.append(templist[index])
        else:
            index = int(len(templist) / 2) - 1
            output.append((templist[index] + templist[index+1])/2)
    return output
