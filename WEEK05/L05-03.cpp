#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

class Engine
{
public:
    void createEngine() {}
};

class ScorpioEngine : public Engine
{
public:
    ScorpioEngine()
    {
        cout << "Engine of Scorpio is Created" << endl;
    }
};

class DefenderEngine : public Engine
{
public:
    DefenderEngine()
    {
        cout << "Engine of Defender is Created" << endl;
    }
};

class VehicleCreation
{
public:
    Engine *eng;
    string name;

    virtual void makeCar() = 0;
    virtual void driveCar() = 0;
};

class ScorpioN : public VehicleCreation
{
public:
    ScorpioN()
    {
        name = "Scorpio-N";
    }
    void makeCar() override
    {
        cout << "Scorpio-N" << endl;
    }
    void driveCar() override
    {
        cout << "I'm Driving a Scorpio-N" << endl;
    }
};

class ScorpioClassic : public VehicleCreation
{
public:
    ScorpioClassic()
    {
        name = "Scorpio-Classic";
    }
    void makeCar() override
    {
        cout << "Scorpio-Classic" << endl;
    }
    void driveCar() override
    {
        cout << "I'm Driving a Scorpio-Classic" << endl;
    }
};

class ScorpioFactory : public VehicleCreation
{
public:
    VehicleCreation *Model;
    ScorpioFactory(VehicleCreation *Mdl)
    {
        name = "Scorpio"; // Set the name in the constructor
        Model = Mdl;
    }
    void makeCar() override
    {
        this->eng = new ScorpioEngine();
    }
    void driveCar() override
    {
        makeCar();
        Model->driveCar();
    }
};

class Defender90 : public VehicleCreation
{
public:
    Defender90()
    {
        name = "Defender90";
    }
    void makeCar() override
    {
        cout << "Defender90" << endl;
    }
    void driveCar() override
    {
        cout << "I'm Driving a Defender90" << endl;
    }
};

class Defender110 : public VehicleCreation
{
public:
    Defender110()
    {
        name = "Defender110";
    }
    void makeCar() override
    {
        cout << "Defender110" << endl;
    }
    void driveCar() override
    {
        cout << "I'm Driving a Defender110" << endl;
    }
};

class DefenderFactory : public VehicleCreation
{
public:
    VehicleCreation *Model;
    DefenderFactory(VehicleCreation *Mdl)
    {
        name = "Defender"; // Set the name in the constructor
        Model = Mdl;
    }
    void makeCar() override
    {
        this->eng = new DefenderEngine();
    }
    void driveCar() override
    {
        makeCar();
        Model->driveCar();
    }
};

// class car
// {
// public:
//     VehicleCreation *vehichle;
//     car(VehicleCreation *vhc) : vehichle(vhc) {}
//     void drivecar()
//     {
//         cout << "Process of making "
//              << "\"" << vehichle->name << "\""
//              << " has been started" << endl;
//         vehichle->driveCar();
//         cout << endl;
//     }
// };

class car
{
public:
    VehicleCreation *Factory;
    VehicleCreation *Vehicle;
    car(VehicleCreation *Fct, VehicleCreation *Vch) : Factory(Fct), Vehicle(Vch) {}
    void drivecar()
    {
        cout << "Process of making "
             << "\"" << Vehicle->name << "\""
             << " has been started" << endl;
        Factory->driveCar();
        cout << endl;
    }
};

int main()
{
    VehicleCreation *CarModel = new ScorpioN();
    VehicleCreation *vehicle = new ScorpioFactory(CarModel);
    car car1(vehicle, CarModel);

    VehicleCreation *CarModel1 = new ScorpioClassic();
    VehicleCreation *vehicle1 = new ScorpioFactory(CarModel1);
    car car2(vehicle1, CarModel1);

    VehicleCreation *CarModel2 = new Defender90();
    VehicleCreation *vehicle2 = new DefenderFactory(CarModel2);
    car car3(vehicle2, CarModel2);

    VehicleCreation *CarModel3 = new Defender110();
    VehicleCreation *vehicle3 = new DefenderFactory(CarModel3);
    car car4(vehicle3, CarModel3);

    vector<car> Car;
    Car.push_back(car1);
    Car.push_back(car2);
    Car.push_back(car3);
    Car.push_back(car4);

    for (auto c : Car)
    {
        c.drivecar();
    }

    // car1.drivecar();

    return 0;
}