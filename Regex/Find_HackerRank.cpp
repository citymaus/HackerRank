#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int find_hackerrank(string s)
{
    int result = -1;
    bool beginning, ending;
    
    regex beg("^(hackerrank)+[a-z\\s]*$");
    regex end("^[a-z\\s]*(hackerrank)+$");
    
    beginning = regex_match(s, beg);
    ending = regex_match(s, end);
    
    if (beginning && ending)
    {
        result = 0;    
    }
    else if (beginning)
    {
        result = 1;    
    }
    else if (ending)
    {
        result = 2;    
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
        int r = find_hackerrank(s);
        cout << r << endl;
    }
    return 0;
}
