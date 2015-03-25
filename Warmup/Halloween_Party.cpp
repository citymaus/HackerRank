#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long cut_pieces(int cuts)
{
    unsigned long long pieces = 0;
    if (cuts % 2 == 0)
    {
        //cout << cuts << " even " << (cuts / 2) << endl;
        pieces = ((unsigned long long) cuts / (unsigned long long) 2) * ((unsigned long long) cuts / (unsigned long long) 2);
    }
    else 
    {
        //cout << cuts << " odd " << (cuts / 2) + 1 << " : " << (cuts / 2) << endl;
        pieces = (((unsigned long long) cuts / (unsigned long long) 2) + (unsigned long long) 1) * ((unsigned long long) cuts / (unsigned long long) 2);        
    }
    return pieces;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, K;
    unsigned long long pieces;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        cin >> K;
        pieces = cut_pieces(K);
        cout << pieces << endl;
    }    
    return 0;
}
