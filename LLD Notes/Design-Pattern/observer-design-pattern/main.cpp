#include <iostream>
#include <list>

class SubscriberNotification
{
public:
    virtual void notify(std::string notification) = 0;
};

class User : public SubscriberNotification
{
private:
    int userId;

public:
    User(int userId)
    {
        this->userId = userId;
    }

    void notify(std::string notification)
    {
        std::cout << "User: " << userId << " " << notification << "\n";
    }
};

class Group
{
private:
    std::list<SubscriberNotification *> subscribers;

public:
    void subscribe(SubscriberNotification *newUser)
    {
        subscribers.push_back(newUser);
    }

    void unsubscribe(SubscriberNotification *user)
    {
        subscribers.remove(user);
    }

    void notify(std::string msg)
    {
        for (auto it : subscribers)
        {
            it->notify(msg);
        }
    }
};

int main()
{

    // channel
    Group *g1 = new Group();

    // users
    User *u1 = new User(1);
    User *u2 = new User(2);
    User *u3 = new User(3);

    g1->subscribe(u1);
    g1->subscribe(u2);
    g1->subscribe(u3);

    g1->notify("NEW MESSAGE ALL USERS ARE HERE");

    g1->unsubscribe(u2);

    g1->notify("KICKED USER 2 heheehe");

    delete g1;
    delete u1;
    delete u2;
    delete u3;
    return 0;
}