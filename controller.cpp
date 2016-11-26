#include "controller.h"


//file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg")
//file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4")

Controller::Controller()
{

}

void Controller::open_image()
{
    QStringList file_names = this->view->display_open_box_image();

    if(!file_names.isEmpty())
    {
        for (int i = 0; i < file_names.size(); i++)
        {
            this->view->add_sub_window();
            this->model->load_image_file(file_names[i]);
            this->view->display_sub_window(this->view->sub_windows.size()-1);
        }
    }
}
void Controller::open_video()
{
    QStringList file_names = this->view->display_open_box_video();

    if(!file_names.isEmpty())
    {
        for (int i = 0; i < file_names.size(); i++)
        {
            this->view->add_sub_window();
            this->model->load_video_file(file_names[i]);
            this->view->display_sub_window(this->view->sub_windows.size()-1);
        }
    }
}

void Controller::save()
{
    unsigned int index = 0;
    for (index = 0; index < this->view->sub_windows.size(); index ++)
    {
        if(this->view->sub_windows[index] == this->view->main_area->activeSubWindow())
        {
            break;
        }
    }

    QString file_name = this->view->sub_windows[index]->accessibleName();
    if(!file_name.isEmpty())
    {
        this->model->save_as_file(file_name, index);
    }
}

void Controller::save_as()
{
    unsigned int index = 0;
    for (index = 0; index < this->view->sub_windows.size(); index ++)
    {
        if(this->view->sub_windows[index] == this->view->main_area->activeSubWindow())
        {
            break;
        }
    }

    QString file_name = this->view->display_save_as_box();
    if(!file_name.isEmpty())
    {
        this->model->save_as_file(file_name, index);
    }

}

