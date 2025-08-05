// PROXY DESIGN PATTERN

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

// Subject Interface/Abstract Class
class IDatabase {
public:
    virtual void fetchData() = 0;
    virtual ~IDatabase() {}
};

// REAL SUBJECT/OBJECT
class RealDatabase : public IDatabase {
public:
    void fetchData() override {
        cout << "Fetching data from the real database.\n";
    }
};

// PROXY
class ProxyDatabase : public IDatabase {
private:
    RealDatabase* realDb;
    bool hasAccess;

public:
    ProxyDatabase(bool access) : realDb(nullptr), hasAccess(access) {}

    void fetchData() override {
        if (hasAccess) {
            if (realDb == nullptr) {
                realDb = new RealDatabase(); // lazy loading
            }
            realDb->fetchData();
        } else {
            cout << "Access Denied: You do not have permission to fetch data.\n";
        }
    }

    ~ProxyDatabase() {
        delete realDb;
    }
};

// CLIENT
int main()
{
    IDatabase* userWithAccess = new ProxyDatabase(true);
    userWithAccess->fetchData();

    IDatabase* userWithoutAccess = new ProxyDatabase(false);
    userWithoutAccess->fetchData();

    delete userWithAccess;
    delete userWithoutAccess;
    return 0;
}