#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int buy_chocolates(int pocket_money, int price, int wrappers_needed)
{
    int num_chocolates = pocket_money / price;
    int wrappers_owned = num_chocolates;
    while (wrappers_owned >= wrappers_needed)
    {
        int free_chocolates = (wrappers_owned / wrappers_needed);
        num_chocolates += free_chocolates;
        wrappers_owned -= free_chocolates * wrappers_needed;
        wrappers_owned += free_chocolates;        
    }
    return num_chocolates;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        // Compute answer
        answer = buy_chocolates(n, c, m);
        cout<<answer<<endl;
    }
    return 0;
}
