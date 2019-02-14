#include<queue>
using namespace std;

template<class T1, class T2>
class MessageBlock
{
public:
    MessageBlock(T1* t_block, T2* t_event)
        : t_event_(t_event)
        , t_block_(t_block)
    {
    };

    T1* GetData()
    {
        return t_block_;
    }

    T2* GetEvent()
    {
        return t_event_;
    }

private:
    T1* t_block_;
    T2* t_event_;
};

template<class T>
class MessageQueue
{
public:
    MessageQueue() {}
    void EnQueue(T t_)
    {
        message_block_.push(t_);
    }

    T& PopQueue()
    {
        if (!message_block_.empty())
        {
            T& t = message_block_.front();
            message_block_.pop();
            return t;
        }
    }

    bool IsEmpty()
    {
        return message_block_.empty();
    }

    bool GetSize()
    {
        return message_block_.size();
    }

private:
    std::queue<T> message_block_;
};