// BUILDER PATTERN 

#include <iostream>
using namespace std;

class Car {
public:
    string engine, chassis, body, tyre;

    virtual void info() = 0;
};

class Scorpio : public Car {
    public:
    void info() override {
        cout << "🚗 Car Info Scorpio:\n";
        cout << "Engine: " << engine << endl;
        cout << "Chassis: " << chassis << endl;
        cout << "Body: " << body << endl;
        cout << "Tyre: " << tyre << endl;
    }
};

class Fortuner : public Car {
    public:
    void info() override {
        cout << "🚗 Car Info Fortuner:\n";
        cout << "Engine: " << engine << endl;
        cout << "Chassis: " << chassis << endl;
        cout << "Body: " << body << endl;
        cout << "Tyre: " << tyre << endl;
    }
};

class CarBuilder {
public:
    virtual void withEngine() = 0;
    virtual void withChassis() = 0;
    virtual void withBody() = 0;
    virtual void withTyre() = 0;
    virtual Car& build() = 0;
    virtual ~CarBuilder() {}  // always add virtual destructor for interfaces
};

class ScorpioBuilder : public CarBuilder {
private:
    Scorpio car;

public:
    void withEngine() override {
        // car.engine = new ScorpioEngine();
        car.engine = "2.2L mHawk";
    }
    void withChassis() override {
        // car.chassis = new ScorpioChassis();
        car.chassis = "Ladder Frame";
    }
    void withBody() override {
        car.body = "Bold SUV";
    }
    void withTyre() override {
        car.tyre = "All-terrain tyres";
    }

    Car& build() override {
        return car;
    }
};

class FortunerBuilder : public CarBuilder {
private:
    Fortuner suv;

public:
    void withEngine() override {
        suv.engine = "4.1L Toyota Engine";
    }
    void withChassis() override {
        suv.chassis = "Toyota Chassis";
    }
    void withBody() override {
        suv.body = "Grand SUV";
    }
    void withTyre() override {
        suv.tyre = "4x4";
    }

    Car& build() override {
        return suv;
    }
};

class Director {
private:
    CarBuilder* builder;

public:
    Director(CarBuilder* builder) : builder(builder) {}

    void construct(bool tyreNeeded) {
        builder->withEngine();
        builder->withChassis();
        builder->withBody();
        if (tyreNeeded)
        {
            builder->withTyre();
        }
        
    }
};

int main() {
    CarBuilder* builder = new ScorpioBuilder();   // Like Java: ICarBuilder builder = new ScorpioBuilder();
    Director director(builder);                   // Like Java: Director director = new Director(builder);

    director.construct(true);                         // Tell builder to build it
    // FINAL OBJECT WE'LL GET FROM BUILDER ITSELF
    Car& car = builder->build();                 // Get the final car

    car.info();                                   // Print car specs

    delete builder;                               // Free memory

    CarBuilder* b2 = new FortunerBuilder();
    Director d2(b2);
    d2.construct(false);
    Car& car2 = b2->build();
    car2.info();
    delete b2;
    return 0;
}