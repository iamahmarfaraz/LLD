// FACADE DESIGN PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

#include <iostream>
using namespace std;

// 1. COMPLEX SUBSYTEM CONSISTING OF - ENGINE,FUELINJECTOR,IGNITION
class Engine
{
public:
    void start()
    {
        cout << "Engine started.\n";
    }
};

class FuelInjector
{
public:
    void injectFuel()
    {
        cout << "Fuel injected.\n";
    }
};

class Ignition
{
public:
    void fire()
    {
        cout << "Ignition fired.\n";
    }
};

// 2.FACADE
class CarFacade
{
private:
    Engine engine;
    FuelInjector fuelInjector;
    Ignition ignition;

public:
    void startCar()
    {
        fuelInjector.injectFuel();
        ignition.fire();
        engine.start();
        cout << "Car started successfully!\n";
    }

    void stopCar()
    {
        cout << "Car stopped.\n";
    }
};

// CLIENT
int main()
{
    CarFacade car;
    car.startCar();  // User doesn’t need to worry about individual subsystems.
    car.stopCar();
    return 0;
}