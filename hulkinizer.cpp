#include "hulkinizer.h"

HULKINIZER::HULKINIZER() :
    clasif(new CascadeClassifier("haarcascade_frontalface_alt2.xml"))
{

}

HULKINIZER::~HULKINIZER()
{
    delete clasif;
}

Mat HULKINIZER::run(Mat image)
{
    vector<Rect> detecciones_vector;
    clasif->detectMultiScale(image,detecciones_vector,1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT, Size(30, 30), Size(200,200));
    vector<Mat> canalesIm;
    split(image,canalesIm);

    //        for (int i=0;i<detecciones_vector.size();i++)
    //        {
    //            vector<Mat> canalesIm;
    //            split(myImage,canalesIm);
    //            canalesIm[1](detecciones_vector[i]) = 2*canalesIm[1](detecciones_vector[i]);
    //        }

    for (int i=0;i<detecciones_vector.size();i++)
    {
        Mat face = canalesIm[1](detecciones_vector[i]);
        face = 2*face;
    }

    merge(canalesIm,image);

    for (int i=0;i<detecciones_vector.size();i++)
        rectangle(image,detecciones_vector[i],CV_RGB(255,0,0));

    return image;
}

