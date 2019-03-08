#ifndef VERSIONVIEW_H
#define VERSIONVIEW_H

#include "observer.h"

//struct VersionView, specialized Observer
class VersionView : public Observer
{
protected:
    void update(void*a)
    {
        cout<<static_cast<Model*>(a)->getVersion_Caption();
        cout<<static_cast<Model*>(a)->getVersion();
        cout<<endl;
    }
};



#endif // VERSIONVIEW_H
