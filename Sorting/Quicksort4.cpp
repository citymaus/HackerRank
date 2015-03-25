#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_arr(vector <int> arr);
int lomuto_partition(vector <int> & arr, int start, int end, int* numswaps);
int insertion_sort(vector <int> & arr);
int quick_sort4(vector <int> & arr);

void print_arr(vector <int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";    
    }
}

int insertion_sort(vector <int> & arr)
{
    int i,j;
    int value;
    int numswaps = 0;
    for(i = 1; i < arr.size(); i++)
    {
        value=arr[i];
        j=i-1;
        //while(j>0 && value<arr[j])
        while(j>=0 && value < arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
            numswaps++;
            //print_arr(arr);
            //cout << endl;
        }
        arr[j+1]=value;
        //cout << "i:" << i << "-> ";
        //print_arr(arr);
        //cout << endl;
    }
    //print_arr(arr);
    //cout << endl << "numswaps: " << numswaps << endl;
    return numswaps;
}

int lomuto_partition(vector <int> & arr, int start, int end, int* numswaps)
{
    int x = arr[end];
    int i = start - 1;
    //cout << "start:" << start << " / end:" << end << endl;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
            *numswaps = *numswaps + 1;
            //print_arr(arr);
            //cout << endl;
        }
    }
    swap(arr[i + 1], arr[end]);
    *numswaps = *numswaps + 1;
    //print_arr(arr);
    //cout << endl;
    return i + 1;
}

int quick_sort4(vector <int> & arr, int start, int end)
{
    int numswaps = 0;
    int p_idx;
    
    if (start < end)
    {
        p_idx = lomuto_partition(arr, start, end, &numswaps);
        numswaps += quick_sort4(arr, start, p_idx-1);
        numswaps += quick_sort4(arr, p_idx+1, end);
    } 
    //cout << "numswaps: " << numswaps << endl;
    return numswaps;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, r;
    int iswaps, qswaps;
    cin >> N;
    vector <int> sortmeq;
    vector <int> sortmei;
    for (int i = 0; i < N; i++)
    {
        cin >> r;
        sortmei.push_back(r);
        sortmeq.push_back(r);
    }
    //cout << "insertion sort: " << endl;
    iswaps = insertion_sort(sortmei);
    //cout << endl << endl << "quick sort:" << endl;
    qswaps = quick_sort4(sortmeq, 0, N-1);
    cout << iswaps - qswaps << endl;
    return 0;
}
