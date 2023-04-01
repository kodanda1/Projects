"""
Project 6
CSE 331 S21 (Onsay)
Varuntej Kodandapuram
hashtable.py
"""

from typing import TypeVar, List, Tuple

T = TypeVar("T")
HashNode = TypeVar("HashNode")
HashTable = TypeVar("HashTable")


class HashNode:
    """
    DO NOT EDIT
    """
    __slots__ = ["key", "value", "deleted"]

    def __init__(self, key: str, value: T, deleted: bool = False) -> None:
        self.key = key
        self.value = value
        self.deleted = deleted

    def __str__(self) -> str:
        return f"HashNode({self.key}, {self.value})"

    __repr__ = __str__

    def __eq__(self, other: HashNode) -> bool:
        return self.key == other.key and self.value == other.value

    def __iadd__(self, other: T) -> None:
        self.value += other


class HashTable:
    """
    Hash Table Class
    """
    __slots__ = ['capacity', 'size', 'table', 'prime_index']

    primes = (
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
        89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
        181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
        281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
        397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
        503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
        619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739,
        743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859,
        863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991,
        997)

    def __init__(self, capacity: int = 8) -> None:
        """
        DO NOT EDIT
        Initializes hash table
        :param capacity: capacity of the hash table
        """
        self.capacity = capacity
        self.size = 0
        self.table = [None] * capacity

        i = 0
        while HashTable.primes[i] <= self.capacity:
            i += 1
        self.prime_index = i - 1

    def __eq__(self, other: HashTable) -> bool:
        """
        DO NOT EDIT
        Equality operator
        :param other: other hash table we are comparing with this one
        :return: bool if equal or not
        """
        if self.capacity != other.capacity or self.size != other.size:
            return False
        for i in range(self.capacity):
            if self.table[i] != other.table[i]:
                return False
        return True

    def __str__(self) -> str:
        """
        DO NOT EDIT
        Represents the table as a string
        :return: string representation of the hash table
        """
        represent = ""
        bin_no = 0
        for item in self.table:
            represent += "[" + str(bin_no) + "]: " + str(item) + '\n'
            bin_no += 1
        return represent

    __repr__ = __str__

    def _hash_1(self, key: str) -> int:
        """
        ---DO NOT EDIT---
        Converts a string x into a bin number for our hash table
        :param key: key to be hashed
        :return: bin number to insert hash item at in our table, None if key is an empty string
        """
        if not key:
            return None
        hashed_value = 0

        for char in key:
            hashed_value = 181 * hashed_value + ord(char)
        return hashed_value % self.capacity

    def _hash_2(self, key: str) -> int:
        """
        ---DO NOT EDIT---
        Converts a string x into a hash
        :param key: key to be hashed
        :return: a hashed value
        """
        if not key:
            return None
        hashed_value = 0

        for char in key:
            hashed_value = 181 * hashed_value + ord(char)

        prime = HashTable.primes[self.prime_index]

        hashed_value = prime - (hashed_value % prime)
        if hashed_value % 2 == 0:
            hashed_value += 1
        return hashed_value

    def __len__(self) -> int:
        """
        Function to return length of the table
        :param self: denotes the address of object itself
        :return: integer which is size of the list
        """
        return self.size

    def __setitem__(self, key: str, value: T) -> None:
        """
        Function to set/ insert item in the table
        :param self: denotes the address of object itself
        :param key: key whose data needs to be added
        :param value: value for the key
        :return: None
        """
        self._insert(key, value)

    def __getitem__(self, key: str) -> T:
        """
        Function to check if key is available in table and return its value
        :param self: denotes the address of object itself
        :param key: key whose data needs to be returned
        :return: value of the key or raise KeyError
        """
        output = self._get(key)
        if output is not None:
            return output.value
        raise KeyError

    def __delitem__(self, key: str) -> None:
        """
        Function to delete data if key is available in table
        :param self: denotes the address of object itself
        :param key: key whose data needs to be deleted
        :return: None
        """
        output = self._get(key)
        if output is not None:
            self._delete(key)
            return
        raise KeyError

    def __contains__(self, key: str) -> bool:
        """
        Function to check if key is available in table
        :param self: denotes the address of object itself
        :param key: key whose data needs to be added
        :return: bool True if value exists else False
        """
        output = self._get(key)
        if output is not None:
            return True
        return False

    def hash(self, key: str, inserting: bool = False) -> int:
        """
        Function to calculate the hash
        :param self: denotes the address of object itself
        :param key: key whose data needs to be added
        :param inserting: where the key needs to be inserted or not
        :return: index value based on hashes
        """
        hash1 = self._hash_1(key)
        hash2 = self._hash_2(key)
        for ind in range(len(self.table)):
            if isinstance(self.table[ind], HashNode):  # IF key exists
                if self.table[ind].key == key and not self.table[ind].deleted:
                    return ind
        if inserting:
            bool2, bool3 = False, False
            try:
                bool2 = self.table[hash1].key is None
                bool3 = self.table[hash1].key != key and self.table[hash1].value is None
            except:
                pass
            if self.table[hash1] is None:
                self.table[hash1] = HashNode(key, None)
                return hash1
            if bool2 or bool3:
                self.table[hash1].key = key
                return hash1
            hashx = hash1
            while True:
                hashx += hash2
                hashx = hashx % self.capacity
                bool1 = self.table[hashx] is None
                bool2 = False
                try:
                    bool2 = self.table[hashx].key is None or self.table[hashx].value is None
                except:
                    pass
                if bool1 or bool2:
                    self.table[hashx] = HashNode(key, None)
                    return hashx
        if not inserting:
            if self.table[hash1] is None:
                return hash1
            hashx = hash1
            while True:
                hashx += hash2
                hashx = hashx % self.capacity
                bool1 = self.table[hashx] is None
                bool2 = False
                try:
                    bool2 = self.table[hashx].key is None or self.table[hashx].value is None
                except:
                    pass
                if bool1 or bool2:
                    return hashx


    def _insert(self, key: str, value: T) -> None:
        """
        Function to insert values in the HashTable
        :param self: denotes the address of object itself
        :param key: key whose data needs to be added
        :param value: value of the key
        :return: None
        """
        hash1 = self._hash_1(key)
        hash2 = self._hash_2(key)
        self._grow()

        for ind in range(len(self.table)):
            if isinstance(self.table[ind], HashNode):  # IF key exists
                if self.table[ind].key == key and not self.table[ind].deleted:
                    self.table[ind].value = value
                    return None

        if self.table[hash1] is None:
            self.table[hash1] = HashNode(key, value)
            self.size += 1
            self._grow()
            return None
        if self.table[hash1].key is None:
            self.table[hash1].key = key
            self.table[hash1].value = value
            self.table[hash1].deleted = False
            return None
        if self.table[hash1].key != key and self.table[hash1].value is None:
            self.table[hash1].key = key
            return None
        hashx = hash1
        while True:
            hashx += hash2
            hashx = hashx % self.capacity
            if self.table[hashx] is None:
                self.table[hashx] = HashNode(key, value)
                self.size += 1
                return None
            if self.table[hashx].key is None or self.table[hashx].value is None:
                self.table[hashx] = HashNode(key, value)
                return None


    def _get(self, key: str) -> HashNode:
        """
        Function to get value in table at given key
        :param self: denotes the address of object itself
        :param key: key whose data needs to be read
        :return: HashNode of the key
        """
        for ind in range(len(self.table)):
            if isinstance(self.table[ind], HashNode):  # IF key exists
                if self.table[ind].key == key and not self.table[ind].deleted:
                    return self.table[ind]
        return None

    def _delete(self, key: str) -> None:
        """
        Function to delete the data in table at given key
        :param self: denotes the address of object itself
        :param key: key where data needs to be deleted
        :return: None
        """
        for ind in range(len(self.table)):
            if isinstance(self.table[ind], HashNode):  # IF key exists
                if self.table[ind].key == key and not self.table[ind].deleted:
                    self.table[ind].key = None
                    self.table[ind].value = None
                    self.table[ind].deleted = True
                    self.size -= 1

    def _grow(self) -> None:
        """
        Function to grow the table
        :param self: denotes the address of object itself
        :return: None
        """
        if self.size >= (self.capacity/2):
            new = HashTable(self.capacity * 2)
            for ind in range(self.capacity):
                if self.table[ind] is None:
                    pass
                else:
                    new[self.table[ind].key] = self.table[ind].value
            self.table, self.capacity = new.table, new.capacity
            for num in range(len(HashTable.primes)-1):
                if HashTable.primes[num] < self.capacity:
                    self.prime_index = num
                else:
                    break

    def update(self, pairs: List[Tuple[str, T]] = []) -> None:
        """
        Function to update the table from given list of key and pair
        :param self: denotes the address of object itself
        :param pairs: list containing key and pairs
        :return: None
        """
        self._grow()
        for key, value in pairs:
            self._insert(key, value)

    def keys(self) -> List[str]:
        """
        Function to give a list of all keys
        :param self: denotes the address of object itself
        :return: list of all keys in table
        """
        output = list()
        for ind in self.table:
            if ind is not None:
                output.append(ind.key)
        return output


    def values(self) -> List[T]:
        """
        Function to give a list of all value
        :param self: denotes the address of object itself
        :return: list of all value in table
        """
        output = None
        for ind in self.table:
            if ind is not None:
                if output is None:
                    output = list()
                output.append(ind.value)
        return output


    def items(self) -> List[Tuple[str, T]]:
        """
        Function to give a list of all key and value pairs
        :param self: denotes the address of object itself
        :return: list of all key and value pairs
        """
        output = list()
        for ind in self.table:
            if ind is not None:
                output.append((ind.key, ind.value))
        return output


    def clear(self) -> None:
        """
        Function to clear the table data
        :param self: denotes the address of object itself
        :return: None
        """
        new = [None] * self.capacity
        self.table = new
        self.size = 0


