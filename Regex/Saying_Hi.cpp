#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int saying_hi(string s)
{
    int result = 0;
    bool matches;
    
    regex rx("^(hi\\s)+([^d][a-z]*)*$", regex_constants::icase);
    smatch match;
    
    matches = regex_match(s, match, rx);
    //matches = regex_search(s, match, rx);
    if (matches)
    {
        result = 1;
        cout << s << endl;
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    int r = 0;
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        r += saying_hi(s);
    }
    //cout << r << endl;
    return 0;
}
