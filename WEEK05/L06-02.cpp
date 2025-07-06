// SINGLETON DESIGN PATTERN

#include <iostream>
#include <vector>

using namespace std;

// SINGLE THREADED
class AircraftOne
{
private:
    AircraftOne()
    {
        cout << "Object Created of AircrafeOne" << endl;
    }
    static AircraftOne *aircraftInstance;

public:
    static AircraftOne *getInstance()
    {
        if (aircraftInstance == NULL)
        {
            aircraftInstance = new AircraftOne();
        }
        return aircraftInstance;
    }
};

// Why do we write AircraftOne* again here? Isn’t it already known from the class?
// Answer: Because C++ needs the full type when defining a static member outside the class
// Why can’t I initialize static members inside the class in C++?
// Because C++ separates declaration and definition for static members — unlike Java.
// In C++:
// static data members belong to the class, not to an object
// They are stored separately in memory
// The compiler needs one definition outside the class to actually allocate storage for it
AircraftOne *AircraftOne::aircraftInstance = nullptr;

// MULTI-THREADED - MEYER'S Approach
class Singleton
{
private:
    Singleton()
    {
        cout << "Instance/Object Created" << endl;
    }

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
    Singleton(Singleton const &) = delete; // this line mean copy constructor call nhi hona chahiye and ise koi
    // equate na kr paye
    Singleton &operator=(Singleton const &) = delete; // is line se Singleton& s1 = new Singleton() nhi krpayenge
};

int main()
{
    AircraftOne *obj1 = AircraftOne::getInstance();

    Singleton &instance1 = Singleton::getInstance();
    Singleton &instance2 = Singleton::getInstance();
    return 0;
}