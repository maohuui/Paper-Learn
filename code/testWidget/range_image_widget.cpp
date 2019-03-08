#include "range_image_widget.h"
#include "ui_range_image_widget.h"
#include <pcl/visualization/range_image_visualizer.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageSlice.h>
#include <vtkPointPicker.h>


RangeImageWidget::RangeImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RangeImageWidget)
{
    ui->setupUi(this);

}

RangeImageWidget::~RangeImageWidget()
{
    delete ui;
}
void RangeImageWidget::on_pushButton_clicked()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>); // 创建点云（指针）

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("test1.pcd", *cloud) == -1) { //* 读入PCD格式的文件，如果文件不存在，返回-1
        PCL_ERROR("Couldn't read file test_pcd.pcd \n"); //文件不存在时，返回错误，终止程序。

    }
    //    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");//直接创造一个显示窗口
    //    viewer.showCloud(cloud);//再这个窗口显示点云
    //    while (!viewer.wasStopped()) {
    //    }
//    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
//    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
//    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
//    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
//    ui->qvtkWidget->update ();
//    viewer->addPointCloud (cloud, "cloud");
//    viewer->resetCamera ();

    float angularResolution = (float) (  1.0f * (M_PI/180.0f));  //   1.0 degree in radians
    //max_angle_width为模拟的深度传感器的水平最大采样角度，
    float maxAngleWidth     = (float) (360.0f * (M_PI/180.0f));  // 360.0 degree in radians
    //max_angle_height为模拟传感器的垂直方向最大采样角度  都转为弧度
    float maxAngleHeight    = (float) (180.0f * (M_PI/180.0f));  // 180.0 degree in radians
    //传感器的采集位置
    Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f(0.0f, 0.0f, 0.0f);
    //深度图像遵循坐标系统
    pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
    float noiseLevel=0.00;    //noise_level获取深度图像深度时，近邻点对查询点距离值的影响水平
    float minRange = 0.0f;     //min_range设置最小的获取距离，小于最小获取距离的位置为传感器的盲区
    int borderSize = 1;        //border_size获得深度图像的边缘的宽度

    pcl::RangeImage rangeImage;
    rangeImage.createFromPointCloud(*cloud, angularResolution, maxAngleWidth, maxAngleHeight,
                                    sensorPose, coordinate_frame, noiseLevel, minRange, borderSize);

    pcl::visualization::RangeImageVisualizer rangeWidget("viewer");
    rangeWidget.showRangeImage(rangeImage);

//   float* ranges = rangeImage.getRangesArray ();
//   rangeWidget.showFloatImage(ranges, rangeImage.width, rangeImage.height);

//    while (!rangeWidget.wasStopped()) {
//        rangeWidget.spinOnce();
//        // Sleep 100ms to go easy on the CPU.
//        pcl_sleep(0.1);
//    }

//    vtkSmartPointer<vtkRenderWindowInteractor> interactor_ = vtkSmartPointer <vtkRenderWindowInteractor>::New ();
//    vtkSmartPointer<vtkRenderWindow> win_ = vtkSmartPointer<vtkRenderWindow>::New ();
//    vtkSmartPointer<vtkInteractorStyle> style = vtkSmartPointer<vtkInteractorStyle>::New ();



    //Setup window
    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();
    //Setup renderer
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);
    ui->qvtkWidget->SetRenderWindow(renderWindow);//make the link between VTK and QT
    //create stuff for user interaction
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    /*
     vtkSmartPointer<vtkUserInteractionStyle> inter = vtkUserInteractionStyle::New ();
     inter->SetDefaultRenderer(renderer);
     renderWindowInteractor->SetInteractorStyle( inter );
    */
    //make the link between the renderwindow and the interactor
    //renderWindowInteractor->SetRenderWindow ( renderWindow );
    // ui->qvtkWidget->show();
    //renderWindow->Render ();
    renderWindowInteractor->Initialize();



    // win_->SetInteractor(ui->qvtkWidget->GetRenderWindow()->GetInteractor());

    //win_->Render ();
    // interactor_->Initialize();

//    win_->SetInteractor(interactor_);
//    ui->qvtkWidget->SetRenderWindow(win_);
//    interactor_->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());



//    interactor_->SetInteractorStyle(style);
//    ui->qvtkWidget->SetRenderWindow(win_);
//    ui->qvtkWidget->GetRenderWindow()->SetInteractor(interactor_);



    //  rangeWidget.setInteractorStyle(interactor_->GetInteractorStyle());


    ui->qvtkWidget->update();

}
