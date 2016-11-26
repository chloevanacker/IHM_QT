#include "model.h"

Model::Model()
{
}

void Model::load_image_file(QString file_name)
{
    int index_of_new_sub_window = this->controller->view->sub_windows.size()-1;

    QLabel* picture_container = new QLabel;
    QPixmap* pixmap = new QPixmap(file_name);
    this->controller->pixmaps.push_back(pixmap);
    picture_container->setPixmap(*(this->controller->pixmaps[index_of_new_sub_window]));
    this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(picture_container);
    this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);

}

void Model::load_video_file(QString file_name)
{
    int index_of_new_sub_window = this->controller->view->sub_windows.size()-1;


    bool flag_convert = false;

    QMediaPlayer* video_player = new QMediaPlayer;
    this->controller->videos.push_back(video_player);
    video_player->setMedia(QUrl::fromLocalFile(file_name));

    VideoSurface* video_surface = new VideoSurface(flag_convert);
    this->controller->video_surfaces.push_back(video_surface);
    video_surface->controller = this->controller;
    video_player->setVideoOutput(video_surface);

    video_player->play();
    this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(video_surface->frame_container);
    this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);

    QSize size = video_surface->frame_container->size();
    this->controller->view->sub_windows[index_of_new_sub_window]->widget()->setFixedSize(size);

}


void Model::save_file(QString file_name, int index)
{
    if(file_name.toLower().endsWith(".png"))
    {
        this->controller->pixmaps[index]->save(file_name, "PNG");
    }

    else if (file_name.toLower().endsWith(".jpg") || file_name.endsWith(".jpeg"))
    {
        this->controller->pixmaps[index]->save(file_name, "JPG");
    }

     /*else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4")))
     {

     }*/

}

void Model::save_as_file(QString file_name, int index)
{
    QFile file(file_name);
    file.open(QIODevice::WriteOnly);

    if(file_name.toLower().endsWith(".png"))
    {
        this->controller->pixmaps[index]->save(&file, "PNG");
    }

    else if (file_name.toLower().endsWith(".jpg") || file_name.endsWith(".jpeg"))
    {
        this->controller->pixmaps[index]->save(&file, "JPG");
    }

     /*else if(file_name.toLower().contains(tr(".avi") || file_name.toLower().endsWith(".mp4")))
     {

     }*/

    file.close();
}

