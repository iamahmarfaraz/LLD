// PROTOTYPE PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// class ScorpioEngine{
//     public:
// };

// class ScorpioN_Engine: public ScorpioEngine{
//     public:
// };

// class ScorpioClassic_Engine: public ScorpioEngine{
//     public:
// };

// SHALLOW COPY
// class ScorpioPrototype{
//     public:
//     ScorpioEngine * engine = new ScorpioEngine();

//     ScorpioPrototype* clone(){
//         return new ScorpioPrototype(*this);
//     }

//     void setEngine(ScorpioEngine *engine){
//         this->engine = engine;
//     }
// };

// DEEP COPY
#include <iostream>
using namespace std;

class ScorpioEngine
{
public:
    ScorpioEngine()
    {
        cout << "Default ScorpioEngine created.\n";
    }

    virtual ~ScorpioEngine() {}

    // Virtual clone method to preserve derived type
    virtual ScorpioEngine *clone() const
    {
        // STEP3 - this will return new ScorpioEngine object 
        // refering to different memory location than Original Engine
        // but with value same as original engine
        return new ScorpioEngine(*this);
    }
};

class ScorpioN_Engine : public ScorpioEngine
{
public:
    ScorpioN_Engine()
    {
        cout << "ScorpioN Engine created.\n";
    }

    ScorpioEngine *clone() const override
    {
        return new ScorpioN_Engine(*this);
    }
};

class ScorpioClassic_Engine : public ScorpioEngine
{
public:
    ScorpioClassic_Engine()
    {
        cout << "ScorpioClassic Engine created.\n";
    }

    ScorpioEngine *clone() const override
    {
        return new ScorpioClassic_Engine(*this);
    }
};

class ScorpioPrototype
{
public:
    ScorpioEngine *engine;

    ScorpioPrototype()
    {
        engine = new ScorpioEngine(); // default
    }

    //  Proper deep copy constructor using virtual clone
    ScorpioPrototype(const ScorpioPrototype &original)
    {
        // STEP2 - Now the copy constructor will let uh initalize
        // object with Original Object value but with different
        //memory location for even pointer type variable like ScorpioEngine *engine;
        // SEE ScorpioEngine Class now
        if (original.engine){
            engine = original.engine->clone(); // polymorphic deep copy
        }
        else{
            engine = nullptr;
        }
    }

    ScorpioPrototype *clone()
    {
        // STEP 1 - below line will return a new ScorpioPrototype Object but
        // but with exact value as of original Object i.e after copying
        // but heres a catch we have defined COPY CONSTRUCTOR of this class
        //For DEEP COPY ,check COPY CONSTRUCTOR NOW
        return new ScorpioPrototype(*this); // use deep copy constructor
    }

    void setEngine(ScorpioEngine *eng)
    {
        if (engine){
            delete engine; // cleanup existing
        }
        engine = eng;
    }

    ~ScorpioPrototype()
    {
        delete engine;
    }
};

int main()
{
    // Create a Prototype
    ScorpioPrototype *Scorpio = new ScorpioPrototype();
    // Create object copying that prototype
    ScorpioPrototype *ScorpioN = Scorpio->clone();
    ScorpioEngine *engine = new ScorpioN_Engine();
    ScorpioN->setEngine(engine);
    cout<<"ProtoType's Engine : "<<Scorpio->engine<<endl;
    cout<<"Copy Object's Engine : "<<ScorpioN->engine<<endl;

    return 0;
}