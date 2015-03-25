#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isint(double x);
bool isint(double x)
{
    int rounded = round(x);
    if ((double) rounded != x)
    {
        return false;
    }
    return true;
}

string circle_city(unsigned long long rsquared, unsigned long long num_stations)
{
    // R^2 = x^2 + y^2
    // Look in Q1, multiply this by 4
    double maxcoord = sqrt(rsquared);
    //if (!isint(maxcoord))
    //{
    //    return "impossible";    
    //}
    int kneeded = 0;
    for (int x = 0; x <= maxcoord; x++)
    {
        // y^2 = r^2 - x^2
        double y = sqrt(rsquared - (x*x));
        if (isint(y) && (y > 0))
        {
            if ((double)((x*x) + (y*y)) == (double)rsquared)
            {
                //cout << "x:" << x << ", y:" << y << endl;
                kneeded++;
            }
        }
    }
    kneeded = kneeded * 4;
    //cout << "r^2:" << rsquared << " k needed:" << kneeded << " provided:" << num_stations << endl;
    if (kneeded <= num_stations)
    {
        return "possible";    
    }
    
    return "impossible";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    unsigned long long T, Rsquared, k;
    string possible;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> Rsquared >> k;
        possible = circle_city(Rsquared, k);
        cout << possible << endl;
    }
    return 0;
}