class CataData:
    """
    CataData Class
    To calculate average time between Stations
    """
    def __init__(self) -> None:
        """
        CataData object initialization
        :param self: denotes the address of object itself
        :return: None
        """
        self.data = HashTable()
        self.rider = HashTable()

    def enter(self, idx: str, origin: str, time: int) -> None:
        """
        Function to process when a user takes the bus from origin
        :param idx: id of the user
        :param origin: origin station
        :param time: time when started from origin
        :return: None
        """
        self.rider[idx] = [origin, time]

    def exit(self, idx: str, dest: str, time: int) -> None:
        """
        Function to process when a user exits from destination
        :param idx: id of the user
        :param dest: destination station
        :param time: time when arrived to destination
        :return: None
        """
        if idx in self.rider.keys():
            if self.rider[idx][0] not in self.data.keys():
                self.data[self.rider[idx][0]] = HashTable()
            temp = self.data[self.rider[idx][0]]
            if dest in temp.keys():
                temp[dest].append(time - self.rider[idx][1])
            else:
                temp[dest] = list()
                temp[dest].append(time - self.rider[idx][1])

    def get_average(self, origin: str, dest: str) -> float:
        """
        :param origin: origin station
        :param dest: destination station
        :return: float value which denotes average time between origin to dest
        """
        if origin in self.data.keys():
            if dest in self.data[origin].keys():
                time = self.data[origin][dest]
                avg = 0
                for ind in time:
                    avg += ind
                return avg/len(time)
            return 0
        return 0


