// COMPOSITE DESIGN PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Step 1: Component Interface
class Employee {
public:
    virtual void showDetails() = 0;
    virtual ~Employee() {}
};

// Step 2: Leaf
class Developer : public Employee {
    string name;
    string position;

public:
    Developer(string name, string position) : name(name), position(position) {}

    void showDetails() override {
        cout << position << ": " << name << endl;
    }
};

// Step 2: Another Leaf
class Designer : public Employee {
    string name;
    string position;

public:
    Designer(string name, string position) : name(name), position(position) {}

    void showDetails() override {
        cout << position << ": " << name << endl;
    }
};

// Step 3: Composite
class Manager : public Employee {
    string name;
    string position;
    vector<Employee*> team;

public:
    Manager(string name, string position) : name(name), position(position) {}

    void add(Employee* emp) {
        team.push_back(emp);
    }

    void showDetails() override {
        cout << position << ": " << name << endl;
        for (Employee* emp : team) {
            emp->showDetails();
        }
    }
};

int main() {
    Employee* dev1 = new Developer("Alice", "Backend Developer");
    Employee* dev2 = new Developer("Bob", "Frontend Developer");
    Employee* des1 = new Designer("Carol", "UI Designer");

    Manager* engManager = new Manager("Dave", "Engineering Manager");
    engManager->add(dev1);
    engManager->add(dev2);
    engManager->add(des1);

    Manager* generalManager = new Manager("Eve", "General Manager");
    generalManager->add(engManager);

    generalManager->showDetails();

    return 0;
}
