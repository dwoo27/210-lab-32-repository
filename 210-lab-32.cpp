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
    srand(time(0));

    deque<Car> line; //create std::deque

    for (int i = 0; i < INTIAL_SIZE; i++) { //populate with 2 cars initially and pushback into deque
        Car nextCar;
        line.push_back(nextCar);
    }

        
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