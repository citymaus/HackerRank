#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string find_decent_number(long long n)
{
    string highest_num = "";
    if (n < 3)
    {
        return "-1";    
    }
    
    if (n % 3 == 0)
    {
        for (int j = 0; j < n; j++)
        {
            highest_num.append("5");
        }
    }
    else
    {
        int num_fives = 0;
        int num_threes = 0;
        
        int remainder = n;
        while ((remainder % 3 != 0) && (remainder >= 0))
        {
            remainder -= 5;
            num_threes++;
        }
        num_fives = (n - (num_threes*5)) / 3;
        //cout << "N=" << n << " num_5s=" << num_fives << " num_3s=" << num_threes << endl;;
        
        if ((num_fives*3 + num_threes*5 == n) && (num_fives >= 0))
        {
            for (int i = 0; i < num_fives; i++)
            {
                highest_num.append("555");
            }
            for (int j = 0; j < num_threes; j++)
            {
                highest_num.append("33333");    
            }
        }
        else
        {
            return "-1";
        }
    }
    
    return highest_num;
}
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T, N;
    cin >> T;
    string d;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        d = find_decent_number(N);
        cout << d << endl;
    }
    return 0;
}
