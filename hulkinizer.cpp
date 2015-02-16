#include "hulkinizer.h"

HULKINIZER::HULKINIZER() :
    clasif(new CascadeClassifier("haarcascade_frontalface_alt2.xml"))
{

}

HULKINIZER::~HULKINIZER()
{
    delete clasif;
}




Mat HULKINIZER::run(Mat image, int TYPE)
{
    clasif->detectMultiScale(image,vector_detecciones,1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT, Size(30, 30), Size(200,200));
    vector<Mat> canalesIm;
    split(image,canalesIm);

    //        for (int i=0;i<detecciones_vector.size();i++)
    //        {
    //            vector<Mat> canalesIm;
    //            split(myImage,canalesIm);
    //            canalesIm[1](detecciones_vector[i]) = 2*canalesIm[1](detecciones_vector[i]);
    //        }


    if (TYPE == Hulk)
    {
        for (int i=0;i<vector_detecciones.size();i++)
        {
            Mat face = canalesIm[1](vector_detecciones[i]);
            face = 2*face;
        }
    }
    else if (TYPE == DrManhattan)
    {
        for (int i=0;i<vector_detecciones.size();i++)
        {
            Mat face = canalesIm[0](vector_detecciones[i]);
            face = 2*face;
        }
    }
    else if (TYPE == HellBoy)
    {
        for (int i=0;i<vector_detecciones.size();i++)
        {
            Mat face = canalesIm[2](vector_detecciones[i]);
            face = 2*face;
        }
    }

    merge(canalesIm,image);

    //    for (int i=0;i<detecciones_vector.size();i++)
    //        rectangle(image,detecciones_vector[i],CV_RGB(255,0,0));

    addDetections(image);

    return image;
}

void HULKINIZER::addDetections(Mat &im)
{
    for (int i=0;i<vector_detecciones.size();i++)
        rectangle(im,vector_detecciones[i],CV_RGB(255,0,0));
}

