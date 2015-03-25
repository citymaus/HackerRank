#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int flip_bits(unsigned int unflipped)
{
    unsigned int flipped;
    unsigned int bits[32];
    unsigned int mask, currbit;
    flipped = 0;
    for (int shift = 0; shift < 32; shift++)
    {
        mask = 0x1 << shift;
        currbit = (unflipped & mask) >> shift;
        flipped |= !currbit << shift;
    }
    
    return flipped;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    unsigned int unflipped, flipped;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> unflipped;
        flipped = flip_bits(unflipped);
        cout << flipped << endl;
    }
    
    return 0;
}
