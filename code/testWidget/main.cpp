#include <iostream>
#include "range_image_widget.h"
#include "form.h"
#include <QApplication>
//主函数
int main (int argc, char** argv)
{
    QApplication a(argc,argv);

    RangeImageWidget w;
    //Form w;

    w.show();
    return a.exec();
}
