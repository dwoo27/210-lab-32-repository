#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INTIAL_SIZE = 2;
const int PERIODS = 20;
const int LANES = 4;

const int PAID = 46;
const int JOIN = 39;
const int SWITCH = 15;
const int EMPTY = 50;

void displayQueue(deque<Car>&);
void displayPlaza(deque<Car>[]);

int main()
{
    srand(time(0));

    deque<Car> lanes[LANES]; //create array of deques
    for (int lane = 0; lane < LANES; lane++) {
        for (int i = 0; i < INTIAL_SIZE; i++) { //populate each lane with 2 cars initially and pushback into deque
            Car nextCar;
            lanes[lane].push_back(nextCar);
        }
    }
    

    cout << "Initial" << endl;
    displayPlaza(lanes);
    cout << endl;

    for (int period = 1; period <= PERIODS; period++) {
        cout << "Time: " << period << endl;
        
        for (int lane = 0; lane < LANES; lane++) {
            cout << "Lane: " << lane + 1 << " ";
            int prob = rand() % 100 + 1; //produces rand prob

            if (lanes[lane].empty()) {
                if (prob <= EMPTY) {
                    cout << "Joined: ";
                    Car nextCar; //create new car
                    lanes[lane].push_back(nextCar); //put in back of deque
                    nextCar.print();
                    cout << endl;

                }
            }
            else {
                if (prob <= PAID) { //prob paid 46%, prob is 1-46
                    cout << "Paid: ";
                    lanes[lane].front().print(); //peek front and print
                    lanes[lane].pop_front(); //remove from front
                    cout << endl;
                }
                else if (prob <= PAID + JOIN) { //prob join 39%, prob is 47-85
                    cout << "Joined: ";
                    Car nextCar; //create new car
                    lanes[lane].push_back(nextCar); //put in back of deque
                    nextCar.print();
                    cout << endl;
                }
                else { //prob switch 15%, prob is 86+

                }
            }
        }
    }
    /* int period = 1; //counter for periods

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
    } */
        
}

void displayQueue(deque<Car>& line) {
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

void displayPlaza(deque<Car> lanes[]){
    for (int lane = 0; lane < LANES; lane++) {
        cout << "Lane " << lane + 1 << " Queue:" << endl;
        displayQueue(lanes[lane]);
    }
}