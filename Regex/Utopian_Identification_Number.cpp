#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string utopian(string s)
{
    string result = "INVALID";
    bool matches;
    string X, Y;
    string valX, valY;
    
    //regex rx("^[]$", regex_constants::icase);
    regex rx("^[a-z]{0,3}[0-9]{2,8}[A-Z]{3,}$");
    smatch match;
    
    matches = regex_match(s, match, rx);
    //matches = regex_search(s, match, rx);
    if (matches)
    {
        result = "VALID";
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    string r = "";
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        r = utopian(s);
        cout << r << endl;
    }
    return 0;
}
