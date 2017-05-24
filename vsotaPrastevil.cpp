#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Program izračuna vsoto praštevil do 20000000.
 */
 
bool jePrastevilo(int n) {
    if (n % 2 == 0) {
        return n == 2;
    }
    int i = 3;
    while (i*i <= n) {
        if (n % i == 0) return false;
        i += 2;
    }
    return true;
}

int main() {
    int n = 20000000;
    
    long long vsota = 2;
    
    vector<thread> 
    clock_t prej = clock(); 

    for (int i=3; i <= n; i += 2) {
        if (jePrastevilo(i)) {
            vsota += i;
        }
    }    
    
    clock_t potem = clock(); 

    cout << "Vsota: " << vsota << endl;
    cout << "Cas: " << (double)(potem - prej) / CLOCKS_PER_SEC << endl;

    return 0;
}

