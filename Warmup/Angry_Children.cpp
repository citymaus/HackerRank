#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

void printarr(int arr[], string s)
{
    cout << s << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < (n-1))
            cout << ", ";
    }
    cout << "]" << endl;
}

void quicksort(int arr[], int left, int right)
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

unsigned int unfair(int arr[], int N, int K)
{
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

int main() {
    /* The code required to enter n,k, candies is provided*/

    int N, K, unfairness;
    cin >> N >> K;
    n = N;
    int candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];
    
    // Sort array  
    //printarr(candies, "UNSORTED");
    quicksort(candies, 0, N-1);    
    //printarr(candies, "SORTED");
    unfairness = unfair(candies, N, K);
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}
