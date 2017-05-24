#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Program izračuna vsoto števil.
 */
 
void vsotaPodseznama(vector<int> &s, int zacetek, int konec, long long &v) {
    for (int i=zacetek; i<=konec; i++) {
        v += s[i];
    }
}

int main() {
    vector<int> seznam;
    int n = 50000000;
    int m = n / 4;

    srand(31337);
    
    for (int i=0; i<n; i++) {
        int x = 1 + rand() % 1000;
        seznam.push_back(x);
    }
    
    long long skupnaVsota = 0;
    long long vsota[4];
    vector<thread> nit;
    
    clock_t prej = clock(); 

    for (int i=0; i<4; i++) {
        int konec = m*(i+1) - 1;
        if (i == 3) konec = n - 1;
        nit.push_back(thread(vsotaPodseznama, ref(seznam), m*i,  konec, ref(vsota[i])));
    }    
    
    for (int i=0; i<4; i++) {
        nit[i].join();
        skupnaVsota += vsota[i];
    }
    
    clock_t potem = clock(); 

    cout << "Vsota: " << skupnaVsota << endl;
    cout << "Cas: " << (double)(potem - prej) / CLOCKS_PER_SEC << endl;

    return 0;
}

