#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int service_lane(int segs[], int i, int j)
{
    int vehicle = 3;
    for (int k = i; k <= j; k++)
    {
        if (segs[k] == 1)
            return 1;
        if (segs[k] < vehicle)
            vehicle = segs[k];
    }
    return vehicle;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, T;
    int i, j, vehicle;
    cin >> N >> T;
    int segments[N];
    for (int k = 0; k < N; k++)
    {
        cin >> segments[k];
    }
    for (int k = 0; k < T; k++)
    {
        cin >> i >> j;
        vehicle = service_lane(segments, i, j);
        cout << vehicle << endl;
    }
    return 0;
}
