#include <functional>
#include <iostream>
#include "../../MessageQueue/MessageQueue.hpp"

using namespace std;

template<typename ListenerType>
class Listener
{
public:
    Listener() {};

    typedef function<void(int)> CallBackFunction;
    bool Register(CallBackFunction fp)
    {
        fp(1);
    }

    bool Start()
    {

    }

private:
    ListenerType type;
};



class TestListener
{
public:
    TestListener()
    {
        init();
    }

    static void print(int i)
    {
        cout << "call back" << endl;
    }

    void init()
    {
        function<void(int)> fp = bind(&TestListener::print, this, std::placeholders::_1);
        
        /*typedef Listener<int> ListenerWrape;
        ListenerWrape listener;
        listener.Register(bind(&print, this, 1));*/
    }

    
};