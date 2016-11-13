#ifndef CONVERTVIDEOTHREAD_H
#define CONVERTVIDEOTHREAD_H

#include "header.h"

class ConvertVideoThread : public QThread
{
public:
    ConvertVideoThread();

public:
    //explicit ConvertVideoThread(QObject *parent = 0);

    explicit ConvertVideoThread(QObject *parent, Controller* controller, QMediaPlayer* video_player, VideoSurface* video_surface);

    void run();

public:

    QMediaPlayer* video_player;
    VideoSurface* video_surface;
    Controller* controller;

private:

};

#endif // CONVERTVIDEOTHREAD_H
