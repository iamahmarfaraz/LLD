//  Chain of Responsiblity Design Pattern

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

class AbstractRequest{
    private:
    int requestCode;

    public:
    AbstractRequest(int code):requestCode(code){}

    int getRequestCode(){
        return requestCode;
    }

    ~ AbstractRequest(){
        cout<<"Destructor of AbstractRequest Called"<<endl;
    }
};

class PressureIssueRequest: public AbstractRequest{
    public:
    PressureIssueRequest(): AbstractRequest(303){}
};

class EngineIssueRequest: public AbstractRequest{
    public:
    EngineIssueRequest(): AbstractRequest(303){}
};

class AbstractHandler{
    protected:
    AbstractHandler *nextHandler; //pointer to next obj in COR

    public:
    AbstractHandler(AbstractHandler* next):nextHandler(next){}

    virtual void handleRequest(AbstractRequest *request){
        if (nextHandler != NULL)
        {
            nextHandler->handleRequest(request);
        }  
    }
};

class PressureIssueHandler : public AbstractHandler{
    static const int code = 303;

    public:
    PressureIssueHandler(AbstractHandler* successor):AbstractHandler(successor){}

    void handleRequest(AbstractRequest* request) override{
        if (request->getRequestCode() == code)
        {
            cout<<"Pressure Issue Handler is Handling the request"<<endl;
        }
        else{
            AbstractHandler::handleRequest(request);
        }
    }
};

class EngineIssueHandler : public AbstractHandler{
    static const int code = 304;

    public:
    EngineIssueHandler(AbstractHandler* successor):AbstractHandler(successor){}

    void handleRequest(AbstractRequest* request) override{
        if (request->getRequestCode() == code)
        {
            cout<<"Engine Issue Handler is Handling the request"<<endl;
        }
        else{
            AbstractHandler::handleRequest(request);
        }
    }
};


int main() {
    // create chain
    shared_ptr<PressureIssueHandler> pressureHandler = make_shared<PressureIssueHandler>(nullptr);
    shared_ptr<EngineIssueHandler> engineHandler = make_shared<EngineIssueHandler>(pressureHandler.get());


    // create request
    shared_ptr<PressureIssueRequest> pressureRequest = make_shared<PressureIssueRequest>();

    // handle request
    engineHandler->handleRequest(pressureRequest.get());
    // new
    return 0;
}