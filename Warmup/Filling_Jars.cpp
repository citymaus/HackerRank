#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long play_jars(int start[], int finish[], int candies[], int num_jars, int num_ops)
{
    long long total_all_jars = 0;
    for (int i = 0; i < num_ops; i++)
    {
        total_all_jars += (finish[i] - start[i] + 1) * (long long) candies[i];    
    }    
    return floor(total_all_jars / num_jars);    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, M;
    long long avg;
    cin >> N >> M;
    int a[M], b[M], k[M];
    for (int i=0; i<M; i++)
        cin >> a[i] >> b[i] >> k[i];
    
    avg = play_jars(a, b, k, N, M);
    
    cout << avg << endl;
    
    return 0;
}
