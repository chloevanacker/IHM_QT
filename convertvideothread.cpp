#include "convertvideothread.h"
#include "header.h"
#include "videosurface.h"

ConvertVideoThread::ConvertVideoThread(QObject *parent, Controller* controller, QMediaPlayer* video_player, VideoSurface* video_surface) : QThread(parent)
{
    //On initialise les attributs
    this->controller = controller;
    this->video_player = video_player;
    this->video_surface = video_surface;
    this->video_surface->controller = this->controller;
}


void ConvertVideoThread::run()
{


    //qDebug()<<QString("Thread debut");

    //Preuve que les threads fonctionnent bien en meme temps
    // for(int a=0;a<100;a++)
    // {
    //    qDebug()<<QString("%1").arg(a);
    //}

    //On met le flag_convert a true pour indiquer qu'on veut convertir la vidéo
    this->video_surface->flag_convert = true;

    //qDebug()<<QString("Thread fin");

}
