#include <iostream>
using namespace std;
// Recursive Function
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
// Non-Recursive Function
int fibonacciIterative(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "\nFibonacci Series (Non-Recursive): ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciIterative(i) << " ";
    }
    cout << "\nFibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
    return 0;
}
