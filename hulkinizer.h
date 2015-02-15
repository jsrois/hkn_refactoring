#ifndef HULKINIZER_H
#define HULKINIZER_H
#include <opencv2/opencv.hpp>
using namespace cv;

class HULKINIZER
{
    CascadeClassifier *clasif;
public:
    HULKINIZER();
    ~HULKINIZER();

    Mat run(Mat image);
};

#endif // HULKINIZER_H
