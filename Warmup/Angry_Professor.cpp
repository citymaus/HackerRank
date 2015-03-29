#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int students[1001];

string angry_professor(int n, int k)
{
    string cancel = "NO";
    int ontime = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i] <= 0)
        {
            ontime++;    
        }
    }
    if (ontime < k)
    {
        cancel = "YES";    
    }
    
    return cancel;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, K, time;
    string cancelled;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;
        memset(students, 0, sizeof(students));
        for (int i = 0; i < N; i++)
        {
            cin >> time;
            students[i] = time;    
        }
        cancelled = angry_professor(N, K);
        cout << cancelled << endl;
    }
    return 0;
}
