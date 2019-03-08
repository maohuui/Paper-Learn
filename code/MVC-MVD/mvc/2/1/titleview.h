#ifndef TITLEVIEW_H
#define TITLEVIEW_H
#include "observer.h"
#include "model.h"

class TitleView : public Observer
{
public:
    void update(void*a)
    {
        cout<<static_cast<Model*>(a)->getTitle_Caption();
        cout<<static_cast<Model*>(a)->getTitle();
        cout<<endl;
    }
};

#endif // TITLEVIEW_H
