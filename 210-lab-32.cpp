#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INTIAL_SIZE = 2;

void displayQueue(deque<Car>&);

int main()
{
    
}

void displayQueue(deque<Car>& line) {
    cout << "Queue:" << endl;

    if (line.empty()) {
        cout << "\tEmpty" << endl;
    }
    else {
        for (Car& car : line) {
            cout << "\t";
            car.print();
            cout << endl;
        }
    }
}