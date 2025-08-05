// ADAPTER DESIGN PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class HotAirBalloon{
    public:
    string gas = "Helium";

    void start(string gas){
        this->gas = gas;
        cout<<"Hot Air Balloon started using "<<this->gas<<" gas"<<endl;
    }

    string gasUsed(){
        return this->gas;
    }
};

class Icar{
    public:
    virtual void start() = 0;
};

class Adapter:public Icar{
    public:
    HotAirBalloon* hotAirBalloon;

    Adapter(HotAirBalloon* balloon){
        this->hotAirBalloon = balloon;
    }

    void start()override{
        string gas = hotAirBalloon->gas;
        hotAirBalloon->start(gas);
    }
};

int main()
{
    HotAirBalloon * balloon = new HotAirBalloon();
    Icar * car = new Adapter(balloon);
    car->start();
    
    return 0;
}