#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(vector <int> countme)
{
    int total_counts = 0;
    vector <int> counts(100, 0);
    for (int i = 0; i < countme.size(); i++)
    {
        counts[countme[i]]++;    
    }
    
    for (int i = 0; i < counts.size(); i++)
    {
        //cout << i << ": " << counts[i] << " " << endl;
        for (int j = 0; j < counts[i]; j++)
        {
            total_counts++;   
        }
        cout << total_counts << " ";
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, r;
    string s;
    vector <int> countme;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> r >> s;
        countme.push_back(r);
    }
    counting_sort(countme);
    return 0;
}
