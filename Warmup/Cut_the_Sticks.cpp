#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cut_the_sticks(int sticks[], int num)
{
    int num_cut = 0;
    int min = 99999;
    for (int i = 0; i < num; i++)
    {
        if ((sticks[i] < min) && (sticks[i] > 0))
        {
            min = sticks[i];    
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (sticks[i] > 0)
        {
            sticks[i] = sticks[i] - min;
            num_cut++;
        }
        //cout << sticks[i];
    }
    //cout << endl;
    return num_cut;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, left;
    cin >> n;
    left = n;
    int initsticks[n];
    for (int i = 0; i < n; i++)
    {
        cin >> initsticks[i];
    }
    while (left > 0)
    {
        left = cut_the_sticks(initsticks, n);
        if (left > 0)
        {
            cout << left << endl;
        }
    }
    return 0;
}
