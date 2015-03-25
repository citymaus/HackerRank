#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string valid_pan_format(string s)
{
    string result = "NO";
    bool matches;
    
    regex beg("^[A-Z]{5}[0-9]{4}[A-Z]$");
    
    matches = regex_match(s, beg);
    
    if (matches && (s.length() == 10))
    {
        result = "YES";    
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        string r = valid_pan_format(s);
        cout << r << endl;
    }
    return 0;
}
