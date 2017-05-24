#include <iostream>
#include <thread>
#include <string>
#include <vector>
using namespace std;

/*
 * g++ lepDan.cpp -pthread -std=c++11 -o helloWorld
 */

void stejSode(const vector<int> &v, int &stevec) {
    for (const auto x : v) {
        if (x % 2 == 0) stevec++;
    }
}

int main() {
    vector<int> n1;
    vector<int> n2;
    
    for (int i=1; i<=1000; i++) {
        n1.push_back(i);
        n2.push_back(i);
    }
    
    int stSodih = 0;
    
    thread nit_1(stejSode, ref(n1), ref(stSodih));
    thread nit_2(stejSode, ref(n2), ref(stSodih));
    
    nit_1.join();
    nit_2.join();
    
    cout << "Sodih stevil je " << stSodih << "." << endl;
    return 0;
}
