#include <iostream>
using namespace std;
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[n], profit[n];
    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++)
        cin >> profit[i];
    cout << "Enter knapsack capacity: ";
    cin >> W;
    int dp[n + 1][W + 1];
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "\nMaximum Profit = " << dp[n][W];
    return 0;
}
