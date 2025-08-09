// COMMAND DESIGN PATTERN 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

// RECIEVER INTERFACE
class Button{
    public:
    virtual void click() = 0;
    virtual ~Button() {}
};

// CONCRETE RECIEVER
class EngineOnButton: public Button{
    public:
    void click() override{
        cout<<"Engine is Turned On"<<endl;
    }
};

// CONCRETE RECIEVER
class EngineOffButton: public Button{
    public:
    void click() override{
        cout<<"Engine is Turned Off"<<endl;
    }
};

// COMMAND INTERFACE
class Command{
    public:
    virtual void execute() = 0;
    virtual ~Command(){}
};

// CONCREATE COMMAND CLASS
class EngineOnCommand: public Command{
    public:
    Button *button;

    EngineOnCommand(Button *btn):button(btn){}

    void execute() override{
        button->click();
    }
};

// CONCREATE COMMAND CLASS
class EngineOffCommand: public Command{
    public:
    Button *button;

    EngineOffCommand(Button *btn):button(btn){}

    void execute() override{
        button->click();
    }
};

// INVOKER
class RemoteControl {
private:
    queue<Command*>commands;
public:
    void addCommand(Command* cmd) {
        commands.push(cmd);
    }
    void pressButton() {
        while(!commands.empty()){
            auto cmd = commands.front();
            cmd->execute();
            commands.pop();
        }
    }
};

int main() {

    // Receivers
    EngineOnButton engineOn;
    EngineOffButton engineOff;

    // Commands
    EngineOnCommand onCmd(&engineOn);
    EngineOffCommand offCmd(&engineOff);

    // Invoker
    RemoteControl remote;

    // Turn Engine On
    remote.addCommand(&onCmd);
    remote.addCommand(&offCmd);
    remote.pressButton();

    return 0;
}