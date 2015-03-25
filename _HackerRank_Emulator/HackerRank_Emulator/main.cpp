#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "file_handler.h"
#include "hackerrank_warmup.h"
#include "hackerrank_implementation.h"
#include "hackerrank_arrays_sorting.h"
#include "hackerrank_search.h"
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int start_s=clock();

	// Change these based on challenge.
#define current_level Search
#define current_test  sherlock_and_pairs
	string level = "search";
	string testname = "sherlock_and_pairs"; //"flipping_bits"; //"the_love_letter";
	string testcase = "02"; 
	string testinput = level + "-tc" + testcase + "_" + testname + ".txt";
	FileHandler* filereader = new FileHandler(testinput);

    int n;
	int r;
	int T;
	int pairs;
//    string row, s;
    //unsigned int input;
	//unsigned int opers;
    //cin >> n;    
    cin >> T;
	//vector <int> countme;
    //vector <string> thestrings;
	for (int j = 0; j < T; j++)
	{
		//cout << "TESTCASE " << j << ":" << endl;
		cin >> n;
        vector <int> v;
		for(int i = 0; i < n; i++) 
		{
			/*cin >> input;
			opers = current_level::current_test(input);
			cout << opers << endl; */
			cin >> r;
			v.push_back(r);
			//thestrings.push_back(s);
		}
		ArraysSorting::quick_sort4(v, 0, v.size()-1);
        //ArraysSorting::print_arr(v);
        //cout << endl;
        pairs = current_level::current_test(v);
        cout << pairs << endl;
	}
	//current_level::current_test(outrow, 0, n-1);
	//current_level::current_test(countme, thestrings);
	int stop_s=clock();
	cout << endl << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << "sec" << endl;
	system("pause");
    return 0;
}
