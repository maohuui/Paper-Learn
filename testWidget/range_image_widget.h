#ifndef RANGE_IMAGE_WIDGET_H
#define RANGE_IMAGE_WIDGET_H

#include <QWidget>

#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/range_image/range_image.h>    //关于深度图像的头文件
#include <pcl/io/pcd_io.h>
#include <pcl/console/parse.h>
#include <vtkRenderer.h>




typedef pcl::PointXYZ PointType;

namespace Ui
{
class RangeImageWidget;
}

class RangeImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RangeImageWidget(QWidget *parent = 0);
    ~RangeImageWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RangeImageWidget *ui;


};

#endif // RANGE_IMAGE_WIDGET_H
