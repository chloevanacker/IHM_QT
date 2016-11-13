#ifndef Controller_H
#define Controller_H

#include "model.h"
#include "view.h"
#include "header.h"
#include "project.h"
#include "videosurface.h"
#include "playitem.h"
#include "convertimagethread.h"
#include "convertvideothread.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();

public:
    View* view;
    Model* model;
    ConvertImageThread *convertimagethread;


public:
    std::vector<QPixmap*> pixmaps;
    std::vector<QMediaPlayer*> videos;
    std::vector<VideoSurface*> video_surfaces;
    std::vector<QImage> videos_frames_pictures;
    std::vector <PlayItem> playlist;
    std::vector<ConvertImageThread*> vector_threads_images;
    std::vector<ConvertVideoThread*> vector_threads_videos;
    unsigned int index_of_playlist;

public:
    /*Declaration of all the functions linked to the actions*/

    void open();
    void save();
    void save_as();
    void convert();
    void assemble();
    void undo();
    void redo();
    void help();
    void about();
    void conversion(QImage* picture);

public slots:
    void media_state_changed(QMediaPlayer::MediaStatus state);
};

#endif // Controller_H
