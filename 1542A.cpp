#include <iostream>

using namespace std;


//!
//! \brief codeforces.com 1542A - odd set 
//!
int main() {
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n = 0;
        cin >> n;
     
        int even_count = 0;
        int odd_count = 0;

        for (int j = 0; j < (n * 2); ++j) {
            int num = 0;
            cin >> num;

            if (num % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        if (even_count == odd_count) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
        

    return 0;
}
