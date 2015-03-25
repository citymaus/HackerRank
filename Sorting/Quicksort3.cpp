#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

void swap(int* i, int* j);
void print_arr(int arr[]);
void swap(int* i, int* j)
{
    //cout << "swapping " << *i << " and " << *j << endl;
    int temp = *i;
    *i = *j;
    *j = temp;
}

void print_arr(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";    
    }
}

void quick_sort(int arr[], int start, int end)
{
    int p_idx = end;
    int p = arr[end];
    int i=start, j=start + 1;
    int beg_of_right = start;
 
    //cout << "start:" << start << " / end:" << end << endl;
    while ((j <= end) && (i <= end))
    {
        while (i < n && (arr[i] <= p))
        {
            // index of first big
            i++;   
        }
        j = i+1;
        while (j < n && (arr[j] > p))
        {
            j++;    
        }
        
        //cout << "i:" << i << "=" << arr[i] << " j:" << j << "=" << arr[j] << endl;
        if ((j <= end) && (i <= end) && (arr[j] <  arr[i]))
        {
            swap(&arr[i], &arr[j]);    
            i++;
            j++;
            //cout << "newi:" << i << "=" << arr[i] << " newj:" << j << "=" << arr[j] << endl;
        }
    }
    print_arr(arr);
    cout << endl;
    
    p_idx = i-1;
    if (start < p_idx-1)
    {
        quick_sort(arr, start, p_idx-1);
    }
    if (p_idx + 1 < end)
    {
        quick_sort(arr, p_idx+1, end);    
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, p;
    cin >> N;
    n = N;
    int sortme[N];
    for (int i = 0; i < N; i++)
    {
        cin >> sortme[i];
    }
    quick_sort(sortme, 0, N-1);
    return 0;
}
