"""
Project 5
CSE 331 S21 (Onsay)
Your Name
AVLTree.py
"""

import queue
from typing import TypeVar, Generator, List, Tuple

# for more information on typehinting, check out https://docs.python.org/3/library/typing.html
T = TypeVar("T")  # represents generic type
Node = TypeVar("Node")  # represents a Node object (forward-declare to use in Node __init__)
AVLWrappedDictionary = TypeVar("AVLWrappedDictionary")#represents a custom type used in application


####################################################################################################


class Node:
    """
    Implementation of an AVL tree node.
    Do not modify.
    """
    # preallocate storage: see https://stackoverflow.com/questions/472000/usage-of-slots
    __slots__ = ["value", "parent", "left", "right", "height"]

    def __init__(self, value: T, parent: Node = None,
                 left: Node = None, right: Node = None) -> None:
        """
        Construct an AVL tree node.

        :param value: value held by the node object
        :param parent: ref to parent node of which this node is a child
        :param left: ref to left child node of this node
        :param right: ref to right child node of this node
        """
        self.value = value
        self.parent, self.left, self.right = parent, left, right
        self.height = 0

    def __repr__(self) -> str:
        """
        Represent the AVL tree node as a string.

        :return: string representation of the node.
        """
        return f"<{str(self.value)}>"

    def __str__(self) -> str:
        """
        Represent the AVL tree node as a string.

        :return: string representation of the node.
        """
        return f"<{str(self.value)}>"


####################################################################################################


