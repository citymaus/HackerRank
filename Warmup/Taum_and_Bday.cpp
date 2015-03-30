#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long taum_and_bday(unsigned long long black_wanted, unsigned long long white_wanted, unsigned long long black_cost, unsigned long long white_cost, unsigned long long conv_cost)
{
    unsigned long long b_cost, w_cost;
    b_cost = black_cost;
    w_cost = white_cost;
    if (black_cost < white_cost)
    {
        if ((black_cost + conv_cost) < white_cost)
        {
            w_cost = black_cost + conv_cost;
        }
    }
    else
    {
        if ((white_cost + conv_cost) < black_cost)
        {
            b_cost = white_cost + conv_cost;
        }
        
    }
    return (black_wanted * b_cost) + (white_wanted * w_cost);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long T, B, W, X, Y, Z, spend;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> B >> W;
        cin >> X >> Y >> Z;
        spend = taum_and_bday(B, W, X, Y, Z);
        cout << spend << endl;
    }
    return 0;
}
