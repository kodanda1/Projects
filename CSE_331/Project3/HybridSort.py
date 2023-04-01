"""
Name: Varuntej Kodandapuram
Project 3 - Hybrid Sorting
Developed by Sean Nguyen and Andrew Haas
Based on work by Zosha Korzecke and Olivia Mikola
CSE 331 Spring 2021
Professor Sebnem Onsay
"""
from typing import TypeVar, List, Callable
from math import sqrt

T = TypeVar("T")  # represents generic type


def merge_sort(data: List[T], threshold: int = 0,
               comparator: Callable[[T, T], bool] = lambda x, y: x <= y) -> int:
    """
    Given a list of values, performs a merge sort to sort the list
    and calculates the inversion count.
    When a threshold is provided, uses a merge sort algorithm
    until the partitioned lists are smaller than or equal to
    the threshold and then uses insertion sort.

    Time Complexity: O(nlog(n))

    Space Complexity: O(n)

    :param data: List of items to be sorted.
    :param threshold: int representing the size of the data at
                      which insertion sort should be used. Defaults to 0.
    :param comparator: A function, which takes an argument two objects
                       of like type to those in the list data and
            and returns `True` if the first argument is less than or
            equal to the second according to some ordering,
            else `False`.

    :return: int representing inversion count if threshold is 0, else 0

    """
    inv_count = 0
    if threshold > 0 and len(data) <= threshold:
        insertion_sort(data, comparator)

    elif len(data) > 1:
        mid = len(data) // 2
        left = data[:mid]
        right = data[mid:]

        inv_count += merge_sort(left, threshold, comparator)
        inv_count += merge_sort(right, threshold, comparator)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if comparator(left[i], right[j]):
                data[k] = left[i]
                i = i + 1
            else:
                data[k] = right[j]
                if threshold == 0:
                    inv_count += j + mid - k
                j = j + 1
            k = k + 1

        while i < len(left):
            data[k] = left[i]
            i = i + 1
            k = k + 1

        while j < len(right):
            data[k] = right[j]
            j = j + 1
            k = k + 1
    return inv_count


def insertion_sort(data: List[T], comparator: Callable[[T, T], bool] = lambda x, y: x <= y) -> None:
    """
    Given a list of values and comparator,
    performs an insertion sort on the list using the comparator.

    Time Complexity: O(n^2)

    Space Complexity: O(1)

    :param data: List of items to be sorted
    :param comparator:
        A function, which takes an argument two objects of the same type as those in the list
        Returns True if the first argument is less than or
        equal to the second according to some ordering,
        else False.
    :return: None
    """
    n = len(data)
    for i in range(1, n):
        ele = data[i]
        j = i
        while j > 0 and comparator(ele, data[j - 1]):
            data[j] = data[j - 1]
            j -= 1
        data[j] = ele


def hybrid_sort(data: List[T], threshold: int,
                comparator: Callable[[T, T], bool] = lambda x, y: x <= y) -> None:
    """
    Wrapper function that calls  merge_sort()  with provided threshold, and comparator function.

    Time Complexity: O(nlog(n))

    Space Complexity: O(n)

    :param data: List of items to be sorted.
    :param threshold: int representing the size of the data at which insertion sort should be used.
    :param comparator: A function, which takes an argument two objects
                       of like type to those in the list **data**
        and returns `True` if the first argument is less than or
        equal to the second according to some ordering,
        else `False`.
    :return: None
    """
    merge_sort(data, threshold, comparator)


def inversions_count(data: List[T]) -> int:
    """
    Wrapper function that calls merge_sort() on a copy of data to retrieve the inversion count.

    Time Complexity: O(nlog(n))

    Space Complexity: O(n)

    :param data: List of items to determine the inversion count of.
    :return: int representing inversion count.
    """
    return merge_sort(data.copy())


def reverse_sort(data: List[T], threshold: int) -> None:
    """
    Wrapper function that uses merge_sort() to sort the data in reverse.

    Time Complexity: O(nlog(n))

    Space Complexity: O(n)

    :param data: List of items to be sorted.
    :param threshold: int represnting the size of the data at which insertion sort should be used.
    :return: None
    """
    merge_sort(data, threshold, lambda x, y: x >= y)


def password_rate(password: str) -> float:
    """
    Rates a given password via the equation given in the problem statement

    Time Complexity: O(p*log(p)) - where p is the password length

    Space Complexity: O(p) - where p is the password length

    :param password: String of password
    :return: Rating of password (float)
    """
    pwd_len = len(password)
    unique_char_count = len(set(password))
    n_inversions = merge_sort(list(password))
    return sqrt(pwd_len) * sqrt(unique_char_count) + n_inversions


def password_sort(data: List[str]) -> None:
    """
    Sort a list of passwords by their ratings (the results from `password_rate()`) in reverse order

    Time Complexity: O(n*p*log(p) + n*log(n))

    Space Complexity: O(n)

    :param data: List of passwords
    :return: None
    """
    password_rates = {password: password_rate(password) for password in data}
    merge_sort(data, comparator=lambda pw1, pw2: password_rates[pw1] >= password_rates[pw2])
