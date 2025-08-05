// BRIDGE PATTERN 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Engine Interface and Implementations
class Engine
{
public:
    virtual void startEngine() = 0;
    virtual string getEngineType() = 0;
    virtual ~Engine() {}
};

class PetrolEngine : public Engine
{
public:
    void startEngine() override
    {
        cout << "Starting Petrol Engine"<<endl;
    }
    string getEngineType() override
    {
        return "Petrol Engine";
    }
};

class DieselEngine : public Engine
{
public:
    void startEngine() override
    {
        cout << "Starting Diesel Engine"<<endl;
    }
    string getEngineType() override
    {
        return "Diesel Engine";
    }
};

class ElectricEngine : public Engine
{
public:
    void startEngine() override
    {
        cout << "Starting Electric Engine"<<endl;
    }
    string getEngineType() override
    {
        return "Electric Engine";
    }
};

// ABSTRACTION
class Vehicle
{
protected:
    Engine *engine; // Bridge happens here!

public:
    Vehicle(Engine *eng)
    {
        engine = eng;
    }

    virtual void drive() = 0;

    virtual ~Vehicle() {}
};

// CONCRETE CLASS
class Car : public Vehicle
{
public:
    Car(Engine *eng) : Vehicle(eng) {}

    void drive() override
    {
        cout << "Car with " << engine->getEngineType() << " is driving"<<endl;
        engine->startEngine();
    }
};

class Truck : public Vehicle
{
public:
    Truck(Engine *eng) : Vehicle(eng) {}

    void drive() override
    {
        cout << "Truck with " << engine->getEngineType() << " is driving"<<endl;
        engine->startEngine();
    }
};

// CLIENT
int main()
{
    Engine *petrol = new PetrolEngine();
    Engine *diesel = new DieselEngine();
    Engine *electric = new ElectricEngine();

    Vehicle *car1 = new Car(petrol);
    Vehicle *car2 = new Car(electric);
    Vehicle *truck1 = new Truck(diesel);

    car1->drive();
    cout << endl;
    car2->drive();
    cout << endl;
    truck1->drive();

    // Clean up
    delete petrol;
    delete diesel;
    delete electric;
    delete car1;
    delete car2;
    delete truck1;

    return 0;
}
