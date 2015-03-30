#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int find_digits(string s)
{
    int num_divisors = 0;
    int dividend = atoi(s.c_str());
    int divisor = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        divisor = (int)(s[i] - '0');
        if (divisor > 0)
        {
            //cout << dividend << " % " <<  divisor << " = " << (dividend %  divisor) << endl;
            if (dividend %  divisor == 0)
            {
                num_divisors++;    
            }
        }
    }
    
    return num_divisors;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, divisors;
    string digits;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> digits;
        divisors = find_digits(digits);
        cout << divisors << endl;
    }
    return 0;
}
