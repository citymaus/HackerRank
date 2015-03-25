#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string missing_numbers(vector <int> & A, vector <int> & B)
{
    string missing = "";
    int min = 100001;
    int max = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] < min)
        {
            min = B[i];    
        }
        if (B[i] > max)
        {
            max = B[i];    
        }
    }
    int countsB[100] = {0};
    int countsA[100] = {0};
    
    for (int i = 0; i < B.size(); i++)
    {
        countsB[B[i]-min]++;
        if (i < A.size())
        {
            countsA[A[i]-min]++;
        }
    }
    
    for (int j = 0; j < 100; j++)
    {
        //cout << (j+min) << " CountsA:" << countsA[j] << " CountsB:" << countsB[j] << endl;
        if (countsA[j] != countsB[j])
        {
            //cout << "can't find " << (j + min) << endl;    
            missing = missing + to_string(j + min) + " ";
        }
    }
    
    return missing;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int M, N;
    int r;
    cin >> M;
    vector <int> a;
    vector <int> b;
    string missing;
    for (int i = 0; i < M; i++)
    {
        cin >> r;
        a.push_back(r);
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> r;
        b.push_back(r);
    }
    missing = missing_numbers(a, b);
    cout << missing << endl;
    return 0;
}
