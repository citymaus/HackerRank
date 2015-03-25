#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string split_number(string s)
{
    string result = "";
    bool matches;
    
    regex rx("([0-9]{1,3})[\\s|-]+([0-9]{1,3})[\\s|-]+([0-9]{4,10})", regex_constants::icase);
    smatch match;
    
    matches = regex_search(s, match, rx);
    
    result = "CountryCode=" + match.str(1) + ",LocalAreaCode=" + match.str(2) +
            ",Number=" + match.str(3);
    
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
        r = split_number(s);
        cout << r << endl;
    }
    return 0;
}
