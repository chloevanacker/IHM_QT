#include "convertimagethread.h"
#include "header.h"


ConvertImageThread::ConvertImageThread(QObject *parent, Controller* controller, View* view, int i) : QThread(parent)
{
    this->controller = controller;
    this->view=view;
    index=i;
}



void ConvertImageThread::run( )
{

    qDebug()<<QString("Thread %1 debut").arg(index);



//    Preuve que les threads fonctionnent bien en meme temps
//     for(int a=0;a<10;a++)
//     {
//     qDebug()<<QString("%1").arg(a);
//      }


    QPixmap* pix =this->controller->pixmaps[index];
    result=pix->toImage();

    for (int height = 0; height < result.height(); height++)
    {
        uchar* scan = result.scanLine(height);
        int depth = 4;
        for (int width = 0; width < result.width(); width ++)
        {
            QRgb* rgb_pixels = reinterpret_cast<QRgb*>(scan+ width*depth);
            int gray = qGray (*rgb_pixels);
            *rgb_pixels = QColor(gray, gray, gray).rgba();
            result.setPixel(width, height, *rgb_pixels);
            if (gray)
            {
                int z = 0;
                z++;
            }

        }
    }


    qDebug()<<QString("Thread %1 fin").arg(index);


}


