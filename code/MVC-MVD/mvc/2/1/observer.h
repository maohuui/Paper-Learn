#ifndef OBSERVER_H
#define OBSERVER_H
#include<iostream>
#include<vector>

//get namespace related stuff
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::vector;

class Observer
{
public:
    virtual void update(void*)=0;
};

#endif // OBSERVER_H
