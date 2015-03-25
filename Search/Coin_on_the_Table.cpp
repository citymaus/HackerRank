#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int M, N, K;
char table[52][52];
int flips[52][52][1001];

void coin_table(int x, int y, int nflips, int time)
{
    if ((x < 0) || (y < 0))     return;
    if ((x >= M) || (y >= N))   return;
    if (time > K)               return;
    
    if ((flips[x][y][time] == -1) || (nflips < flips[x][y][time]))
    {
        flips[x][y][time] = nflips;
    
        if (table[x][y] != '*') 
        {
            // Flips in every direction
            coin_table(x, y - 1, nflips + (table[x][y] != 'U'), time + 1);
            coin_table(x, y + 1, nflips + (table[x][y] != 'D'), time + 1);
            coin_table(x - 1, y, nflips + (table[x][y] != 'L'), time + 1);
            coin_table(x + 1, y, nflips + (table[x][y] != 'R'), time + 1);
        }
        else
        {
            coin_table(x, y, nflips, time + 1);   
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char r;
    int x, y;
    cin >> N >> M >> K;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> r;
            table[i][j] = r;
            if (r == '*')
            {
                x = i;
                y = j;
            }
        }
    }    
	memset(flips, -1, sizeof(flips));
    coin_table(0, 0, 0, 0);
    cout << flips[x][y][K] << endl;
    return 0;
}