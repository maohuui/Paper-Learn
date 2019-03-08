#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

class Observable
{
public:

    void addObserver(Observer*a)
    {
        observers.push_back(a);
    }

    void notifyObservers()
    {
        for (vector<Observer*>::const_iterator observer_iterator=observers.begin();
             observer_iterator!=observers.end();
             observer_iterator++)
            (*observer_iterator)->update(this);
    }
private:
    vector<Observer*>observers;
};


#endif // OBSERVABLE_H
