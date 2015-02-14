#include <iostream>
#include "hulkinizer.h"
using namespace std;
using namespace cv;

int main()
{

    VideoCapture cam(0);

    while (1)
    {
        Mat frame;

        cam >> frame;

        cv::resize(frame,frame,Size(),0.4,0.4);
        imshow("frame",frame);
        waitKey(10);

    }
    return 0;
}

