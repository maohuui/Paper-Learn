#include "controller.h"

Controller::Controller()
{

}

void Controller::setModel(Model&a)
{
    model=&a;
}

void Controller::MessageLoop()
{
    char c=' ';
    string s;
    while(c!='q') {
        cin>>c;
        cin.ignore(256,'\n');
        cin.clear();
        switch(c) {
        case 'c':
        case 't':
        case 'v':
            getline(cin,s);
            break;
        }
        switch(c) {
        case 'c':
            model->setCredits(s);
            break;
        case 't':
            model->setTitle(s);
            break;
        case 'v':
            model->setVersion(s);
            break;
        }
    }
}
