#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int hackerrank_tweets(string s)
{
    int result = 0;
    bool matches;
    
    regex rx(".*(hackerrank)+.*", regex_constants::icase);
    
    matches = regex_match(s, rx);
    
    if (matches)
    {
        result = 1;    
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        getline(cin, s);
        total += hackerrank_tweets(s);
    }
    cout << total << endl;
    return 0;
}
