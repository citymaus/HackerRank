#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string is_fibo(unsigned long long orig, unsigned long long fib1, unsigned long long fib2)
{
    unsigned long long fib3 = fib1 + fib2;
    if ((orig == fib3) || (orig == fib1) || (orig == fib2))
    {
        return "IsFibo";    
    }
    else
    {
        if (fib3 < orig)
        {
            return is_fibo(orig, fib2, fib3);
        }
        else
        {
            return "IsNotFibo";            
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int TC;
    unsigned long long num;
    string fibo;
    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        cin >> num;
        fibo = is_fibo(num, 0, 1);
        cout << fibo << endl;
    }
    return 0;
}
