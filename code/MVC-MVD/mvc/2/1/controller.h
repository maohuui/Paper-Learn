#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller();
    void setModel(Model&a);
    void MessageLoop();

private:
    Model*model;

};

#endif // CONTROLLER_H
