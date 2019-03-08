#ifndef VIEWS_H
#define VIEWS_H

#include "observer.h"
#include "titleview.h"
#include "versionview.h"
#include "creditsview.h"
#include "observable.h"

class Views : public Observer
{
public:
    TitleView titleview;
    VersionView versionview;
    CreditsView creditsview;

    void setModel(Observable&a);
    void update(void*a);

};

#endif // VIEWS_H
