#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int l, r;
string sorttype;

void print_arr(vector <int> arr);
bool is_sorted(vector <int> & arr);
bool try_swap(vector <int> sw, int i, int j);
bool try_reverse(vector <int> arr, int start, int end);

void print_arr(vector <int> arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";    
    }
}

bool is_sorted(vector <int> & arr)
{
    bool sorted = true;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i-1])
        {
            sorted = false;
            break;
        }
    }
    return sorted;
}

bool try_swap(vector <int> sw, int i, int j)
{
    swap(sw[i], sw[j]);
    //cout << "swapped i:" << i << " j:" << j << endl;
    //print_arr(sw);
    //cout << endl;
    return is_sorted(sw);
}

bool try_reverse(vector <int> rev, int start, int end)
{
    int mid = ((start + end) / 2);
    int counter = 0;
    for (int i = start; i <= mid; i++)
    {
        int j = end - counter;
        //cout << "swapping i:" << i << " j:" << j << endl;
        counter++;
        swap(rev[i], rev[j]);
    }
    //print_arr(rev);
    //cout << endl;
    return is_sorted(rev);
}

string almost_sorted(vector <int> & arr)
{
    string can_sort = "no";
    sorttype = "";
    l = 0;
    r = 0;
    int left = 0;
    int right = 0;
    
    // Check if already sorted
    if (is_sorted(arr))
    {
        return "yes";    
    }
    
    // Find the out of whack indices
    left = 0;
    right = 0;
    int save_right = 0;
    //cout << "start:" << start << " / end:" << end << endl;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i-1])
        {
            left = i-1;
            break;
        }
    }
    for (int j = arr.size()-1; j > 0; j--)
    {
        if (arr[j] < arr[j-1])
        {
            right = j;
            save_right = right;
            break;
        }
    }
    
    // Try swap first  
    if (try_swap(arr, left, right))
    {
        l = left + 1;
        r = right + 1;
        sorttype = "swap";
        return "yes";
    }

    // Try reverse
    right = save_right;
    if (try_reverse(arr, left, right))
    {
        l = left + 1;
        r = right + 1;
        sorttype = "reverse";
        return "yes";
    }
    return "no";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, ele;
    cin >> N;
    vector <int> v;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    s = almost_sorted(v);
    cout << s << endl;
    if (sorttype != "")
    {
        cout << sorttype << " " << l << " " << r;
    }
    return 0;
}
