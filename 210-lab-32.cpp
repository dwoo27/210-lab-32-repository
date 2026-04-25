#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INTIAL_SIZE = 2;
const int PERIODS = 20;

void displayQueue(deque<Car>&);

int main()
{
    srand(time(0));

    deque<Car> line; //create std::deque

    for (int i = 0; i < INTIAL_SIZE; i++) { //populate with 2 cars initially and pushback into deque
        Car nextCar;
        line.push_back(nextCar);
    }

    cout << "Intial" << endl;
    displayQueue(line);
    cout << endl;

    int period = 1; //counter for periods

    while (!line.empty()) { //run while line is not empty
        int prob = rand() % 100 + 1; //produces rand prob

        cout << "Time: " << period << " Operation: ";

        if (prob <= 55) { //55% prob car in front pays
            cout << "Car paid: ";
            line.front().print(); //peek front and print
            line.pop_front(); //remove from front
            cout << endl;
        }
        else{ //remaining 45% prob car joins
            cout << "Joined lane: ";
            Car nextCar; //create new car
            line.push_back(nextCar); //put in back of deque
            nextCar.print();
            cout << endl;
        }

        displayQueue(line);
        cout << endl;
        period++;
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