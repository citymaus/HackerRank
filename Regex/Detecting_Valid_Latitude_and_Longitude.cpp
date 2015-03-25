#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string val_ok(string s, double min, double max);

string val_ok(string s, double min, double max)
{
    string valid = "Invalid";
    //cout << s << " min:" << min << endl;
    double val = stod(s);
    
    if (val >= min && val <=max)
    {
        valid = "Valid";    
    }
    return valid;
}

string split_number(string s)
{
    string result = "Invalid";
    bool matches;
    string X, Y;
    string valX, valY;
    
    regex rx("^\\(([-+]?[1-9]{1}[0-9]*(\\.?[0-9]+)*){1},{1}\\s{1}([-+]?[1-9]{1}[0-9]*(\\.?[0-9]+)*){1}\\)$", regex_constants::icase);
    smatch match;
    
    matches = regex_match(s, match, rx);
    //matches = regex_search(s, match, rx);
    if (match.size() > 1)
    {
        X = match.str(1);
        Y = match.str(3);
        valX = val_ok(X, -90, 90);
        valY = val_ok(Y, -180, 180);
    
        result = "X=" + match.str(1) + "(" + valX + ")" + ",Y=" + match.str(2) + "(" + valY + ")";
        //cout << result << endl;
        if ((valX == "Valid") && (valY == "Valid"))
        {
            result = "Valid";
        }
        else
        {
            result = "Invalid";    
        }
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
        r = split_number(s);
        cout << r << endl;
    }
    return 0;
}