void Controller::convert_all()
{

    int number_of_sub_windows = this->view->sub_windows.size();

    std::vector <QString> file_names;

    for (int index = 0; index < number_of_sub_windows; index ++)
    {
        file_names.push_back(this->view->sub_windows[index]->accessibleName());
    }

    //creation des threads
    for(int index =0; index <number_of_sub_windows;index++)
    {

        if(file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg"))
        {
           ConvertImageThread* new_thread_convert_image= new ConvertImageThread(NULL,this,this->view,this->pixmaps[index]);
           this->vector_threads_images.push_back(new_thread_convert_image);

        }
        else if(file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4"))
        {
            ConvertVideoThread* new_thread_convert_video = new ConvertVideoThread(NULL, this, this->videos[index], this->video_surfaces[index]);
            this->vector_threads_videos.push_back(new_thread_convert_video);

            this->vector_threads_videos[index]->controller = this;
            this->vector_threads_videos[index]->video_player = this->videos[index];
            this->vector_threads_videos[index]->video_surface = this->video_surfaces[index];
        }
    }

    //on lance les threads
    for(int index=0; index<number_of_sub_windows; index++)
    {
        if(file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg"))
        {
           this->vector_threads_images[index]->start();

        }
        else if(file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4"))
        {
            this->vector_threads_videos[index]->start();
        }
    }


    for(int index=0; index<number_of_sub_windows; index++)
    {
        if(file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg"))
        {
            this->vector_threads_images[index]->wait();//on attend que les threads finissent
            this->view->refresh_sub_window(index);

        }
        else if(file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4"))
        {
            this->vector_threads_videos[index]->wait();
        }
    }

    for(int index=0; index<number_of_sub_windows; index++)
    {
        if(file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg"))
        {
            delete this->vector_threads_images[index];
        }
        else if(file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4"))
        {
            delete this->vector_threads_videos[index];
        }
    }

    this->vector_threads_images.clear();
    this->vector_threads_videos.clear();


//    int number_of_sub_windows = this->view->sub_windows.size();
//    for(int index = 0; index < number_of_sub_windows; index++)
//    {
//        QString file_name = this->view->sub_windows[index]->accessibleName();

//        if(file_name.toLower().endsWith(".png") || file_name.toLower().endsWith(".jpg") || file_name.toLower().endsWith(".jpeg"))
//        {
//            QImage picture = this->pixmaps[index]->toImage();

//            this->conversion(&picture);

//            QLabel* picture_container = new QLabel;
//            *(this->pixmaps[index]) = this->pixmaps[index]->fromImage(picture);
//            picture_container->setPixmap(*this->pixmaps[index]);
//            this->view->sub_windows[index]->setWidget(picture_container);
//            this->view->display_sub_window(index);
//        }

//        else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
//        {
//            this->video_surfaces[index]->flag_convert = true;
//        }
//    }
}

void Controller::assemble()
{
    //Les fichiers ouverts ne sont que des videos ou que des photos
    QString file_name = this->view->sub_windows[0]->accessibleName();

    if(file_name.toLower().endsWith(".png") || file_name.toLower().endsWith(".jpg") || file_name.toLower().endsWith(".jpeg"))
    {
        QPoint sub_window_position = this->view->sub_windows[0]->pos();
        int max_height=sub_window_position.ry() + this->pixmaps[0]->height();
        int max_width=sub_window_position.rx() + this->pixmaps[0]->width();

        int min_height=sub_window_position.ry();
        int min_width=sub_window_position.rx();

        for(unsigned int i=1; i < this->pixmaps.size(); i++)
        {
            sub_window_position = this->view->sub_windows[i]->pos();
            if(sub_window_position.ry()+this->pixmaps.at(i)->height()>max_height)
            {
                max_height=sub_window_position.ry()+this->pixmaps.at(i)->height();
            }

            if(sub_window_position.rx()>max_width  || sub_window_position.rx()+this->pixmaps.at(i)->width()>max_width)
            {
                max_width=sub_window_position.rx()+this->pixmaps.at(i)->width();
            }

            if(sub_window_position.ry()<min_height)
            {
                min_height=sub_window_position.ry();
            }

            if(sub_window_position.rx()<min_width)
            {
                min_width=sub_window_position.rx();
            }
        }

        QImage result_image(max_width-min_width, max_height-min_height, QImage::Format_RGB32);
        QPainter painter;

        painter.begin(&result_image);

        for(unsigned int i=0; i < this->pixmaps.size(); i++)
        {
            QPoint sub_window_position = this->view->sub_windows[i]->pos();
            painter.drawImage(sub_window_position.rx()-min_width, sub_window_position.ry()-min_height,
                              this->pixmaps[i]->toImage(), 0, 0, max_width-min_width, max_height-min_height, Qt::AutoColor);
        }
        
        painter.end();

        for (unsigned int index = 0; index < this->view->sub_windows.size(); index ++)
        {
            this->view->hide_sub_window(index);
            delete this->view->sub_windows[index];
            delete this->pixmaps[index];
        }

        this->pixmaps.clear();
        this->view->sub_windows.clear();
        QPixmap* pixmap = new QPixmap;
        *pixmap = pixmap->fromImage(result_image);

        this->pixmaps.push_back(pixmap);

        this->view->add_sub_window();

        QLabel* result_container = new QLabel;
        result_container->setPixmap(*this->pixmaps[0]);
        this->view->sub_windows[0]->setWidget(result_container);
        this->view->sub_windows[0]->setAccessibleName("assemble.png");

        this->view->display_sub_window(0);
    }

    else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
    {
        this->index_of_playlist = 0;

        for (unsigned int index = 0; index < this->videos.size(); index ++)
        {
            PlayItem item;
            item.flag_convert = this->video_surfaces[index]->flag_convert;
            item.url = this->videos[index]->media().canonicalUrl();

            this->videos[index]->stop();
            this->view->sub_windows[index]->hide();
            this->playlist.push_back(item);
        }

        this->videos.erase(this->videos.begin(), this->videos.begin() + this->videos.size());
        this->video_surfaces.erase(this->video_surfaces.begin(), this->video_surfaces.begin() + this->video_surfaces.size());
        this->view->sub_windows.erase(this->view->sub_windows.begin(), this->view->sub_windows.begin() + this->view->sub_windows.size());


        QMediaPlayer* video_player = new QMediaPlayer;
        this->videos.push_back(video_player);
        video_player->setMedia(playlist[index_of_playlist].url);

        connect(video_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(media_state_changed(QMediaPlayer::MediaStatus)));

        VideoSurface* video_surface = new VideoSurface(false);
        this->video_surfaces.push_back(video_surface);
        video_surface->controller = this;
        video_surface->flag_convert = playlist[index_of_playlist].flag_convert;

        video_player->setVideoOutput(video_surface);
        video_player->play();

        this->view->add_sub_window();
        this->view->sub_windows[0]->setWidget(video_surface->frame_container);
        this->view->sub_windows[0]->setAccessibleName("assemble.avi");

        QSize size = video_surface->frame_container->size();
        this->view->sub_windows[0]->widget()->setFixedSize(size);

        this->view->display_sub_window(0);
    }
}

void Controller::undo()
{

}

void Controller::redo()
{

}

void Controller::help()
{
    QString title = "Help";
    QString content = "You have openned the help message box!!";
    this->view->display_message_box(title, content);
}

void Controller::about()
{
    QString title = "About";
    QString content = "Project made by NICOL Pauline, SERVOIN Arnaud, VANACKER Chloé.";
    this->view->display_message_box(title, content);
}

void Controller::conversion(QImage* picture)
{
    for (int height = 0; height < picture->height(); height++)
    {
        uchar* scan = picture->scanLine(height);
        int depth = 4;
        for (int width = 0; width < picture->width(); width ++)
        {
            QRgb* rgb_pixels = reinterpret_cast<QRgb*>(scan+ width*depth);
            int gray = qGray (*rgb_pixels);
            *rgb_pixels = QColor(gray, gray, gray).rgba();
            picture->setPixel(width, height, *rgb_pixels);
            if (gray)
            {
                int z = 0;
                z++;
            }
        }
    }
}

void Controller::media_state_changed(QMediaPlayer::MediaStatus state)
{
    if (state == QMediaPlayer::EndOfMedia)
    {
        this->index_of_playlist ++;
        if(this->index_of_playlist != this->playlist.size())
        {
            this->videos[0]->setMedia(this->playlist[this->index_of_playlist].url);
            this->video_surfaces[0]->flag_convert = this->playlist[index_of_playlist].flag_convert;
            this->videos[0]->play();
        }
        else
        {
            this->videos[0]->stop();
        }
    }
}
