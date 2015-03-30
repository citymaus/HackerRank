#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int modify_string(string s)
{
    int deletions = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] == s[i+1])
        {
            deletions++;    
        }
    }
    return deletions;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, deletions;
    string input;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> input;
        deletions = modify_string(input);
        cout << deletions << endl;
    }
    return 0;
}
