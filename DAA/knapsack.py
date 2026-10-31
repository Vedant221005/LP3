
n = int(input("Enter number of items: "))

weight = list(map(int, input("Enter weights: ").split()))
profit = list(map(int, input("Enter profits: ").split()))

W = int(input("Enter knapsack capacity: "))

# Create DP table
dp = [[0 for j in range(W + 1)] for i in range(n + 1)]

# Fill DP table
for i in range(1, n + 1):

    for w in range(1, W + 1):

        if weight[i - 1] <= w:

            dp[i][w] = max(
                dp[i - 1][w],
                profit[i - 1] + dp[i - 1][w - weight[i - 1]]
            )

        else:
            dp[i][w] = dp[i - 1][w]

# Display maximum profit
print("\nMaximum Profit =", dp[n][W])

# Find selected items
print("Selected Items:", end=" ")

w = W

for i in range(n, 0, -1):

    if dp[i][w] != dp[i - 1][w]:

        print(i, end=" ")
        w = w - weight[i - 1]

print()
