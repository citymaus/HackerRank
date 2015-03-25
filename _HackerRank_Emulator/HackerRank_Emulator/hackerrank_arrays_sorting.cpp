#include "hackerrank_arrays_sorting.h"

/*void ArraysSorting::swap(int* i, int* j)
{
    cout << "swapping " << *i << " and " << *j << endl;
    int temp = *i;
    *i = *j;
    *j = temp;
}*/

void ArraysSorting::print_arr(vector <int> arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";    
    }
}

void ArraysSorting::insertion_sort(vector <int> & arr)
{
	int i,j;
    int value;
    for(i = 1; i < arr.size(); i++)
    {
        value=arr[i];
        j=i-1;
        //while(j>0 && value<arr[j])
        while(j>=0 && value < arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
            //print_arr(arr);
            //cout << endl;
        }
        arr[j+1]=value;
        //cout << "i:" << i << "-> ";
        //print_arr(arr);
        //cout << endl;
    }
    //print_arr(arr);
}

void ArraysSorting::quick_sort3(vector <int> & arr, int start, int end)
{
	int p_idx = end;
    int p = arr[end];
    int i=start, j=start + 1;
    int beg_of_right = start;
 
    cout << "start:" << start << " / end:" << end << endl;
    while ((j <= end) && (i <= end))
    {
        while (i < arr.size() && (arr[i] <= p))
        {
            // index of first big
            i++;   
        }
        j = i+1;
		while (j < arr.size() && (arr[j] > p))
		{
			j++;    
		}
        
        //cout << "i:" << i << "=" << arr[i] << " j:" << j << "=" << arr[j] << endl;
        if ((j <= end) && (i <= end) && (arr[j] <  arr[i]))
        {
            swap(arr[i], arr[j]);    
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
        quick_sort3(arr, start, p_idx-1);
    }
    if (p_idx + 1 < end)
    {
        quick_sort3(arr, p_idx+1, end);    
    }
}


int ArraysSorting::find_median(vector <int> & arr, int start, int end)
{
    int median = 0;
    int median_idx = (int)arr.size()/2;
    int p_idx;    
    if (start < end)
    {
        p_idx = lomuto_partition(arr, start, end);
        if (p_idx == median_idx)
        {
            return arr[median_idx];    
        }
        else
        {
            find_median(arr, start, p_idx-1);
            find_median(arr, p_idx+1, end);
        }
    }
    median = arr[median_idx]; 
    return median;
}

int ArraysSorting::lomuto_partition(std::vector<int> &arr, int start, int end)
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
            //print_arr(arr);
            //cout << endl;
        }
    }
    swap(arr[i + 1], arr[end]);
    //print_arr(arr);
    //cout << endl;
    return i + 1;
}

// quick_sort(v, 0, v.size()-1);
void ArraysSorting::quick_sort4(std::vector<int> &arr, int start, int end)
{
	int p_idx;    
    if (start < end)
    {
        p_idx = lomuto_partition(arr, start, end);
        quick_sort4(arr, start, p_idx-1);
        quick_sort4(arr, p_idx+1, end);
    }
}

void ArraysSorting::full_counting_sort(vector <int> countme, vector <string> allstrings)
{
	int total_counts = 0;
    vector <int> counts(100, 0);
    vector <int> start_idx(100, 0);
    vector <string> print_idx(countme.size(), "");
    for (int i = 0; i < countme.size(); i++)
    {
        counts[countme[i]]++;    
    }
	cout << "   DONE counting ...................." << endl;
    
    for (int i = 0; i < counts.size(); i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            total_counts++; 
        }
        start_idx[i] = total_counts;
		//cout << "start_idx[" << i << "] = " << total_counts << endl;
    } 
	cout << "DONE SETUP ...................." << endl;
    
    for (int i = 0; i < countme.size(); i++)
    {
        int val = countme[i];
		int firsthalf = (countme.size()/2);
        //int endpos = start_idx[val];
        int startpos = 0;
		string s = "-";
        if (val > 0)
        {
            startpos = start_idx[val-1];
        }
		if (i >= firsthalf)
		{
			s = allstrings[i];
		}
		print_idx[startpos] = print_idx[startpos] + s + " ";
		//cout << "print_idx[" << startpos << "] = " << print_idx[startpos] << endl;
    }
    
     for (int i = 0; i < countme.size(); i++)
    {
        cout << print_idx[i]; 
    }
}

unsigned long long ArraysSorting::sherlock_and_pairs(vector <int> & arr)
{
    unsigned long long num_pairs = 0;
    unsigned long long num_consecutive = 0;
    unsigned long long consecutive = arr[0];
    
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == consecutive)
		{
			num_consecutive++;
		}
		else
		{
			consecutive = arr[i];
			if (num_consecutive > 1)
			{
				num_pairs = num_pairs + (num_consecutive*(num_consecutive-1));
			}
			num_consecutive = 1;
		}
		if (i == arr.size()-1)
		{
			if (num_consecutive > 1)
			{
				num_pairs = num_pairs + (num_consecutive*(num_consecutive-1));
			}
		}
		if (num_consecutive > 1)
		{
			//cout << "num_consecutive " << consecutive << "'s: " << num_consecutive << endl;
		}
	}    
    return num_pairs;
}