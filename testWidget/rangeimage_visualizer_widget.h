

#include <pcl/pcl_config.h>

#ifndef PCL_VISUALIZATION_RANGE_IMAGE_VISUALIZER_H_
#define PCL_VISUALIZATION_RANGE_IMAGE_VISUALIZER_H_

// PCL includes
#include <pcl/range_image/range_image.h>
#include <pcl/visualization/image_viewer.h>

namespace pcl
{
namespace visualization
{
class PCL_EXPORTS RangeImageVisualizer : public ImageViewer
{
public:
    // =====CONSTRUCTOR & DESTRUCTOR=====
    //! Constructor
    RangeImageVisualizer (const std::string& name="Range Image");
    //! Destructor
    ~RangeImageVisualizer ();

    // =====PUBLIC STATIC METHODS=====
    /** Get a widget visualizing the given range image.
     *  You are responsible for deleting it after usage! */
    static RangeImageVisualizer* getRangeImageWidget (const pcl::RangeImage& range_image, float min_value,
            float max_value, bool grayscale, const std::string& name="Range image");

    /** Visualize the given range image and the detected borders in it.
     *  Borders on the obstacles are marked green, borders on the background are marked bright blue. */
    void visualizeBorders (const pcl::RangeImage& range_image, float min_value, float max_value, bool grayscale,
                           const pcl::PointCloud<pcl::BorderDescription>& border_descriptions);

    /** Same as above, but returning a new widget. You are responsible for deleting it after usage! */
    static RangeImageVisualizer* getRangeImageBordersWidget (const pcl::RangeImage& range_image, float min_value,
            float max_value, bool grayscale, const pcl::PointCloud<pcl::BorderDescription>& border_descriptions,
            const std::string& name="Range image with borders");

    /** Get a widget visualizing the given angle image (assuming values in (-PI, PI]).
     *  -PI and PI will return the same color
     *  You are responsible for deleting it after usage! */
    static RangeImageVisualizer* getAnglesWidget (const pcl::RangeImage& range_image, float* angles_image, const std::string& name);

    /** Get a widget visualizing the given angle image (assuming values in (-PI/2, PI/2]).
     *  -PI/2 and PI/2 will return the same color
     *  You are responsible for deleting it after usage! */
    static RangeImageVisualizer* getHalfAnglesWidget (const pcl::RangeImage& range_image, float* angles_image, const std::string& name);


    /** Get a widget visualizing the interest values and extracted interest points.
     * The interest points will be marked green.
     *  You are responsible for deleting it after usage! */
    static RangeImageVisualizer* getInterestPointsWidget (const pcl::RangeImage& range_image, const float* interest_image, float min_value, float max_value,
            const pcl::PointCloud<pcl::InterestPoint>& interest_points, const std::string& name);

    // =====PUBLIC METHODS=====
    //! Visualize a range image
    /* void  */
    /* setRangeImage (const pcl::RangeImage& range_image,  */
    /*                float min_value = -std::numeric_limits<float>::infinity (),  */
    /*                float max_value =  std::numeric_limits<float>::infinity (),  */
    /*                bool grayscale  = false); */

    void
    showRangeImage (const pcl::RangeImage& range_image,
                    float min_value = -std::numeric_limits<float>::infinity (),
                    float max_value =  std::numeric_limits<float>::infinity (),
                    bool grayscale  = false);

protected:
    // =====PROTECTED MEMBER VARIABLES=====
    std::string name_;
};
}
}

#endif  //#define PCL_VISUALIZATION_RANGE_IMAGE_VISUALIZER_H_
