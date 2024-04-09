#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

class Scorpio
{
    // INTERFACE CLASS
public:
    virtual void drivecar() = 0;
};

class ScorpioN : public Scorpio
{
public:
    void drivecar()  override
    {
        cout << "I'm driving Scorpio-N" << endl;
        ;
    }
};

class ScorpioClassic : public Scorpio
{
public:
    void drivecar()
    {
        cout << "I'm driving Scorpio-Classic" << endl;
    }
};

int main()
{
    Scorpio *Sc = new ScorpioClassic();
    Sc->drivecar();
    return 0;
}