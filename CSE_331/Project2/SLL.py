"""
Project 2
CSE 331 S21 (Onsay)
Varuntej Kodandapuram
DLL.py
"""

from typing import TypeVar  # For use in type hinting
from Project2.Node import Node  # Import `Node` class

# Type Declarations
T = TypeVar('T')  # generic type
SLL = TypeVar('SLL')  # forward declared


class RecursiveSinglyLinkList:
    """
    Recursive implementation of an SLL
    """

    __slots__ = ['head']

    def __init__(self) -> None:
        """
        Initializes an `SLL`
        :return: None
        """
        self.head = None

    def __repr__(self) -> str:
        """
        Represents an `SLL` as a string
        """
        return self.to_string(self.head)

    def __str__(self) -> str:
        """
        Represents an `SLL` as a string
        """
        return self.to_string(self.head)

    def __eq__(self, other: SLL) -> bool:
        """
        Overloads `==` operator to compare SLLs
        :param other: right hand operand of `==`
        :return: `True` if equal, else `False`
        """
        comp = lambda n1, n2: n1 == n2 and (comp(n1.next, n2.next) if (n1 and n2) else True)
        return comp(self.head, other.head)

    # ============ Modify below ============ #

    def to_string(self, curr: Node) -> str:
        """
        Recursive Method to convert Sll into string showing all nodes starting from curr node
        :param curr: The node at which the sll starts
        :return: string representation of all nodes after curr node, including curr node
                returns "None" if curr node is None
        Time complexity: O(n^2)
        """
        if curr is None:
            return "None"
        res = str(curr.val)
        if curr.next is not None:
            res += " --> " + self.to_string(curr.next)
        return res

    def length(self, curr: Node) -> int:
        """
        Returns the length of sll starting at curr node
        :param curr: the node at which sll starts
        :return: the number of nodes after curr node, including curr node
                returns 0 if curr node is None
        Time complexity: O(n)
        """
        if curr is None:
            return 0
        return 1 + self.length(curr.next)

    def sum_list(self, curr: Node) -> T:
        """
        Returns the sum of all values in sll starting at curr node
        :param curr: the node at which sll starts
        :return: the sum of values of all nodes after curr node, including curr node
                returns 0 if curr node is None
        Time complexity: O(n)
        """
        if curr is None:
            return 0
        res = curr.val
        if curr.next is not None:
            res += self.sum_list(curr.next)
        return res

    def push(self, value: T) -> None:
        """
        Insert the given value into the linked list
        The value is inserted at the end of the list
        :param value: the value of node to be inserted
        :return: None
        Time complexity: O(n)
        """
        if self.head is None:
            self.head = Node(value)
            return

        def push_inner(curr: Node) -> None:
            """
            This is a helper function for push
            Inserts the given value (from push) into the linked list that has head curr
            The value is inserted at the end of the list
            :param curr: head of current linked list (assumed to be not None)
            :return: None
            Time complexity: O(n)
            """
            if curr.next is None:
                curr.next = Node(value)
            else:
                push_inner(curr.next)

        push_inner(self.head)

    def remove(self, value: T) -> None:
        """
        Removes the first node in the list with the given value.
        If the value doesn’t exist, does not change the linked list.
        :param value: the value of node to be removed
        :return: None
        Time complexity: O(n)
        """

        def remove_inner(curr: Node) -> Node:
            """
            This is a helper function for remove
            Removes the first node in the list with the given value
            (from remove) starting at head curr.
            If the value doesn’t exist, does not change the linked list.
            :param curr: the head node of current linked list
            :return: starting node(head) of resultant linked list
            Time complexity: O(n)
            """
            if curr is None:
                return None
            if curr.val == value:
                return curr.next
            curr.next = remove_inner(curr.next)
            return curr

        self.head = remove_inner(self.head)

    def remove_all(self, value: T) -> None:
        """
        Removes all nodes in the list with the given value.
        If the value doesn’t exist, does not change the linked list.
        :param value: value of nodes to be removed
        :return: None
        Time complexity: O(n)
        """

        def remove_all_inner(curr: Node) -> Node:
            """
            This is a helper function for remove_all.
            Removes all nodes in the list with the given value
            (from remove_all) starting at head curr.
            If the value doesn’t exist, does not change the linked list.
            :param curr: the head node of current linked list
            :return: starting node(head) of resultant linked list
            Time complexity: O(n)
            """
            if curr is None:
                return None
            curr.next = remove_all_inner(curr.next)
            if curr.val == value:
                return curr.next
            return curr

        self.head = remove_all_inner(self.head)

    def search(self, value: T) -> bool:
        """
        Looks for value in the list.
        :param value: value to be searched in linked list
        :return: True if the value is in the list ,
                False if it is not in the list
        Time complexity: O(n)
        """

        def search_inner(curr: Node) -> bool:
            """
            This is a helper function for search.
            Looks for value (from search) in the list starting with head curr.
            :param curr: the head node of current linked list
            :return: True if the value is in the list ,
                    False if it is not in the list
            Time complexity: O(n)
            """
            if curr is None:
                return False
            if curr.val == value:
                return True
            return search_inner(curr.next)

        return search_inner(self.head)

    def count(self, value: T) -> int:
        """
        Counts and returns how many times the given value occurs in the list.
        :param value: value whose frequency is be counted
        :return: number of occurrences of given value in linked list
        Time complexity: O(n)
        """

        def count_inner(curr: Node) -> int:
            """
            This is a helper function for count.
            Counts and returns how many times the given value
            (from count) occurs in the list starting at head curr.
            :param curr: the head node of current linked list
            :return: number of occurrences of given value in linked list
            Time complexity: O(n)
            """
            if curr is None:
                return 0
            count = count_inner(curr.next)
            if curr.val == value:
                count += 1
            return count

        return count_inner(self.head)

    def reverse(self, curr: Node) -> Node:
        """
        Given a list starting with head curr, reverse this list.
        Time complexity: O(n)
        :param curr: the head node of current linked list.
        :return: the head of the reversed list.
        """
        if curr is None:
            return None
        if curr.next is None:
            return curr
        self.head = self.reverse(curr.next)
        curr.next.next = curr
        curr.next = None
        return self.head


def crafting(recipe: RecursiveSinglyLinkList, pockets: RecursiveSinglyLinkList) -> bool:
    """
    Given two linked lists, recipe and pockets,
    determine if the values in the recipe list are contained in the
    pockets list. If all the values in recipe are present in pockets,
    they will be consumed, and therefore must be
    removed from pockets.
    :param recipe: recursive singly linked list with items required for crafting
    :param pockets: recursive singly linked list with items available in inventory
    :return:  True if the pockets contain enough ingredients to complete the recipe,
            False otherwise.
    Time complexity: O(rp)
    """
    if recipe.head is None:
        return False

    item = recipe.head.val
    if pockets.count(item) >= recipe.count(item):
        recipe.remove(item)
        if recipe.head is None or crafting(recipe, pockets):
            pockets.remove(item)
            return True
        return False
    else:
        return False
