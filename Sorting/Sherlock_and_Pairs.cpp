#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
	long long N, count, temp;
	cin >> T;
	for (int j = T; j > 0; j--)
	{
		cin >> N;
		int ar[1000007] = {0};
		count = 0;
		for (long long i = 0; i < N; i++)
		{
			cin >> temp;
			ar[temp] += 1;
		}
		for (long long i = 1; i <= 1000000; i++)
		{
			if (ar[i] >= 2)
			{
				count += (long long)ar[i] * (long long)(ar[i]-1);		
			}
		}
		cout << count << endl;
		
	}
    return 0;
}
