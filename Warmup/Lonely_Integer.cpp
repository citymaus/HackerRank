#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;

int lonelyinteger(int arr[])
{
    // Array is sorted, set lonely guy to last integer
    int lonely = arr[n-1];
    
    for (int i = 1; i < n-1; i++)
    {
        if ((arr[i] == arr[i-1]) || (arr[i] == arr[i+1]))
        {
            //cout << i-1 << " and " << i << " OR " << i + 1 << " are buddies: " << arr[i] << endl;
        }
        else
        {
            lonely = arr[i];    
            //cout << i << " is lonely: " << arr[i] << endl;
        }
    }
    
    return lonely;
}

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

int main() {
    int res;
    
    int N;
    cin >> N;
    n = N;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');     
    int integers[N];
    for (int i=0; i<N; i++)
        cin >> integers[i];
    
    // Sort array  
    //printarr(integers, "UNSORTED");
    quicksort(integers, 0, N-1);    
    //printarr(integers, "SORTED");
    res = lonelyinteger(integers);
    cout << res;
    
    return 0;
}
