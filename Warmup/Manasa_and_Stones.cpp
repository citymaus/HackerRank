#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

set<int> s;

void guess_stone(int num_stones, int a, int b)
{
    if (num_stones == 1)
    {
        cout << 0 << endl;    
    }
    else
    {
        s.clear();
		for (int i = 0; i <= num_stones - 1; i++)
		{
			int val = a * i + b * (num_stones - 1 - i);
			s.insert(val);
		}
		for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
			cout << *it << " ";
		cout << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, n, a, b;
    string result;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        cin >> n;
        cin >> a;
        cin >> b;
        guess_stone(n, a, b);
    }
    return 0;
}
