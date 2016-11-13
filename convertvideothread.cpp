#include "convertvideothread.h"
#include "header.h"
#include "videosurface.h"

//ConvertVideoThread::ConvertVideoThread(QObject *parent) : QThread(parent)

ConvertVideoThread::ConvertVideoThread(QObject *parent, Controller* controller, QMediaPlayer* video_player, VideoSurface* video_surface) : QThread(parent)
{
    this->controller = controller;
    this->video_player = video_player;
    this->video_surface = video_surface;
    this->video_surface->controller = this->controller;
}


void ConvertVideoThread::run()
{
    qDebug()<<QString("Thread debut");

    this->video_surface->flag_convert = true;

    qDebug()<<QString("Thread fin");

}

