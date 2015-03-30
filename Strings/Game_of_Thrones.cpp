#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int check_palindromeness(string s)
{
    int num_odd_counts = 0;
    int alphabet[26] = { 0 };
    int ok_palindrome = 1;
    int a_int = int('a');
    
    // Make sure count of each letter is even
    // One odd count is ok, can be middle of palindrome
    for (int i = 0; i < s.length(); i++)
    {
        int alpha_ind = int(s[i])-a_int;
        alphabet[alpha_ind]++; 
        //cout << "adding one to ind(" << alpha_ind << ") char:" << char(alpha_ind + a_int) << endl;
    }
    
    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] % 2 == 1)
        {
            num_odd_counts++;    
        }
    }
    if (num_odd_counts > 1)
        ok_palindrome = 0;
    return ok_palindrome;
}

int main() {
   
    string s;
    cin>>s;
     
    int flag = check_palindromeness(s);
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
