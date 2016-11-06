#include "model.h"

Model::Model()
{
}

void Model::load_file(QString file_name)
{
    int index_of_new_sub_window = this->controller->view->sub_windows.size()-1;

    if(file_name.toLower().endsWith(".png") || file_name.toLower().endsWith(".jpg") || file_name.toLower().endsWith(".jpeg"))
    {
        QLabel* picture_container = new QLabel;
        QPixmap* pixmap = new QPixmap(file_name);
        this->controller->pixmaps.push_back(pixmap);
        picture_container->setPixmap(*(this->controller->pixmaps[index_of_new_sub_window]));
        this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(picture_container);
        this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);
    }

     else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
     {
        QVideoWidget* video_container = new QVideoWidget;
        QMediaPlayer* video_player = new QMediaPlayer;
        this->controller->videos.push_back(video_player);
        video_player->setMedia(QUrl::fromLocalFile(file_name));
        video_player->setVideoOutput(video_container);
        video_player->state();
        video_player->mediaStatus();
        this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(video_container);
        this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);
        QSize size= video_container->size();
        this->controller->view->sub_windows[index_of_new_sub_window]->widget()->setFixedSize(size);
        video_player->play();

     }
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

