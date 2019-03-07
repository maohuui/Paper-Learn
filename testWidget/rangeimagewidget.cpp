#include <pcl/visualization/range_image_visualizer.h>




class RangeImageWidget : public pcl::visualization::RangeImageVisualizer
{
private:
    vtkRenderWindowInteractor *Interactor;
    // vtkImageViewer2* viewer;
    vtkInteractorStyleImage* style;

public:
    static RangeImageWidget *New()
    {
        return new RangeImageWidget;
    }

    RangeImageWidget()//构造函数
    {
        this->Interactor = 0;
    }

    void SetInteractorStyle(vtkInteractorStyleImage* style)
    {
        this->style = style;
    }

    void SetInteractor(vtkRenderWindowInteractor *interactor)
    {
        this->Interactor = interactor;
    }

    vtkRenderWindowInteractor *GetInteractor()
    {
        return this->Interactor;
    }
    void setupInterator(vtkRenderWindowInteractor *iren,vtkRenderWindow *win)
    {
        win->AlphaBitPlanesOff();
        win->PointSmoothingOff();
        win->LineSmoothingOff();
        win->PolygonSmoothingOff();
        win->SetStereoTypeToAnaglyph();

        iren->SetRenderWindow(win);
        iren->SetInteractorStyle(style);
        iren->SetDesiredUpdateRate(30.0);

        iren->Initialize();
    }
};
