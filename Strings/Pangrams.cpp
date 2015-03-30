#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string pangrams(string s)
{
    int charcount = 0;
    int alphabet[26] = { 0 };
    string result = "not pangram";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int a_int = int('a');
    
    // Make sure count of each letter is used at least once, ignore spaces
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            int alpha_ind = int(s[i])-a_int;
            alphabet[alpha_ind]++; 
            //cout << "adding one to ind(" << alpha_ind << ") char:" << char(alpha_ind + a_int) << endl;
        }
    }
    
    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] >= 1)
        {
            charcount++;    
        }
    }
    if (charcount == 26)
        result = "pangram";
    
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string z, result;
    getline(cin, z);
    result = pangrams(z);
    cout << result << endl;
    return 0;
}
