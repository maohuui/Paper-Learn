#include "application.h"

Application::Application()
{
    views.setModel(model);
    controller.setModel(model);
    model.notifyObservers();
}

void Application::run()
{
    controller.MessageLoop();
}
