#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Order
{
private:
    std::vector<std::string> items;
    std::vector<int> quantities;
    std::vector<double> prices;
    std::string status;

public:
    Order() : status("open") {}

    void addItem(const string &name, int quantity, double price)
    {
        items.push_back(name);
        quantities.push_back(quantity);
        prices.push_back(price);
    }

    double totalPrice() const
    {
        double total = 0;
        for (size_t i = 0; i < prices.size(); ++i)
        {
            total += quantities[i] * prices[i];
        }
        return total;
    }

    void setStatus(const string &newStatus)
    {
        status = newStatus;
    }

    const string &getStatus() const
    {
        return status;
    }
};

class PaymentProcessor
{
public:
    virtual void pay()
    {
    }
};

class DebitProcessor : public PaymentProcessor
{
public:
    void pay(Order &order, const string &securityCode)
    {
        cout << "Processing debit payment type" << endl;
        cout << "Verifying security code: " << securityCode << endl;
        order.setStatus("paid");
    }
};

class CreditProcessor : public PaymentProcessor
{
public:
    void pay(Order &order, const string &securityCode)
    {
        cout << "Processing credit payment type" << endl;
        cout << "Verifying security code: " << securityCode << endl;
        order.setStatus("paid");
    }
};

class UPIProcessor : public PaymentProcessor
{
public:
    void pay(Order &order, const string &securityCode)
    {
        cout << "Processing UPI payment type" << endl;
        cout << "Verifying security code: " << securityCode << endl;
        order.setStatus("paid");
    }
};

int main()
{
    Order order;
    order.addItem("Keyboard", 1, 50);
    order.addItem("SSD", 1, 150);
    order.addItem("USB cable", 2, 5);

    cout << order.totalPrice() << endl;

    DebitProcessor debit;
    debit.pay(order, "0372846");
    cout<<endl<<endl;

    CreditProcessor credit;
    credit.pay(order, "729999");
    cout<<endl<<endl;

    UPIProcessor upi;
    upi.pay(order, "155674");
    cout<<endl<<endl;

    return 0;
}
