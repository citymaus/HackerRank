#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(vector <int> countme)
{
    vector <int> counts(100, 0);
    for (int i = 0; i < countme.size(); i++)
    {
        counts[countme[i]]++;    
    }
    
    for (int i = 0; i < counts.size(); i++)
    {
        //cout << i << ": " << counts[i] << " " << endl;    
        //cout << counts[i] << " ";
        for (int j = 0; j < counts[i]; j++)
        {
            cout << i << " ";    
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, r;
    vector <int> countme;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> r;
        countme.push_back(r);
    }
    counting_sort(countme);
    return 0;
}