class AVLTree:
    """
    Implementation of an AVL tree.
    Modify only below indicated line.
    """
    # preallocate storage: see https://stackoverflow.com/questions/472000/usage-of-slots
    __slots__ = ["origin", "size"]

    def __init__(self) -> None:
        """
        Construct an empty AVL tree.
        """
        self.origin = None
        self.size = 0

    def __repr__(self) -> str:
        """
        Represent the AVL tree as a string. Inspired by Anna De Biasi (Fall'20 Lead TA).

        :return: string representation of the AVL tree
        """
        if self.origin is None:
            return "Empty AVL Tree"

        # initialize helpers for tree traversal
        root = self.origin
        result = ""
        q = queue.SimpleQueue()
        levels = {}
        q.put((root, 0, root.parent))
        for i in range(self.origin.height + 1):
            levels[i] = []

        # traverse tree to get node representations
        while not q.empty():
            node, level, parent = q.get()
            if level > self.origin.height:
                break
            levels[level].append((node, level, parent))

            if node is None:
                q.put((None, level + 1, None))
                q.put((None, level + 1, None))
                continue

            if node.left:
                q.put((node.left, level + 1, node))
            else:
                q.put((None, level + 1, None))

            if node.right:
                q.put((node.right, level + 1, node))
            else:
                q.put((None, level + 1, None))

        # construct tree using traversal
        spaces = pow(2, self.origin.height) * 12
        result += "\n"
        result += f"AVL Tree: size = {self.size}, height = {self.origin.height}".center(spaces)
        result += "\n\n"
        for i in range(self.origin.height + 1):
            result += f"Level {i}: "
            for node, level, parent in levels[i]:
                level = pow(2, i)
                space = int(round(spaces / level))
                if node is None:
                    result += " " * space
                    continue
                if not isinstance(self.origin.value, AVLWrappedDictionary):
                    result += f"{node} ({parent} {node.height})".center(space, " ")
                else:
                    result += f"{node}".center(space, " ")
            result += "\n"
        return result

    def __str__(self) -> str:
        """
        Represent the AVL tree as a string. Inspired by Anna De Biasi (Fall'20 Lead TA).

        :return: string representation of the AVL tree
        """
        return repr(self)

    def height(self, root: Node) -> int:
        """
        Return height of a subtree in the AVL tree, properly handling the case of root = None.
        Recall that the height of an empty subtree is -1.

        :param root: root node of subtree to be measured
        :return: height of subtree rooted at `root` parameter
        """
        if self.origin is None:
            return -1
        return root.height if root is not None else -1

    def left_rotate(self, root: Node) -> Node:
        """
        Perform a left rotation on the subtree rooted at `root`. Return new subtree root.
        :param root: root node of unbalanced subtree to be rotated.
        :return: new root node of subtree following rotation.
        """
        # print('Left Rotate Called', root)
        if root is None:
            return None
        # pull right child up and shift right-left child across tree, update parent
        new_root, rl_child = root.right, root.right.left
        root.right = rl_child
        if rl_child is not None:
            rl_child.parent = root

        # right child has been pulled up to new root -> push old root down left, update parent
        new_root.left = root
        new_root.parent = root.parent
        if root.parent is not None:
            if root is root.parent.left:
                root.parent.left = new_root
            else:
                root.parent.right = new_root
        root.parent = new_root

        # handle tree origin case
        if root is self.origin:
            self.origin = new_root

        # update heights and return new root of subtree
        root.height = 1 + max(self.height(root.left), self.height(root.right))
        new_root.height = 1 + max(self.height(new_root.left), self.height(new_root.right))
        return new_root

    ########################################
    # Implement functions below this line. #
    ########################################

    def right_rotate(self, root: Node) -> Node:
        """
        Perform a right rotation on the subtree rooted at `root`. Return new subtree root.
        :param root: root node of unbalanced subtree to be rotated.
        :return: new root node of subtree following rotation.
        """
        if root is None:
            return None
        # pull right child up and shift right-left child across tree, update parent
        new_root, rl_child = root.left, root.left.right
        root.left = rl_child
        if rl_child is not None:
            rl_child.parent = root
        # right child has been pulled up to new root -> push old root down left, update parent
        new_root.right = root
        new_root.parent = root.parent
        if root.parent is not None:
            if root is root.parent.right:
                root.parent.right = new_root
            else:
                root.parent.left = new_root
        root.parent = new_root
        # handle tree origin case
        if root is self.origin:
            self.origin = new_root
        # update heights and return new root of subtree
        root.height = 1 + max(self.height(root.right), self.height(root.left))
        new_root.height = 1 + max(self.height(new_root.right), self.height(new_root.left))
        return new_root

    def balance_factor(self, root: Node) -> int:
        """
        Perform a balance check and returns the balance factor.
        :param root: root node of which balance factor is to be calculated.
        :return: Balance Factor value.
        """
        if root is None:
            return 0
        return self.height(root.left) - self.height(root.right)

    def rebalance(self, root: Node) -> Node:
        """
        Perform rebalance to the Tree if needed.
        :param root: root node of unbalanced subtree to be balanced.
        :return: new root node of subtree after balance.
        """
        if root is None:
            return None
        balance = self.balance_factor(root)
        if balance > 1:
            if self.balance_factor(root.left) < 0:  # L-R
                root.left = self.left_rotate(root.left)
                return self.right_rotate(root)
            return self.right_rotate(root)
        elif balance < -1:
            if self.balance_factor(root.right) > 0:  # R-L
                root.right = self.right_rotate(root.right)
                return self.left_rotate(root)
            return self.left_rotate(root)
        return root  # no need to rebalance

    def insert(self, root: Node, val: T) -> Node:
        """
        Perform a insertion operation in the Tree.
        :param root: root node of Tree in which new data is to be inserted.
        :param val: value to be inserted.
        :return: new root node of subtree following insertion.
        """
        if self.origin is None:
            root = Node(val, root)
            self.size += 1
            self.origin = root
            return root

        if root.left is not None and root.right is not None:
            rheight = root.height
            rlheight = root.left.height
            rrheight = root.right.height
            if root.parent is None and (rheight - rlheight > 1 or rheight - rrheight > 1):
                root.height -= 1
        if val > root.value:
            if root.right is None:
                if root.left is None:
                    root.height += 1
                root.right = Node(val, root)
                self.size += 1
                return root.right
            else:
                self.insert(root.right, val)
                root = self.rebalance(root)
                root.height = max(self.height(root.left), self.height(root.right)) + 1
        elif val < root.value:
            if root.left is None:
                if root.right is None:
                    root.height += 1
                root.left = Node(val, root)
                self.size += 1
                return root.left
            self.insert(root.left, val)
            root = self.rebalance(root)
            root.height = max(self.height(root.left), self.height(root.right)) + 1
        else:
            pass
        return self.rebalance(self.origin)

    def min(self, root: Node) -> Node:
        """
        Search and Return the node with minimum value.

        :param root: root node of Tree in which Value is to be search.
        :return: Node where min value is found.
        """
        if root is None:
            return None
        if root.left is None:
            return root
        root = self.min(root.left)
        return root

    def max(self, root: Node) -> Node:
        """
        Search and Return the node with maximum value.

        :param root: root node of Tree in which Value is to be search.
        :return: Node where max value is found.
        """
        if root is None:
            return None
        if root.right is None:
            return root
        root = self.max(root.right)
        return root

    def search(self, root: Node, val: T) -> Node:
        """
        Perform Search to the Tree.

        :param root: root node of Tree in which Value is to be search.
        :param val: Value to be searched.
        :return: Node where value is found.
        """
        if root is None:
            return root
        if root.value == val:
            return root
        elif val < root.value:
            if root.left is None:
                return root
            root = self.search(root.left, val)
        else:
            if root.right is None:
                return root
            root = self.search(root.right, val)
        return root
    def inorder(self, root: Node) -> Generator[Node, None, None]:
        """
        Perform a In Order Transversal to the Tree.
        :param root: root node of Tree in which Transversal is to be done.
        :return: Generator Object of the Transversed Tree.
        """
        if root is None or self.origin is None:
            return StopIteration
        yield from self.inorder(root.left)
        yield root
        yield from self.inorder(root.right)
    def preorder(self, root: Node) -> Generator[Node, None, None]:
        """
        Perform a Pre Order Transversal to the Tree.
        :param root: root node of Tree in which Transversal is to be done.
        :return: Generator Object of the Transversed Tree.
        """
        if root is None or self.origin is None:
            return StopIteration
        yield root
        yield from self.preorder(root.left)
        yield from self.preorder(root.right)
    def postorder(self, root: Node) -> Generator[Node, None, None]:
        """
        Perform a Post Order Transversal to the Tree.
        :param root: root node of Tree in which Transversal is to be done.
        :return: Generator Object of the Transversed Tree.
        """
        if root is None or self.origin is None:
            return StopIteration
        yield from self.postorder(root.left)
        yield from self.postorder(root.right)
        yield root
    def levelorder(self, root: Node) -> Generator[Node, None, None]:
        """
        Perform a Level Order Transversal to the Tree.
        :param root: root node of Tree in which Transversal is to be done.
        :return: Generator Object of the Transversed Tree.
        """
        if root is None or self.origin is None:
            return None
        def printgivenlevel(root, level):
            if root is None:
                return StopIteration
            if level == 1:
                yield root
            elif level > 1:
                yield from printgivenlevel(root.left, level - 1)
                yield from printgivenlevel(root.right, level - 1)
        heit = root.height
        for i in range(0, heit + 2):
            yield from printgivenlevel(root, i)

    def remove(self, root: Node, val: T) -> Node:
        """
        Perform a removal operation in the Tree.
        :param root: root node of Tree in which removal is to be done.
        :param val: value to be removed.
        :return: new root node of subtree following removal.
        """
        if root is None:
            return None
        if val < root.value:
            self.remove(root.left, val)
        elif val > root.value:
            self.remove(root.right, val)
        elif val == root.value:
            self.size -= 1
            if root.left is not None and root.right is not None:
                rheight = root.height
                rlheight = root.left.height
                rrheight = root.right.height
                if root.parent is None and (rheight - rlheight > 1 or rheight - rrheight > 1):
                    root.height -= 1
                if root.left is not None:
                    if root.left.left is None:
                        temp = self.max(root.left)
                        root.value = temp.value
                        if temp.parent.right.value == temp.value:
                            temp.parent.right = None
                            if self.origin.left is not None:
                                soll = self.origin.left.left
                                if soll is None and self.origin.left.right is None:
                                    self.origin.left.height -= 1
                        elif temp.parent.left.value == temp.value:
                            temp.parent.left = None
                            sorg = self.origin
                            if sorg.right.right is not None and sorg.right.right.right is None:
                                self.origin.right.height = 1
                    else:
                        root.value = root.left.value
                        root.left = root.left.left
            elif root.left is not None and root.right is None:
                root.value = root.left.value
                root.left = root.left.left
                root.height -= 1
            elif root.left is None and root.right is not None:
                root.value = root.right.value
                root.right = root.right.left
                root.height -= 1
            elif root.left is None and root.right is None:
                if root.parent.left is not None:
                    if root.value == root.parent.left.value:
                        root.parent.left = None
                        root.height -= 1
                if root.parent.right is not None:
                    if root.value == root.parent.right.value:
                        root.parent.right = None
                        root.height -= 1
        return self.rebalance(self.origin)
        #################################################################################
