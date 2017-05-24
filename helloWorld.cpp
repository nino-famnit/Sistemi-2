#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

/*
 * g++ helloWorld.cpp -pthread -std=c++11 -o helloWorld
 */

void f_1() {
    for (int i=0; i<4; i++) {
        cout << "Sem f_1, i = " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void f_2() {
    for (int i=0; i<4; i++) {
        cout << "\t\t\t\tSem f_2, i = " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(700));
    }
}

int main() {
    thread nit_1(f_1);
    thread nit_2(f_2);
    
    nit_1.join();
    nit_2.join();
    return 0;
}
