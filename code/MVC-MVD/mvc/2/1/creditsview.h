#ifndef CREDITSVIEW_H
#define CREDITSVIEW_H

#include "model.h"

class CreditsView: public Observer
{
public:
    void update(void*a)
    {
        cout<<static_cast<Model*>(a)->getCredits_Caption();
        cout<<static_cast<Model*>(a)->getCredits();
        cout<<endl;
    }
};


#endif // CREDITSVIEW_H
