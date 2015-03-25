#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string language(string s)
{
    string result = "INVALID";
    bool matches;
    string X, Y;
    string valX, valY;
    
    regex rx("^[0-9]{5,6}\\s(C|CPP|JAVA|PYTHON|PERL|PHP|RUBY|CSHARP|HASKELL|CLOJURE|BASH|SCALA|ERLANG|CLISP|LUA|BRAINFUCK|JAVASCRIPT|GO|D|OCAML|R|PASCAL|SBCL|DART|GROOVY|OBJECTIVEC)$", regex_constants::icase);
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
        r = language(s);
        cout << r << endl;
    }
    return 0;
}
