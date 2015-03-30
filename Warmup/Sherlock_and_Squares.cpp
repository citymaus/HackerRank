#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long find_squares(unsigned long low, unsigned long high)
{
    unsigned long num_squares = 0;
    unsigned long lowest_square = floor(sqrt(low));
    unsigned long highest_square = floor(sqrt(high));
    //cout << "lowest: " << sqrt(low) << ", highest: " << sqrt(high) << endl;
    //cout << "lowest square: " << lowest_square << ", highest square: " << highest_square << endl;
    
    num_squares = highest_square - lowest_square + 1;
    if ((lowest_square * lowest_square) < low)
    {
        num_squares--;
    }
    if ((highest_square * highest_square) > high)
    {
        num_squares--;
    }
    return num_squares;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    unsigned long A, B, squares;
    cin >> T;
    for (int i=0; i<T; i++)
    {
        cin >> A >> B;
        squares = find_squares(A, B);
        cout << squares << endl;
    }
    return 0;
}
