#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Program izračuna vsoto števil.
 */
 
void vsotaPodseznama(vector<int> &s, int zacetek, int konec, long long &vsota) {
    for (int i=zacetek; i<konec; i++) {
       vsota += s[i];
    }
}

int main() {
    vector<int> seznam;
    int n = 50000000;

    srand(31337);
    
    for (int i=0; i<n; i++) {
        int x = 1 + rand() % 1000;
        seznam.push_back(x);
    }
    
    long long skupnaVsota = 0;
    
    clock_t prej = clock(); 

    vector<thread> niti;
    long long vsota[5];
    for (int i=0; i<5; i++) {
        vsota[i] = 0;
        niti.push_back(thread(vsotaPodseznama, ref(seznam), 10000000*i, 10000000*(i+1), ref(vsota[i])));
    } 

    for (int i=0; i<5; i++) {
        niti[i].join();
        skupnaVsota += vsota[i]; 
    }    
    
    clock_t potem = clock(); 

    cout << "Vsota: " << skupnaVsota << endl;
    cout << "Cas: " << (double)(potem - prej) / CLOCKS_PER_SEC << endl;

    return 0;
}

