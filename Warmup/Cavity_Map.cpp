#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string cavity_map(string prev_row, string curr_row, string next_row)
{
    string outrow = "";
    for (int i = 0; i < curr_row.length(); i++)
    {
        if ((i == 0) || (i + 1 == curr_row.length()))
        {
            // Not a cavity
            outrow += curr_row[i];    
        }
        else if (((int)curr_row[i]) > ((int)prev_row[i]) && (((int)curr_row[i]) > ((int)next_row[i])))
        {
            if ((((int)curr_row[i]) > ((int)curr_row[i-1])) && (((int)curr_row[i]) > ((int)curr_row[i + 1])))
            {          
                // Found a cavity
                outrow += "X";  
            }
            else
            {
                // Not a cavity
                outrow += curr_row[i];                      
            }
        }
        else
        {
            // Not a cavity
            outrow += curr_row[i];            
        }
    }
    return outrow;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string row;
    cin >> n;
    string outrow[n];
    for (int i = 0; i < n; i++)
    {
        cin >> outrow[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ((i == 0) || (i + 1 == n))
        {
            // First or Last row
            cout << outrow[i] << endl;
        }
        else
        {
            // Potential cavities
            row = cavity_map(outrow[i-1], outrow[i], outrow[i+1]);
            cout << row << endl;
        }
    }
    return 0;
}
