#include "form.h"
#include "ui_form.h"
#include <pcl/common/common_headers.h>

#include <pcl/range_image/range_image_planar.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>      //PCL可视化的头文件
#include <pcl/console/parse.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/visualization/range_image_visualizer.h>
#include <QFile>
#include <QTextStream>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
//    int width  = 328;
//    int height = 252;
//    int **dataPixelfield;

//    double alfa0 = 45 * 3.14159 / 180;  //45 grad
//    double step = alfa0 / (width / 2);
//    double beta0 = step * (height / 2);
//    double alfa, beta;

//    dataPixelfield = new int*[328];
//    for (int i = 0; i < 328; i++) {
//        dataPixelfield[i] = new int[252]; //
//    }
//    for (int x = 0; x < 328; x++) {
//        for (int y = 0; y < 252; y++) {
//            dataPixelfield[x][y] = -1;
//        }
//    }


//    QFile fp("test.txt");
//    QVector<int> array;

//    if(fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        QTextStream ts(&fp);
//        while(!ts.atEnd()) {
//            int buf;
//            ts>>buf;
//            array.append(buf);
//        }
//        fp.close();
//    }
//    //int size = array.size();
//    int i = 0;
//    for (int x = 0; x < 328; x++) {
//        for (int y = 0; y < 252; y++) {
//            dataPixelfield[x][y] = array.at(i);
//            i++;
//        }
//    }

//    pcl::PointCloud<pcl::PointXYZ> cloud;

//    for(int y = 0; y < height; y++) {
//        beta = y * step - beta0;
//        for(int x = 0; x < width; x++ ) {
//            alfa = x * step - alfa0;
//            int rcm = dataPixelfield[x][y];
//            double beta1 = beta; //* f(y); TODO... lens distortion
//            double alfa1 = alfa; //* f(x);

//            pcl::PointXYZ point;
//            point.x = rcm * cos(beta1) * sin(alfa1);
//            point.y = rcm * sin(beta1);
//            point.z = rcm * cos(alfa) * cos(beta);
//            cloud.points.push_back(point); //循环添加点数据到点云对象
//        }
//    }
//    cloud.width = cloud.points.size();
//    cloud.height = 1;
//    // cloud.points.resize (cloud.width * cloud.height);  //点云总数大小
//    pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);

//    for (int i=0; i<328; i++) {
//        delete[] dataPixelfield[i]; //先撤销指针元素所指向的数组
//    }
//    delete[] dataPixelfield;


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // Object for storing the normals.
    // Read a PCD file from disk.
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("test_pcd.pcd", *cloud) != 0) {
        return ;
    }
    Eigen::Matrix4f T;
    T << 1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 500,
    0, 0, 0, 1;
    Eigen::Matrix4f T1;
    T1 << 0, -1, 0, 0,
    1, 0, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1;
    Eigen::Affine3f Traw(T*T1);

    int imageSizeX = 1500;
    int imageSizeY = 1500;
    float centerX = imageSizeX / 2.0f;
    float centerY = imageSizeY / 2.0f;

    float focalLengthX = 800.0f, focalLengthY = focalLengthX;
    Eigen::Affine3f sensorPose = Traw;// Eigen::Affine3f(Eigen::Translation3f(0, 0, 0));
    float noiseLevel = 0.0f;
    float minimumRange = 0.0f;

    // Planar range image object.
    pcl::RangeImagePlanar rangeImagePlanar;
    rangeImagePlanar.createFromPointCloudWithFixedSize(*cloud, imageSizeX, imageSizeY,
            centerX, centerY, focalLengthX, focalLengthY,
            sensorPose, pcl::RangeImage::LASER_FRAME,
            noiseLevel, minimumRange);

    // Visualize the image.
    pcl::visualization::RangeImageVisualizer viewer("Planar range image");
    viewer.showRangeImage(rangeImagePlanar);
    while (!viewer.wasStopped()) {
        viewer.spinOnce();
        // Sleep 100ms to go easy on the CPU.
        pcl_sleep(0.1);
    }
}
