#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Warmup {
public:
	static unsigned int palindromize(string s);
	static unsigned int flipping_bits(unsigned int unflipped);
	static unsigned int angry_children(int arr[], int N, int K);
	static int game_of_thrones(string s);
	static long long filling_jars(int start[], int finish[], int candies[], int num_jars, int num_ops);
	static bool sherlock_and_gcd(int s[], int set_size);	

	static int find_gcd(int a, int b);
	static void quicksort(int arr[], int left, int right);
	static void printarr(int arr[], string s);
};