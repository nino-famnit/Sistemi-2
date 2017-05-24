#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
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

void vsotaPrast(int zacetek, int meja, int korak, long long &s) {
    for (int i=zacetek; i <= meja; i += korak) {
        if (jePrastevilo(i)) {
            s += i;
        }
    }    
}

int main() {
    int n = 20000000;
    
    long long skupnaVsota = 2;
    long long vsota1 = 0, vsota2 = 0;
    
    clock_t prej = clock(); 

    thread nit_1(vsotaPrast, 3, n, 4, ref(vsota1));
    thread nit_2(vsotaPrast, 5, n, 4, ref(vsota2));
    
    nit_1.join();
    nit_2.join();
    
    skupnaVsota += vsota1;
    skupnaVsota += vsota1;
    
    clock_t potem = clock(); 

    cout << "Vsota: " << skupnaVsota << endl;
    cout << "Cas: " << (double)(potem - prej) / CLOCKS_PER_SEC << endl;

    return 0;
}

