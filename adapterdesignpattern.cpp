#include <iostream>
#include <memory>
using namespace std;

class PaymentGateway {
public:
    virtual void pay(const string& orderid, double amount) = 0;
    virtual ~PaymentGateway() {}
};

class PayuGateway : public PaymentGateway {
public:
    void pay(const string& orderid, double amount) override {
        cout << "Paid " << amount << " and order ID is " << orderid << endl;
    }
};

class CheckoutService {
private:
    PaymentGateway* paymentgateway; // use pointer for polymorphism

public:
    CheckoutService(PaymentGateway* gateway) : paymentgateway(gateway) {}

    void checkout(const string& orderid, double amount) {
        paymentgateway->pay(orderid, amount);
    }

    ~CheckoutService() {
        delete paymentgateway;
    }
};

int main() {
    CheckoutService checkservice(new PayuGateway());
    checkservice.checkout("12", 56.0);
    return 0;
}
