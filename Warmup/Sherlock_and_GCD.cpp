#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int find_gcd(int a, int b);

bool find_denominator(int s[], int set_size)
{
    if (set_size < 2)
    {
        // Only one item in set
        return false;
    }
    
    int current_gcd = s[0];
    for (int i = 0; i < set_size; i++)
    {
        current_gcd = find_gcd(current_gcd, s[i]);
    }
    
    return (current_gcd < 2);
}

int find_gcd(int a, int b)
{
    while (b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, A;
    string p;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int s[N];
        for (int j = 0; j < N; j++)
        {
            cin >> s[j];
        }
        p = (find_denominator(s, N) ? "YES" : "NO");
        cout << p << endl;
    }
    return 0;
}
