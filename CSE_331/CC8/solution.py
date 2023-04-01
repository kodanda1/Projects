"""
Varuntej Kodandapuram
Coding Challenge 8
CSE 331 Spring 2021
Professor Sebnem Onsay
"""

from typing import Set, Tuple, Dict
from CC8.InventoryItems import ItemInfo, ALL_ITEMS


class Bundle:
    """ Bundle Class """

    def __init__(self) -> None:
        """
        Initialization of the object of class Bundle
        :param self: Refers to the address of the object itself
        :return: None
        """
        self.data = dict()
        self.size = 0

    def to_set(self) -> Set[Tuple[str, int]]:
        """
        Conversion of the Dictionary Data to set of items with key value pair
        :param self: Refers to the address of the object itself
        :return: Set containing all the key value pairs as tuples
        """
        data = list(self.data.items())
        return set(data)

    def add_to_bundle(self, item_name: str, amount: int) -> bool:
        """
        Adding a new or updating an existing key in the data
        :param self: Refers to the address of the object itself
        :param item_name: Name of the object (Key) which needs to be added
        :param amount: Number of those items which needs to be added
        :return: bool True if item was added successfully else False
        """
        name = ALL_ITEMS[item_name].name
        space_per_unit = 64 / ALL_ITEMS[name].amount_in_stack
        if 64 - self.size >= amount * space_per_unit:
            self.size += amount * space_per_unit
            if name not in self.data.keys():
                self.data[name] = amount
            else:
                self.data[name] += amount
            return True
        return False

    def remove_from_bundle(self, item_name: str, amount: int) -> bool:
        """
        Removing an amount of items of given item_name
        :param self: Refers to the address of the object itself
        :param item_name: Name of the object (Key) which needs to be added
        :param amount: Number of those items which needs to be removed
        :return: bool True if item was removed successfully else False
        """
        name = ALL_ITEMS[item_name].name
        space_per_unit = 64 / ALL_ITEMS[name].amount_in_stack
        print(space_per_unit, amount)
        if name not in self.data.keys():
            return False
        if self.data[name] >= amount:
            self.data[name] -= amount
            if self.data[name] == 0:
                del self.data[name]
            self.size -= (space_per_unit * amount)
            return True
        return False
