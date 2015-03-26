#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

unsigned long long all_configs(int n);
int num_primes(int m);

unsigned long long all_configs(int n)
{
    /*  n=0 c=1
        n=1 c=1
        n=2 c=1
        n=3 c=1
        n=4 c=2
        n=5 c=3
        n=6 c=4
        n=7 c=5
        n=8 c=7
        n=9 c=10
        ...
        n=18 c>=181 */
    
    unsigned long long config[41];
    config[0] = 1;
    config[1] = 1;
    config[2] = 1;
    config[3] = 1;
    
    for (int i = 4; i <= 40; i++)
    {
        config[i] = config[i-1] + config[i-4];    
    }
    return config[n];
}

int num_primes(int m)
{
    int primes = (m + 1) - 2; // Between 0 and m inclusive, subtract two: 0 and 1, not primes
    int sq = sqrt(m);
    bool sieve[m+1];
    memset(sieve, true, sizeof(sieve));
    
    for (int i = 2; i <= sq; i++)
    {
        if (sieve[i])
        {
            // Remove all multiples of i, they are not prime
            for (int j = i*i; j <= m; j+=i)
            {
                if (sieve[j])
                {
                    //cout << "removing " << j << endl;
                    primes--;
                    sieve[j] = false;
                }
            }
        }
    }    
    return primes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, primes;
    unsigned long long configs;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        //cout << "num primes:";
        configs = all_configs(N);
        //cout << N << ", num configs:" << configs << endl;
        primes = num_primes(configs);
        cout << primes << endl;
    }
    return 0;
}
