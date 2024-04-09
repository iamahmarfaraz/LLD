#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

// FACTORY METHOD PATTERN

class Engine
{
public:
    void createEngine() {}
};

class Body
{
public:
    void createBody() {}
};

class ScorpioEngine : public Engine
{
public:
    ScorpioEngine()
    {
        cout << "Engine of Scorpio Created" << endl;
    }
};

class ScorpioBody : public Body
{
public:
    ScorpioBody()
    {
        cout << "Body of Scorpio Created" << endl;
    }
};

class Scorpio
{
public:
    Engine *eng;
    Body *bdy;

    virtual void makeScorpio()
    {
        this->eng = new ScorpioEngine();
        this->bdy = new ScorpioBody();
    }
    virtual void driveCar()
    {
        makeScorpio();
        cout << "I'm Now Driving a Scorpio" << endl;
    }
};

class ScorpioNEngine : public Engine
{
public:
    ScorpioNEngine()
    {
        cout << "Engine of Scorpio-N Created" << endl;
    }
};

class ScorpioNBody : public Body
{
public:
    ScorpioNBody()
    {
        cout << "Body of Scorpio-N Created" << endl;
    }
};

class ScorpioN : public Scorpio
{
public:
    void makeScorpio() override
    {
        this->eng = new ScorpioNEngine();
        this->bdy = new ScorpioNBody();
    }
    void driveCar() override
    {
        makeScorpio();
        cout << "I'm Driving a Scorpio-N" << endl;
    }
};

class ScorpioClassicEngine : public Engine
{
public:
    ScorpioClassicEngine()
    {
        cout << "Engine of Scorpio-Classic Created" << endl;
    }
};

class ScorpioClassicBody : public Body
{
public:
    ScorpioClassicBody()
    {
        cout << "Body of Scorpio-Classic Created" << endl;
    }
};

class ScorpioClassic : public Scorpio
{
public:
    void makeScorpio() override
    {
        this->eng = new ScorpioClassicEngine();
        this->bdy = new ScorpioClassicBody();
    }
    void driveCar() override
    {
        makeScorpio();
        cout << "I'm Driving a Scorpio-Classic" << endl;
    }
};

int main()
{
    vector<Scorpio *> list;
    Scorpio *car1 = new ScorpioN();
    Scorpio *car2 = new ScorpioClassic();
    list.push_back(car1);
    list.push_back(car2);
    for (auto car : list)
    {
        car->driveCar();
    }
    return 0;
}