"""
Varuntej Kodandapuram
Coding Challenge 2
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from typing import List, Tuple
from CC2.linked_list import DLLNode, LinkedList


def pokemon_machine(pokemon: LinkedList, orders: List[Tuple]) -> LinkedList:
    """
    Returns the pokemon Linked list after performing all operations mentioned in orders list
    :param pokemon: Double Linked List with pokemon names
    :param orders: Orders List where each order is a tuple in which,
                    the first element is a string denoting the operation to be performed and
                    the remaining elements are inputs required for operation
    :return: Double linked list with pokemon names
    """

    def add_pokemon(cur_node: DLLNode, added_pokemon: str) -> None:
        """
        Adds a node before the current node.
        :param cur_node: The node before which new node must be added
        :param added_pokemon: the value of new node (pokemon name)
        :return: None
        """
        if cur_node is None:
            new_node = DLLNode(added_pokemon, prev=pokemon.tail)
            pokemon.tail.nxt = new_node
            pokemon.tail = new_node
        else:
            new_node = DLLNode(added_pokemon, prev=cur_node.prev, nxt=cur_node)
            cur_node.prev.nxt = new_node
            cur_node.prev = new_node

    def remove_pokemon(cur_node: DLLNode) -> None:
        """
        Removes the cur_node from pokemon linked list
        :param cur_node: The node to be deleted
        :return: None
        """
        if cur_node.nxt is not None:
            cur_node.nxt.prev = cur_node.prev
        else:
            pokemon.tail = cur_node.prev
        cur_node.prev.nxt = cur_node.nxt

    def swap_pokemon(first_node: DLLNode, second_node: DLLNode) -> None:
        """
        Swaps the values of given two nodes
        :param first_node: first node to be swapped
        :param second_node: second node to be swapped
        :return:
        """
        first_node.val, second_node.val = second_node.val, first_node.val

    def get_node(target_index: int, cur_index: int, cur_node: DLLNode) -> DLLNode:
        """
        moves to specified index of pokemon linked list
        :param cur_node: the node at current
        :param cur_index: index of current node in pokemon Linked List
        :param target_index: the index of node in pokemon linked list
        :return: the node at given index
        """
        if target_index < cur_index:
            while target_index != cur_index:
                cur_node = cur_node.prev
                cur_index -= 1
        elif target_index > cur_index:
            while target_index != cur_index:
                cur_node = cur_node.nxt
                cur_index += 1
        return cur_node

    index = 0
    node = pokemon.head.nxt

    for order in orders:
        if order[0] == "add":
            at_index, pokemon_name = order[1], order[2]
            node = get_node(at_index, index, node)
            add_pokemon(node, pokemon_name)
            if node is None:
                node = pokemon.tail
                index = at_index
            else:
                index = at_index + 1

        elif order[0] == "remove":
            at_index = order[1]
            node = get_node(at_index, index, node)
            node = node.prev
            remove_pokemon(node.nxt)
            index = at_index - 1

        elif order[0] == "swap":
            at_index1, at_index2 = order[1], order[2]
            node1 = get_node(at_index1, index, node)
            node2 = get_node(at_index2, index, node)
            swap_pokemon(node1, node2)
            index, node = at_index1, node1

    return pokemon

