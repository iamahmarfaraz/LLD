// DECORATOR PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Icar{
    public:
    float baseWeight = 1500;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual float getWeight() = 0;
};

class Scorpio:public Icar{
    public:
    void start() override{
        cout<<"Scorpio Started"<<endl;
    }
    void stop() override{
        cout<<"Scorpio Stopped"<<endl;
    }
    float getWeight() override{
        return this->baseWeight;
    }
};

class ScorpioDecorator:public Icar{
    public:
};

class BulletProofScorpioDecorator:public ScorpioDecorator{
    public:
    Icar* Scorpio;

    BulletProofScorpioDecorator(Icar* myScorpio){
        this->Scorpio = myScorpio;
    }

    void start() override{
        Scorpio->start();
    }
    void stop() override{
        Scorpio->stop();
    }
    float getWeight() override{
        return (300.0 + Scorpio->getWeight());
    }
};

 

int main()
{
    // 
    Icar * car1 = new Scorpio();
    cout<<"BASE WEIGHT OF CAR1(WITHOUT BULLET PROOF CAR)"<<car1->getWeight()<<endl;
    ScorpioDecorator* decorator = new BulletProofScorpioDecorator(car1);
    cout<<"BASE WEIGHT OF CAR1(WITHOUT BULLET PROOF CAR)"<<decorator->getWeight()<<endl;
    
    return 0;
}