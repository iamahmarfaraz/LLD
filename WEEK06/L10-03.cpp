// FLYWEIGHT PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Intrinsic Property
class TreeType
{
    string name;
    string color;
    string texture;

public:
    TreeType(string name, string color, string texture)
        : name(name), color(color), texture(texture) {}

    void display(int x, int y)
    {
        cout << "Tree [Type: " << name << ", Color: " << color
             << ", Texture: " << texture << "] at (" << x << ", " << y << ")" << endl;
    }
};

// Flyweight Factory
class TreeFactory
{
    unordered_map<string, TreeType *> treeTypes;

public:
    TreeType *getTreeType(string name, string color, string texture)
    {
        string key = name + "_" + color + "_" + texture;

        if (treeTypes.find(key) == treeTypes.end())
        {
            treeTypes[key] = new TreeType(name, color, texture);
        }
        return treeTypes[key];
    }

    ~TreeFactory()
    {
        for (auto &pair : treeTypes)
            delete pair.second;
    }
};

class Tree
{
    int x, y;
    TreeType *type;

public:
    Tree(int x, int y, TreeType *type) : x(x), y(y), type(type) {}

    void display()
    {
        type->display(x, y); // extrinsic data passed to shared intrinsic object
    }
};

int main()
{
    TreeFactory factory;
    vector<Tree *> forest;

    forest.push_back(new Tree(10, 20, factory.getTreeType("Oak", "Green", "Rough")));
    forest.push_back(new Tree(15, 25, factory.getTreeType("Oak", "Green", "Rough")));
    forest.push_back(new Tree(50, 60, factory.getTreeType("Pine", "Dark Green", "Smooth")));

    for (auto tree : forest)
        tree->display();

    // Clean up
    for (auto tree : forest)
        delete tree;

    return 0;
}