class AVLWrappedDictionary:
    """
    Implementation of a helper class which will be used as tree node values in the
    NearestNeighborClassifier implementation. Compares objects with keys less than
    1e-6 apart as equal.
    """
    # preallocate storage: see https://stackoverflow.com/questions/472000/usage-of-slots
    __slots__ = ["key", "dictionary"]

    def __init__(self, key: float) -> None:
        """
        Construct a AVLWrappedDictionary with a key to search/sort on and
        a dictionary to hold data.
        :param key: floating point key to be looked up by.
        """
        self.key = key
        self.dictionary = {}

    def __repr__(self) -> str:
        """
        Represent the AVLWrappedDictionary as a string.
        :return: string representation of the AVLWrappedDictionary.
        """
        return f"key: {self.key}, dict: {self.dictionary}"

    def __str__(self) -> str:
        """
        Represent the AVLWrappedDictionary as a string.
        :return: string representation of the AVLWrappedDictionary.
        """
        return f"key: {self.key}, dict: {self.dictionary}"

    def __eq__(self, other: AVLWrappedDictionary) -> bool:
        """
        Implement == operator to compare 2 AVLWrappedDictionaries by key only.
        Compares objects with keys less than 1e-6 apart as equal.
        :param other: other AVLWrappedDictionary to compare with
        :return: boolean indicating whether keys of AVLWrappedDictionaries are equal
        """
        return abs(self.key - other.key) < 1e-6

    def __lt__(self, other: AVLWrappedDictionary) -> bool:
        """
        Implement < operator to compare 2 AVLWrapped Dictionarys by key only.
        Compares objects with keys less than 1e-6 apart as equal.
        :param other: other AVLWrappedDictionary to compare with
        :return: boolean indicating ordering of AVLWrappedDictionaries
        """
        return self.key < other.key and not abs(self.key - other.key) < 1e-6

    def __gt__(self, other: AVLWrappedDictionary) -> bool:
        """
        Implement > operator to compare 2 AVLWrappedDictionaries by key only.
        Compares objects with keys less than 1e-6 apart as equal.
        :param other: other AVLWrappedDictionary to compare with
        :return: boolean indicating ordering of AVLWrappedDictionaries
        """
        return self.key > other.key and not abs(self.key - other.key) < 1e-6


