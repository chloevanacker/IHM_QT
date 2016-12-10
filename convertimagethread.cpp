#include "convertimagethread.h"
#include "header.h"


ConvertImageThread::ConvertImageThread(QObject *parent, Controller* controller, QPixmap* pixmap) : QThread(parent)
{
    this->controller = controller;
    result = pixmap->toImage();
}



void ConvertImageThread::run( )
{

    //qDebug()<<QString("Thread debut");



    //Preuve que les threads fonctionnent bien en meme temps
    //for(int a=0;a<100;a++)
    //{
    //    qDebug()<<QString("%1").arg(a);
    //}

    //On convertit l'image
    this->controller->conversion(&result);


    //qDebug()<<QString("Thread fin");


}

