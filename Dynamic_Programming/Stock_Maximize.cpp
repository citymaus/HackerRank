#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
using namespace std;

vector<bool> selldays;
long long pocket;
vector<int> shareprice;
int N;

void find_sell_days();
void calculate_profit();

void find_sell_days()
{
    long long max = LONG_MIN;    
    
    for (int i = N-1; i >= 0; i--)
    {
        if (max < shareprice[i])
        {
            max = shareprice[i];
            selldays[i] = true;
            //cout << "SELL TODAY " << i << endl;
        }
    }
}

void calculate_profit()
{
    long long shares = 0;
    for (int i = 0; i < N; i++)
    {
        if (!selldays[i])
        {
            // Buy today
            shares++;
            pocket -= shareprice[i];
            //cout << "BUY t:" << i << " s:" << shares << " $" << cost << endl;
        }
        else
        {
            if (shares > 0)
            {
                // Sell all today
                pocket += shares*shareprice[i];
            
                // Reset counter
                shares = 0;
                //cout << "SELL t:" << i << " s:" << shareprice[i] << " $" << profit << endl;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, price;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        pocket = 0;
        shareprice.clear();
        selldays.clear();
        for (int j = 0; j < N; j++)
        {
            cin >> price;
            shareprice.push_back(price);
            selldays.push_back(false);
        }
        //cout << "TESTCASE " << i + 1 << endl << "----------" << endl;
        find_sell_days();
        calculate_profit();
        cout << pocket << endl;
    }
    return 0;
}