class NearestNeighborClassifier:
    """
    Implementation of a one-dimensional nearest-neighbor classifier with AVL tree lookups.
    Modify only below indicated line.
    """
    # preallocate storage: see https://stackoverflow.com/questions/472000/usage-of-slots
    __slots__ = ["resolution", "tree"]

    def __init__(self, resolution: int) -> None:
        """
        Construct a one-dimensional nearest neighbor classifier with AVL tree lookups.
        Data are assumed to be floating point values in the closed interval [0, 1].
        :param resolution: number of decimal places the data will be rounded to, effectively
                           governing the capacity of the model - for example, with a resolution of
                           1, the classifier could maintain up to 11 nodes, spaced 0.1 apart - with
                           a resolution of 2, the classifier could maintain 101 nodes, spaced 0.01
                           apart, and so on - the maximum number of nodes is bounded by
                           10^(resolution) + 1.
        """
        self.tree = AVLTree()
        self.resolution = resolution
        # pre-construct lookup tree with AVLWrappedDictionary objects storing (key, dictionary)
        # pairs, but which compare with <, >, == on key only
        for i in range(10 ** resolution + 1):
            w_dict = AVLWrappedDictionary(key=(i / 10 ** resolution))
            self.tree.insert(self.tree.origin, w_dict)

    def __repr__(self) -> str:
        """
        Represent the NearestNeighborClassifier as a string.
        :return: string representation of the NearestNeighborClassifier.
        """
        return f"NNC(resolution={self.resolution}):\n{self.tree}"

    def __str__(self) -> str:
        """
        Represent the NearestNeighborClassifier as a string.
        :return: string representation of the NearestNeighborClassifier.
        """
        return f"NNC(resolution={self.resolution}):\n{self.tree}"

    def fit(self, data: List[Tuple[float, str]]) -> None:
        """
        Perform Data Fitting Operation on the AVL Tree.
        :param data: Data which needs to be fitted in Tree.
        :return: Node where the Data was inserted.
        """
        for i in data:
            a = AVLWrappedDictionary(round(i[0], self.resolution))
            node = self.tree.search(self.tree.origin, a)
            if i[1] not in node.value.dictionary.keys():
                node.value.dictionary[i[1]] = 1
            else:
                val = node.value.dictionary[i[1]] + 1
                node.value.dictionary[i[1]] = val

    def predict(self, x: float, delta: float) -> str:
        """
        Perform Prediction Operation on the AVL Tree.
        :param x: Data which needs to be predicted in Tree.
        :param delta: Delta value range for prediction
        :return: str: label of predicted data.
        """
        yfirst = float(x)
        zfirst = float(x)
        increment = 1 / pow(10, self.resolution)
        while yfirst < x + delta + increment and zfirst > x - delta - increment:
            anode = AVLWrappedDictionary(round(zfirst, self.resolution))
            data1 = self.tree.search(self.tree.origin, anode).value.dictionary
            keys = list(data1.keys())
            if len(keys) == 1:
                return keys[0]
            elif len(keys) > 1:
                list1 = list(data1.keys())
                list1.sort(reverse=True)
                max_value_keys = [key for key in list1 if data1[key] == max(data1.values())]
                return max_value_keys[0]
            anode = AVLWrappedDictionary(round(yfirst, self.resolution))
            data1 = self.tree.search(self.tree.origin, anode).value.dictionary
            keys = list(data1.keys())
            if len(keys) == 1:
                return keys[0]
            elif len(keys) > 1:
                list2 = list(data1.keys())
                list2.sort()
                max_value_keys = [key for key in list2 if data1[key] == max(data1.values())]
                return max_value_keys[0]
            yfirst += increment
            zfirst -= increment

