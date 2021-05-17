#include <chrono>
#include <iostream>
#include <cmath>
#include "lab1.cpp"
#include "lab2.cpp"
using namespace std;



int main() {

    using chrono::microseconds;

    List s_1 = new_list();
    String a = new_string();


    
    for (int j=0; j != 8; j++){
        auto t1 = chrono::steady_clock::now();
        for (int i=0; i !=  10 * pow(10, j); ++i){
            push_list(s_1, 1);  // считаем для стека-списка
            pop_list(s_1);

            //append(a, "a");  // считаем для массива с амортизацией

            //append_simple(a, "a");  // считаем для массива с амортизацией
        }
        auto t2 = chrono::steady_clock::now();
        // duration<double, nano> ms_double = t2 - t1;
        auto time = chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        cout << 10 * pow(10, j) << ' '<< time << ' ' << "mcs" << endl;
    }
    return 0;
    }
