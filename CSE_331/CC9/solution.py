"""
Name: Varuntej Kodandapuram
Coding Challenge 9
CSE 331 Spring 2021
Professor Sebnem Onsay
"""

from typing import List, Tuple


class Dungeon:
    """
    Represents a dungeon made of rooms connected by hallways
    Implemented as an adjacency matrix
    """

    __slots__ = ['adjacency_matrix']

    def __init__(self, rooms: List[int], hallways: List[Tuple[int, int]]) -> None:
        self.adjacency_matrix = [[0] * len(rooms) for _ in range(len(rooms))]
        for hall in hallways:
            self._add_connecting_hallway(*hall)

    def _add_connecting_hallway(self, start_room: int, end_room: int) -> None:
        """
        Adds a hallway to the dungeon
        :param start_room: start room
        :param end_room: end room
        :return: None
        """
        self.adjacency_matrix[start_room][end_room] = self.adjacency_matrix[end_room][start_room] = 1

    def get_connecting_rooms(self, current_room: int) -> List[int]:
        """
        Gets a list of rooms connected to the current room
        :param current_room: current room represented by an index in the matrix
        :return: List of connected, adjacent rooms
        """
        connecting_rooms = []
        for connected_room, required_stamina in enumerate(self.adjacency_matrix[current_room]):
            if required_stamina > 0:
                connecting_rooms.append(connected_room)
        return connecting_rooms

    def get_required_stamina(self, start_room: int, end_room: int) -> int:
        """
        Gets the required stamina between two edges
        :param start_room: First room at the end of a hallway
        :param end_room: Second room at the other end of a hallway
        :return: Stamina of hallway as an int
            will be 1 if the rooms are connected by a single hallway,
            0 if the rooms are not connected by a single hallway
        """
        return self.adjacency_matrix[start_room][end_room]


def dungeon_escape(dungeon: Dungeon, start_room: int, end_room: int,
                   stamina_limit: int) -> Tuple[List[int], int]:
    """
    Function to Calculate the Best Path of Travel.
    :param start_room: First room at the end of a hallway
    :param end_room: Second room at the other end of a hallway
    :param stamina_limit: Stamina limit for escaping
    :return: A Tuple containing the Best paths as first element
            Stamina used as second element
    """
    goflag = 1
    if len(dungeon.get_connecting_rooms(
            end_room)) == 0 or len(dungeon.get_connecting_rooms(
                start_room)) == 0 or stamina_limit <= 1:
        goflag = 0
    graph = dict()
    for key in range(len(dungeon.adjacency_matrix)):
        graph[key] = dungeon.get_connecting_rooms(key)
    def pathfinder(graph, start, end):
        visited = set()
        paths = [[start]]
        if start == end:
            return list()
        while paths:
            path = paths.pop(0)
            room = path[-1]
            if room not in visited:
                all_conn_rooms = graph[room]
                for conn_room in all_conn_rooms:
                    best_path = list(path)
                    best_path.append(conn_room)
                    paths.append(best_path)
                    if conn_room == end:
                        return best_path
                visited.add(room)
        return list()
    if goflag == 0:
        final_output = list()
    else:
        final_output = pathfinder(graph, start_room, end_room)
    stamina_used = len(final_output) - 1
    if stamina_used < 0:
        stamina_used = 0
    if stamina_used > stamina_limit:
        final_output = []
        stamina_used = 0
    return (final_output, stamina_used)
