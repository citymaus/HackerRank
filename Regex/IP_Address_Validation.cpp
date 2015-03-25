#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

bool checkdigits(string s, int min, int max, int base);
bool checkdigits(string s, int min, int max, int base)
{   
    unsigned long val = strtoul(s.c_str(), NULL, base);
    if (val >= min && val <=max)
    {
        return true;    
    }
    return false;
}

string ip_addr(string s)
{
    string result = "Neither";
    string A, B, C, D, E, F, G, H;
    regex rfour("^([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)$");
    regex rsix("^([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+):([0-9A-Fa-f]+)$");
    bool matches;
    smatch match;
        
    if(regex_match(s, match, rfour))
    {
        A = match.str(1);
        B = match.str(2);
        C = match.str(3);
        D = match.str(4);
        //cout << "A:" << A << " B:" << B << " C:" << C << " D:" << D << endl;
        if(checkdigits(A, 0, 255, 10) &&
           checkdigits(B, 0, 255, 10) &&
           checkdigits(C, 0, 255, 10) && 
           checkdigits(D, 0, 255, 10))
        {
            result = "IPv4";
        }
    }
    if(regex_match(s, match, rsix))
    {
        A = match.str(1);
        B = match.str(2);
        C = match.str(3);
        D = match.str(4);
        E = match.str(5);
        F = match.str(6);
        G = match.str(7);
        H = match.str(8);
        //cout << "A:" << A << " B:" << B << " C:" << C << " D:" << D << endl;
        if(checkdigits(A, 0, 0xFFFF, 16) &&
           checkdigits(B, 0, 0xFFFF, 16) &&
           checkdigits(C, 0, 0xFFFF, 16) && 
           checkdigits(D, 0, 0xFFFF, 16) && 
           checkdigits(E, 0, 0xFFFF, 16) && 
           checkdigits(F, 0, 0xFFFF, 16) && 
           checkdigits(G, 0, 0xFFFF, 16) && 
           checkdigits(H, 0, 0xFFFF, 16))
        {
            result = "IPv6";   
        }
    }
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    string s, result;
    cin >> T;
    getline(cin, s);
    for (int i = 0; i < T; i++)
    {
        getline(cin, s);
        result = ip_addr(s);
        cout << result << endl;
    }
    return 0;
}
