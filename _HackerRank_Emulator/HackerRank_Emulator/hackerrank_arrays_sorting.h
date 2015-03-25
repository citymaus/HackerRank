#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ArraysSorting {
public:
	//static void swap(int* i, int* j);
	static void print_arr(vector <int> arr);
	static void insertion_sort(vector <int> & arr);
	static void quick_sort3(vector <int> & arr, int start, int end);
	static int find_median(vector <int> & arr, int start, int end);
	static int lomuto_partition(vector <int> & arr, int start, int end);
	static void quick_sort4(vector <int> & arr, int start, int end);
	static void full_counting_sort(vector <int> countme, vector <string> allstrings);
	static unsigned long long sherlock_and_pairs(vector <int> & arr);
};