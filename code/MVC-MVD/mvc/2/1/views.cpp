#include "views.h"

void Views::setModel(Observable &a)
{
    a.addObserver(&titleview);
    a.addObserver(&versionview);
    a.addObserver(&creditsview);
    a.addObserver(this);
}

//update
void Views::update(void* /*a*/)
{
    cout<<"_____________________________";
    cout<<"\nType t to edit Title, ";
    cout<<"v to edit Version, ";
    cout<<"c to edit Credits. ";
    cout<<"Type q to quit./n>>";
}

