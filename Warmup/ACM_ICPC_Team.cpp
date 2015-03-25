#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculate_combined_knowledge(string p1, string p2)
{
    int combined_knowledge = 0;
    for (int i = 0; i < p1.length(); i++)
    {
        if (p1[i] == '1' || p2[i] == '1')
            combined_knowledge++;
    }
    return combined_knowledge;
}

int calculate_max_knowledge(string k[], int n, int m, int* teams)
{
    int smartest_teams = 0;
    int j = 0;
    int most_topics = 0;
    
    for (int i = 0; i < n; i++)
    {
        j = n-1;
        while(j > i)
        {
            int combined_knowledge = calculate_combined_knowledge(k[i], k[j]);
            if (combined_knowledge == most_topics)
            {
                smartest_teams++;    
            }
            if (combined_knowledge > most_topics)
            {
                most_topics = combined_knowledge;
                smartest_teams = 1;
            }
            j--;
            //cout << "adding i[" << i << "]: " << k[i] << " and j[" << j << "]: ";
            //cout << k[j] << " = " << combined_knowledge << endl;
        }
    } 
    *teams = smartest_teams;
    return most_topics;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M;
    int max_topics, max_teams;
    cin >> N >> M;    
    string topics[N];
    for (int i=0; i<N; i++)
        cin >> topics[i];
    
    max_topics = calculate_max_knowledge(topics, N, M, &max_teams);
    
    cout << max_topics << endl;
    cout << max_teams << endl;
    return 0;
}
