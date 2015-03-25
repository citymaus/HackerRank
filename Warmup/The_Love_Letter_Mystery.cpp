#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int palindromize(string s)
{
    unsigned int changes = 0;
    unsigned int halfsize, foot_idx;
    string head, foot;
    if (s.length() % 2 == 0)
    {   // Even number string
        halfsize = s.length()/2;
        head.append(s, 0, halfsize);
        foot.append(s, halfsize, halfsize);
    }
    else
    {   // Odd number string
        halfsize = (s.length() - 1)/2;
        head.append(s, 0, halfsize);
        foot.append(s, halfsize + 1, halfsize);        
    }
    for (int i = 0; i < halfsize; i++)
    {
        foot_idx = foot.length() - 1 - i;
        if (head[i] > foot[foot_idx])
        {
            changes += head[i] - foot[foot_idx];
        }
        if (head[i] < foot[foot_idx])
        {
            changes += foot[foot_idx] - head[i];
        }
    }
    return changes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string input;
    unsigned int opers;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> input;
        opers = palindromize(input);
        cout << opers << endl;
    }
    return 0;
}
