from typing import List


class Node():
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def construct_binary_tree(nodeList: List[int], root: Node, i: int, n: int) -> Node:
    if i < n:
        root = Node(nodeList[i])

        root.left = construct_binary_tree(nodeList, root.left, 2*i+1, n)
        root.right = construct_binary_tree(nodeList, root.right, 2*i+2, n)

    return root


def inorder(root: Node):
    if root is None:
        return

    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)


def preorder(root: Node):

    if root is None:
        return

    print(root.data, end=' ')
    preorder(root.left)
    preorder(root.right)


def postorder(root: Node):
    if root is None:
        return

    postorder(root.left)
    postorder(root.right)
    print(root.data, end=' ')


if __name__ == "__main__":
    nodeList = [0, 1, 2, 3, 4, 5, 6]
    root = None
    root = construct_binary_tree(nodeList, root, 0, len(nodeList))

    inorder(root)

    print('\n')

    preorder(root)

    print('\n')

    postorder(root)
