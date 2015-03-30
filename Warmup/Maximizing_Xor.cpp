#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int xor_result, max_result;
    max_result = 0;
    for (int A = l; A <= r; A++)
    {
        for (int B = l; B <= r; B++)
        {
            xor_result = A ^ B;
            if (xor_result > max_result)
            {
                max_result = xor_result;   
            }
        }
    }
    return max_result;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
