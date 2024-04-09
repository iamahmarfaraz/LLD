#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

// Lower level module
class FileLogger1
{
public:
    void Log(const string &message)
    {
        // Code to write the message to a file
    }
};

// higher level module
class Application_
{
private:
    FileLogger1 *logger_;

public:
    Application_()
    {
        logger_ = new FileLogger1();
    }
    void Process()
    {
        logger_->Log("Application started");
        // Additional logic here
    }
};

// in above example higher level module Application is coupled/dependent on lower level module,
// that's the  violaton of DIP

// SOLUTION
// Make an Abstration, and make both dependent on ABS.

// 1. Define the Abstration
class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log(const string &message) = 0;
};

// 2. Implement the Abstration
class ConsoleLogger : public ILogger
{
public:
    void Log(const string &message) override
    {
        cout << "ConsoleLogger: " << message << endl;
    }
};

class FileLogger : public ILogger
{
public:
    void Log(const string &message) override
    {
        // Code to write the message to a file
        cout << "FileLogger: " << message << endl;
    }
};

// 3. Extend Functionality, if needed? which principle?
class ExternalServiceLogger : public ILogger
{
public:
    void Log(const std::string &message) override
    {
        // Code to send the message to an external service
        // This could involve HTTP requests, dealing with authentication, etc.
    }
};

// Higher level app now depends upon Abstraction
class Application
{
private:
    ILogger *logger_;

public:
    Application(ILogger *logger) : logger_(logger) {}
    void Process()
    {
        logger_->Log("Application started");
        // Additional logic here
    }
};

int main()
{
    // ExternalServiceLogger *externalServiceLogger = new ExternalServiceLogger();
    // // Base class pointer can point to the object of child class
    // Application app(externalServiceLogger);

    // OR

    ExternalServiceLogger externalServiceLogger;
    // Base class pointer can point to the object of child class
    Application app(&externalServiceLogger);

    ConsoleLogger clogger; // new FileLogger();
    Application app1(&clogger);
    app1.Process();
    return 0;
}
