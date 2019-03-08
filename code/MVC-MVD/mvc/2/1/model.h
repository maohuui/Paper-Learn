#ifndef MODEL_H
#define MODEL_H

#include "observable.h"

class Model: public Observable
{
public:
    string title_caption;
    string version_caption;
    string credits_caption;
    string title;
    string version;
    string credits;

    Model(): title_caption("Title: ")
        , version_caption("Version: ")
        , credits_caption("Credits: ")
        , title("Simple Model-View-Controller Implementation")
        , version("0.2")
        , credits("(put your name here)")
    {

    }

    string getCredits_Caption()
    {
        return credits_caption;
    }
    string getTitle_Caption()
    {
        return title_caption;
    }
    string getVersion_Caption()
    {
        return version_caption;
    }

    string getCredits()
    {
        return credits;
    }
    string getTitle()
    {
        return title;
    }
    string getVersion()
    {
        return version;
    }
    void setCredits(string a)
    {
        credits=a;
        notifyObservers();
    }
    void setTitle(string a)
    {
        title=a;
        notifyObservers();
    }
    void setVersion(string a)
    {
        version=a;
        notifyObservers();
    }
};


#endif // MODEL_H
