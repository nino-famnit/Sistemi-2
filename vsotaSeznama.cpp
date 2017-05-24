#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Program izračuna vsoto števil.
 */

int main() {
    vector<int> seznam;
    int n = 50000000;

    srand(31337);
    
    for (int i=0; i<n; i++) {
        int x = 1 + rand() % 1000;
        seznam.push_back(x);
    }
    
    long long vsota = 0;
    
    clock_t prej = clock(); 

    for (int i=0; i<n; i++) {
        vsota += seznam[i];
    }    
    
    clock_t potem = clock(); 

    cout << "Vsota: " << vsota << endl;
    cout << "Cas: " << (double)(potem - prej) / CLOCKS_PER_SEC << endl;

    return 0;
}

