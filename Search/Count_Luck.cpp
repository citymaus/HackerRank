#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
char forest[100][100] = {0};
int countwaves();
void printforest(int rows, int cols);
void printpossible(int possible, string dir);
int traverse(int rows, int cols, int x, int y, int moves, int waves, string dirs);
int route_moves = 0;
int startX = 0;
int startY = 0;
string alldirs = "";
 
int countwaves()
{
    int waves = 0;
    int x = startX;
    int y = startY;
    
    for (int i = 0; i < alldirs.length(); i++)
    {
        char nextdir = alldirs[i];
        if (forest[x][y] == 'w')
        {
            waves++; 
            //cout << "x:" << x << " y:" << y << " ?:" << forest[x][y] << " next:" << nextdir <<  " w's:" << waves << endl;   
        }
        switch (nextdir)
        {
            case 'U':
                y = y-1;
                break;
            case 'D':
                y = y+1;
                break;
            case 'L':
                x = x-1;
                break;
            case 'R':
                x = x+1;
                break;
        }
    }
 
    return waves;
}
 
void printforest(int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << forest[c][r];   
        }
        cout << endl;
    }
}
 
void printpossible(int possible, string dir)
{
    if (possible == 2)
    {
        //cout << "(WAVE NEEDED HERE)";   
    }
    //cout << " going " << dir << endl;
}
 
int traverse(int rows, int cols, int x, int y, int moves, int waves, string dirs)
{
    if ((x < 0) || (x >= cols) || (y < 0) || (y >= rows))     return waves;
   
    //cout << "x:" << x << " y:" << y << " = " << forest[x][y] << "  / waves(" << waves << ")" << endl;
   
    if (forest[x][y] == '*')   
    {
        alldirs = dirs;
        //cout << "PATH:" << dirs << endl;
        return waves;
    }
   
    // Mark current space as walked.
    forest[x][y] = 'n';
   
    int numpossible = 0;
    
    // Check up
    if (y-1 >= 0)
    {
        if ((forest[x][y-1] == '.') || (forest[x][y-1] == '*'))
        {
            numpossible++;
            printpossible(numpossible, "UP");
           
            waves = traverse(rows, cols, x, y-1, moves + 1, waves, dirs + "U");
        }
    }
    // Check down
    if (y+1 < rows)
    {
        if ((forest[x][y+1] == '.') || (forest[x][y+1] == '*'))
        {
            numpossible++;
            if (numpossible == 2)
            {
                // Mark current space as wand waved.
                forest[x][y] = 'w';
                route_moves = 0;         
            }
            printpossible(numpossible, "DOWN");
            waves = traverse(rows, cols, x, y+1, moves + 1, waves + (numpossible == 2), dirs + "D");
        }
    }
    // Check left
    if (x-1 >= 0)
    {
        if ((forest[x-1][y] == '.') || (forest[x-1][y] == '*'))
        {
            numpossible++;
            if (numpossible == 2)
            {
                // Mark current space as wand waved.
                forest[x][y] = 'w';
                route_moves = 0;          
            }
            printpossible(numpossible, "LEFT");
            waves = traverse(rows, cols, x-1, y, moves + 1, waves + (numpossible == 2), dirs + "L");
        }
    }
    // Check right
    if (x+1 < cols)
    {
        if ((forest[x+1][y] == '.') || (forest[x+1][y] == '*'))
        {
            numpossible++;
            if (numpossible == 2)
            {
                // Mark current space as wand waved.
                forest[x][y] = 'w';
                route_moves = 0;
            }
            printpossible(numpossible, "RIGHT");           
            waves = traverse(rows, cols, x+1, y, moves + 1, waves + (numpossible == 2), dirs + "R");
        }
    }
   
    // Nowhere to go, erase moves and waves taken down this path
    //cout << "TRAPPED at " << x << ", " << y << " waves: " << waves << " moves: " << moves << endl;
    moves = moves - route_moves;
    return waves;
   
}
 
string count_luck(int rows, int cols, int waves)
{
    int waves_needed = 0;
    bool foundhome = false;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (forest[c][r] == 'M')
            {
                startX = c;
                startY = r;
            }
        }
    }
   
    waves_needed = traverse(rows, cols, startX, startY, 0, 0, "");
    waves_needed = countwaves();
    //cout << "COUNTWAVES:" << waves_needed << endl;
   // cout << "WAVES MADE:" << waves_needed << " EXPECTED:" << waves << endl;
   
    if (waves_needed == waves)
    {
        return "Impressed";   
    }
    return "Oops!";
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T, ROWS, COLS, K;
    cin >> T;
    char item;
    string imp;
    for (int i = 0; i < T; i++)
    {
        cin >> ROWS >> COLS;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                cin >> item;
                forest[c][r] = item;
            }
        }
        cin >> K;
        imp = count_luck(ROWS, COLS, K);
        //cout << "FOREST " << i << endl;
        //printforest(ROWS, COLS);
        cout << imp << endl;
    }
    return 0;
}
 
 