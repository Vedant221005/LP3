
import heapq
from collections import Counter
from itertools import count


# Node class
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None


# Huffman Encoding class
class HuffmanEncoding:

    def __init__(self, text):
        self.text = text
        self.heap = []
        self.codes = {}
        self.unique = count()

    # Step 1: Calculate character frequencies
    def calculateFrequency(self):

        frequency = Counter(self.text)

        for char, freq in frequency.items():
            node = Node(char, freq)

            heapq.heappush(
                self.heap,
                (freq, next(self.unique), node)
            )

    # Step 2: Build Huffman Tree using Min Heap
    def buildTree(self):

        while len(self.heap) > 1:

            freq1, _, left = heapq.heappop(self.heap)
            freq2, _, right = heapq.heappop(self.heap)

            newNode = Node(None, freq1 + freq2)

            newNode.left = left
            newNode.right = right

            heapq.heappush(
                self.heap,
                (newNode.freq, next(self.unique), newNode)
            )

        return self.heap[0][2]

    # Step 3: Generate Huffman Codes
    def generateCodes(self, root, code=""):

        if root is None:
            return

        # Leaf node
        if root.left is None and root.right is None:

            self.codes[root.char] = code if code else "0"
            return

        self.generateCodes(root.left, code + "0")
        self.generateCodes(root.right, code + "1")

    # Step 4: Display Huffman Codes
    def displayCodes(self):

        print("\nCharacter | Huffman Code")
        print("-------------------------")

        for char, code in sorted(self.codes.items()):
            print(f"    {char}     |    {code}")

    # Main function
    def encode(self):

        if not self.text:
            print("Input string is empty!")
            return

        self.calculateFrequency()

        root = self.buildTree()

        self.generateCodes(root)

        self.displayCodes()


# Main program
text = input("Enter string: ")

huffman = HuffmanEncoding(text)
huffman.encode()
