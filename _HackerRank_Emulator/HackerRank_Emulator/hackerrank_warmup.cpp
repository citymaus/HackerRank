#include <cmath>
#include "hackerrank_warmup.h"

unsigned int Warmup::palindromize(string s)
{
    unsigned int changes = 0;
    unsigned int halfsize, foot_idx;
    string head, foot;
    if (s.length() % 2 == 0)
    {   // Even number string
        halfsize = s.length()/2;
        head.append(s, 0, halfsize);
        foot.append(s, halfsize, halfsize);
    }
    else
    {   // Odd number string
        halfsize = (s.length() - 1)/2;
        head.append(s, 0, halfsize);
        foot.append(s, halfsize + 1, halfsize);        
    }
    for (int i = 0; i < halfsize; i++)
    {
        foot_idx = foot.length() - 1 - i;
        if (head[i] > foot[foot_idx])
        {
            changes += head[i] - foot[foot_idx];
        }
        if (head[i] < foot[foot_idx])
        {
            changes += foot[foot_idx] - head[i];
        }
    }
    return changes;
}

unsigned int Warmup::flipping_bits(unsigned int unflipped)
{
    unsigned int flipped;
    unsigned int bits[32];
    unsigned int mask, currbit;
    flipped = 0;
    for (int shift = 0; shift < 32; shift++)
    {
        mask = 0x1 << shift;
        currbit = (unflipped & mask) >> shift;
        flipped |= !currbit << shift;
    }
    
    return flipped;    
}

unsigned int Warmup::angry_children(int arr[], int N, int K)
{
	// Do a quicksort first.
	quicksort(arr, 0, N-1);

    int min_unfairness = 0, current_unfairness;
    for (int i = 0; i < N-(K-1); i++)
    {
        current_unfairness = arr[i + (K-1)] - arr[i];
        if ((i == 0) || (current_unfairness < min_unfairness))
            min_unfairness = current_unfairness;
            
        //cout << "min=" << arr[i] << "max=" << arr[i + (K-1)] << " unfair: " << current_unfairness << endl;    
    }
    return min_unfairness;
}

int Warmup::game_of_thrones(string s)
{
	// Checking palindromeness
    int num_odd_counts = 0;
    int alphabet[26] = { 0 };
    int ok_palindrome = 1;
    int a_int = int('a');
    
    // Make sure count of each letter is even
    // One odd count is ok, can be middle of palindrome
    for (int i = 0; i < s.length(); i++)
    {
        int alpha_ind = int(s[i])-a_int;
        alphabet[alpha_ind]++; 
        //cout << "adding one to ind(" << alpha_ind << ") char:" << char(alpha_ind + a_int) << endl;
    }
    
    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] % 2 == 1)
        {
            num_odd_counts++;    
        }
    }
    if (num_odd_counts > 1)
        ok_palindrome = 0;
    return ok_palindrome;
}

long long Warmup::filling_jars(int start[], int finish[], int candies[], int num_jars, int num_ops)
{
	// Find average number of candies after num_ops
    long long total_all_jars = 0;
    for (int i = 0; i < num_ops; i++)
    {
        total_all_jars += (finish[i] - start[i] + 1) * (long long) candies[i];    
    }    
    return floor((long double) total_all_jars / num_jars);    
}

bool Warmup::sherlock_and_gcd(int s[], int set_size)
{
    if (set_size < 2)
    {
        // Only one item in set
        return false;
    }
    
    int current_gcd = s[0];
    for (int i = 0; i < set_size; i++)
    {
        current_gcd = find_gcd(current_gcd, s[i]);
    }
    
    return (current_gcd < 2);
}

int Warmup::find_gcd(int a, int b)
{	
    while (b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

void Warmup::printarr(int arr[], string s)
{
	int n = sizeof(arr) / sizeof(int);
    cout << s << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < (n-1))
            cout << ", ";
    }
    cout << "]" << endl;
}

void Warmup::quicksort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    while (i <= j)
    {
        // Find first instance of i > pivot, j < pivot
        while (arr[i] < pivot)
        {
            i++;    
        }
        while (arr[j] > pivot)
        {
            j--;    
        }
        if (i <= j)
        {
            // Swap values
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
    {
        quicksort(arr, left, j);    
    }
    if (i < right)
    {
        quicksort(arr, i, right);    
    }
}