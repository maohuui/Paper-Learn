#ifndef APPLICATION_H
#define APPLICATION_H

#include "model.h"
#include "views.h"
#include "controller.h"

class Application
{
public:
    Application();
    void run();

private:
    Model model;
    Views views;
    Controller controller;
};

#endif // APPLICATION_H
