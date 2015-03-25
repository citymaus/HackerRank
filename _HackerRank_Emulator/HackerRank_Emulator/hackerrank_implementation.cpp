#include "hackerrank_implementation.h"

string Implementation::cavity_map(string prev_row, string curr_row, string next_row)
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
                cout << endl << curr_row[i] << " > " << prev_row[i] << " & " << next_row[i];
                cout << " & " << curr_row[i-1] << " & " << curr_row[i + 1] << endl;
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