"""
Varuntej Kodandapuram
Coding Challenge 7
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from __future__ import annotations  # allow self-reference
from typing import List, Optional

class TreeNode:
    """Tree Node that contains a value as well as left and right pointers"""
    def __init__(self, val: int, left: TreeNode = None, right: TreeNode = None):
        self.val = val
        self.left = left
        self.right = right

def rewind_combo(points: List[int]) -> List[Optional[int]]:
    """
    Perform the operation to calculate the output list
        :param points: List of points
        :return: List: A list as per te required condition
    """
    def insert(root, value) -> TreeNode:
        """
        Perform the operation to add new data in our BST
            :param root: The root of the BST where the data addition should start
            :param value: Value to be added
            :return: TreeNode: Returns root node of Tree
        """
        current = root
        parent = None
        if root is None:
            return TreeNode(value)
        while current:
            parent = current
            if value < current.val:
                current = current.left
            else:
                current = current.right
        if value < parent.val:
            parent.left = TreeNode(value)
        else:
            parent.right = TreeNode(value)
        return root
    def search(root, value) -> (int, int):
        """
        Perform the operation to search a data in our BST
            :param root: The root of the BST where the data addition should start
            :param value: Value to be searched
            :return: int: value of parent Node
            :return: int: Type/ Relation of/ with Node
        """
        current = root
        parent = None
        while current and current.val != value:
            parent = current
            if value < current.val:
                current = current.left
            else:
                current = current.right
        if current is None:
            return None, None
        if parent is None:
            return value, 1
        elif value < parent.val:
            return parent.val, 2
        else:
            return parent.val, 3
    root = None
    oplist = list()
    for value in points:
        root = insert(root, value)
        rroot = root
        kkey = value
        while True:
            kout, rout = search(rroot, kkey)
            if rout == 1:
                oplist.append(None)
                break
            if rout == 3:
                oplist.append(kout)
                break
            if rout == 2:
                kkey = kout
            if rout is None:
                oplist.append(None)
                break
    return(oplist)
