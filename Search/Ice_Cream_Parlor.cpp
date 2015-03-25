#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void icecream_parlor(vector <int> & v, int dollars, int &one, int &two)
{
    one = 0;
    two = 0;
    int spent_idx = 0;
    int spent = v[spent_idx];
    for (int i = 0; i < v.size(); i++)
    {
        spent = v[i];
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[j] + spent == dollars)
            {
                one = i+1;
                two = j+1;
                break;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, M, N, r;
    cin >> T;
    vector <int> v;
    int first, second;
    for (int i = 0; i < T; i++)
    {
        v.clear();
        cin >> M >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> r;
            v.push_back(r);
        }
        first = 0;
        second = 0;
        icecream_parlor(v, M, first, second);
        cout << first << " " << second << endl;
    }
    return 0;
}
