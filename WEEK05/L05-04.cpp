// FACTORY PATTERN

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Product
class Notification
{
public:
    string type;
    virtual void send() = 0;
    virtual ~Notification() {}
};

// Concrete Products
class EmailNotification : public Notification
{
public:
    EmailNotification()
    {
        type = "Email";
    }
    void send() override
    {
        cout << "Sending Email Notification" << endl;
    }
};

class SMSNotification : public Notification
{
public:
    SMSNotification()
    {
        type = "SMS";
    }
    void send() override
    {
        cout << "Sending SMS Notification" << endl;
    }
};

class PushNotification : public Notification
{
public:
    PushNotification()
    {
        type = "Push";
    }
    void send() override
    {
        cout << "Sending Push Notification" << endl;
    }
};

// Factory
class NotificationFactory
{
public:
    static Notification *createNotification(string type)
    {
        if (type == "Email")
            return new EmailNotification();
        else if (type == "SMS")
            return new SMSNotification();
        else if (type == "Push")
            return new PushNotification();
        else
            return nullptr;
    }
};

// Client
class Notifier
{
public:
    Notification *notification;
    Notifier(Notification *notif)
    {
        notification = notif;
    }
    void notifyUser()
    {
        cout << "Selected Notification Type: " << notification->type << endl;
        notification->send();
        cout << endl;
    }
};

int main()
{
    Notification *n1 = NotificationFactory::createNotification("Email");
    Notification *n2 = NotificationFactory::createNotification("SMS");
    Notification *n3 = NotificationFactory::createNotification("Push");

    Notifier notify1(n1);
    Notifier notify2(n2);
    Notifier notify3(n3);

    vector<Notifier> system;
    system.push_back(notify1);
    system.push_back(notify2);
    system.push_back(notify3);

    for (auto &n : system)
    {
        n.notifyUser();
    }

    delete n1;
    delete n2;
    delete n3;

    return 0;
}
