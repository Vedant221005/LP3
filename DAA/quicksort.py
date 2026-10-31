
import random

# Deterministic Quick Sort
def deterministicQuickSort(arr):

    if len(arr) <= 1:
        return arr

    pivot = arr[-1]

    left = []
    right = []

    for i in arr[:-1]:
        if i <= pivot:
            left.append(i)
        else:
            right.append(i)

    return deterministicQuickSort(left) + [pivot] + deterministicQuickSort(right)


# Randomized Quick Sort
def randomizedQuickSort(arr):

    if len(arr) <= 1:
        return arr

    # Select random pivot
    pivotIndex = random.randint(0, len(arr) - 1)
    pivot = arr[pivotIndex]

    left = []
    right = []

    for i in range(len(arr)):
        if i == pivotIndex:
            continue

        if arr[i] <= pivot:
            left.append(arr[i])
        else:
            right.append(arr[i])

    return randomizedQuickSort(left) + [pivot] + randomizedQuickSort(right)


# Main program
n = int(input("Enter number of elements: "))

arr = list(map(int, input("Enter elements: ").split()))

if len(arr) != n:
    print("Please enter exactly", n, "elements.")
else:
    print("\nOriginal Array:", arr)

    result1 = deterministicQuickSort(arr.copy())
    print("Deterministic Quick Sort:", result1)

    result2 = randomizedQuickSort(arr.copy())
    print("Randomized Quick Sort:", result2)
