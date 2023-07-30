#include <iostream>
#include <queue>
#include <unistd.h> // for sleep() function
using namespace std;
// Define the traffic light colors
enum LightColor { GREEN, YELLOW, RED };
// Define the traffic light class
class TrafficLight {
private:
 LightColor color;
public:
 TrafficLight() {
    color = GREEN;
 }
 void changeColor() {
    switch (color) {
        case GREEN:
         color = YELLOW;
         break;
        case YELLOW:
         color = RED;
         break;
        case RED:
         color = GREEN;
         break;
    }
 }
 LightColor getColor() const {
    return color;
 }
};
// Define the vehicle class
class Vehicle {
private:
 int id;
public:
 Vehicle(int id) { 
    this->id = id;
 }
 int getId() const {
    return id;
 }
};
// Define the traffic management system class
class TrafficManagementSystem {
private:
 queue<Vehicle> vehicleQueue;
 TrafficLight trafficLight;
public:
 void addVehicle(Vehicle vehicle) {
 vehicleQueue.push(vehicle);
 }
 void run() {
 int iterations = 0; // add termination condition
 while (iterations < 10) { // or a specific time has passed
 // Check the traffic light color and dequeue a vehicle if the light is green
 if (trafficLight.getColor() == GREEN && !vehicleQueue.empty()) {
 Vehicle vehicle = vehicleQueue.front();
 vehicleQueue.pop();
 cout << "Vehicle " << vehicle.getId() << " is crossing the intersection" << endl;
 }
 // Change the traffic light color every 5 seconds
 trafficLight.changeColor();
 cout << "Traffic light is now " << trafficLight.getColor() << endl;
 sleep(5);
 iterations++; // increment iteration counter
 }
 }
};
int main() {
 TrafficManagementSystem tms;
 tms.addVehicle(Vehicle(1));
 tms.addVehicle(Vehicle(2));
 tms.addVehicle(Vehicle(3));
 tms.run();
 return 0;
}