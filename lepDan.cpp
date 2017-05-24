#include <iostream>
#include <thread>
#include <string>
using namespace std;

/*
 * g++ lepDan.cpp -pthread -std=c++11 -o helloWorld
 */

void izpisi_Nkrat(int n, string& msg) {
    for (int i=0; i<n; i++) {
        cout << msg << endl;
    }
}

int main() {
    string s1 = "Danes je na Obali soncen dan!";
    string s2 = "Danes na Obali sije sonce!";
    
    thread nit_1(izpisi_Nkrat, 10, ref(s1));
    thread nit_2(izpisi_Nkrat, 7, ref(s2));
    
    nit_1.join();
    nit_2.join();
    return 0;
}
