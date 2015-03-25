#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_row(vector <char> & v);
void print_row(vector <char> & v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];    
    }
    cout << endl;
}

string encryption(string str)
{
    string truncstr = "";
    string encrstr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            truncstr = truncstr + str[i];
        }
    }
    int newlength = truncstr.length();
    int cols = ceil(sqrt(newlength));
    int rows = ceil((double)newlength / (double)cols);
    //cout << newlength << " -> cols:" << cols << " rows:" << rows << endl;
    //cout << truncstr << endl;
    
 /*   vector <char> row;
    int r = 0;
    for (int i = 0; i < rows; i++)
    {
        row.clear();
        for (int j = 0; j < cols; j++)
        {
            r = i*cols + j;
            if (r < newlength)
            {
                row.push_back(truncstr[r]);
            }
        }
        //cout << "row" << i << ":";
        //print_row(row);
    }
    */
    
    for (int cidx = 0; cidx < cols; cidx++)
    {
	   for (int ridx = 0; ridx < rows; ridx++)
	   {
          int k = ridx*cols + cidx;
          if (k < newlength)
          {
		      encrstr = encrstr + truncstr[k];
              //encrstr = encrstr + to_string(k) + ",";
          }
	   }
	   encrstr = encrstr + " ";
    }
    
    return encrstr;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s, sout;
    getline(cin, s);
    sout = encryption(s);
    cout << sout << endl;
    return 0;
}
