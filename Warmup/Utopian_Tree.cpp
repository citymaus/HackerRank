#include <iostream>
using namespace std;

int height(int n) {
    int h = 1; // Beginning height always 1m
    for (int cycle = 1; cycle <= n; cycle++)
    {
        if (cycle % 2 == 1)
        {
            // First growth cycle (spring), doubles
            h *= 2;
        }
        else 
        {
            // Second growth cycle (summer), add 1m
            h += 1;
        }
    }
    return h;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
