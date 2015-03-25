#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string sherlock_and_array(int arr[], int n)
{
    int sumleft = 0;
    int sumright = 0;
    for (int j = 0; j < n; j++)
    {
        // Init right sum
        sumright += arr[j];    
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            sumleft += arr[i-1];
        }
        sumright -= arr[i];
        //cout << "i:" << i << " l:" << sumleft << " r:" << sumright << endl;
        if (sumleft == sumright)
        {
            return "YES";    
        }
    }
    return "NO";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N;
    string answer;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int sher[N];
        for (int j = 0; j < N; j++)
        {
            cin >> sher[j];
        }
        answer = sherlock_and_array(sher, N);
        cout << answer << endl;
    }
    return 0;
}
