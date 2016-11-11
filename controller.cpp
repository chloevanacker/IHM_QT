#include "controller.h"

Controller::Controller()
{

}

void Controller::open()
{
    QStringList file_names = this->view->display_open_box();

    if(!file_names.isEmpty())
    {
        for (int i = 0; i < file_names.size(); i++)
        {
            this->view->add_sub_window();
            this->model->load_file(file_names[i]);
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

void Controller::convert()
{
    int number_of_sub_windows = this->view->sub_windows.size();
    for(int index = 0; index < number_of_sub_windows; index++)
    {
        QString file_name = this->view->sub_windows[index]->accessibleName();

        if(file_name.toLower().endsWith(".png") || file_name.toLower().endsWith(".jpg") || file_name.toLower().endsWith(".jpeg"))
        {
            QImage picture = this->pixmaps[index]->toImage();

            for (int height = 0; height < picture.height(); height++)
            {
                uchar* scan = picture.scanLine(height);
                int depth = 4;
                for (int width = 0; width < picture.width(); width ++)
                {
                    QRgb* rgb_pixels = reinterpret_cast<QRgb*>(scan+ width*depth);
                    int gray = qGray (*rgb_pixels);
                    *rgb_pixels = QColor(gray, gray, gray).rgba();
                    picture.setPixel(width, height, *rgb_pixels);
                    if (gray)
                    {
                        int z = 0;
                        z++;
                    }
                }
            }

            QLabel* picture_container = new QLabel;
            *(this->pixmaps[index]) = this->pixmaps[index]->fromImage(picture);
            picture_container->setPixmap(*this->pixmaps[index]);
            this->view->sub_windows[index]->setWidget(picture_container);
            this->view->display_sub_window(index);
        }

        else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
        {
            QUrl url = this->videos[index]->media().canonicalUrl();
            this->videos[index]->stop();
            delete this->videos[index];
            QMediaPlayer* video_container = new QMediaPlayer;
            this->videos[index] = video_container;
            this->videos[index]->setMedia(url);
            VideoSurface* video_surface = new VideoSurface;
            this->videos[index]->setVideoOutput(video_surface);
            this->videos[index]->play();
        }
    }
}

void Controller::assemble()
{

    int max_height=this->view->sub_windows.at(0)->pos().ry()+pixmaps.at(0)->height();
    int max_width=this->view->sub_windows.at(0)->pos().rx()+pixmaps.at(0)->width();

    for(unsigned int i=1; i < pixmaps.size(); i++)
    {
        if(this->view->sub_windows.at(i)->pos().ry()+pixmaps.at(i)->height()>max_height)
            max_height=this->view->sub_windows.at(i)->pos().ry()+pixmaps.at(i)->height();

        if(this->view->sub_windows.at(i)->pos().rx()>max_width  || this->view->sub_windows.at(i)->pos().rx()+pixmaps.at(i)->width()>max_width)
            max_width=this->view->sub_windows.at(i)->pos().rx()+pixmaps.at(i)->width();
    }

    int min_height=this->view->sub_windows.at(0)->pos().ry();
    int min_width=this->view->sub_windows.at(0)->pos().rx();

    for( unsigned int i=1; i < pixmaps.size(); i++)
    {
        if(this->view->sub_windows.at(i)->pos().ry()<min_height)
                    min_height=this->view->sub_windows.at(i)->pos().ry();

        if(this->view->sub_windows.at(i)->pos().rx()<min_width)
                    min_width=this->view->sub_windows.at(i)->pos().rx();
    }

    QImage resultImage(max_width-min_width, max_height-min_height, QImage::Format_RGB32);
    QPainter painter;

    painter.begin(&resultImage);

    for(unsigned int i=0; i < pixmaps.size(); ++i)
    {

            painter.drawImage(this->view->sub_windows.at(i)->pos().rx()-min_width, this->view->sub_windows.at(i)->pos().ry()-min_height, pixmaps.at(i)->toImage(), 0, 0, max_width-min_width, max_height-min_height, Qt::AutoColor);

    }
    painter.end();

    //ATTENTION supprime la dernière fenetre
    QLabel* resultcontainer = new QLabel;

    *(this->pixmaps[pixmaps.size()-1]) = this->pixmaps[pixmaps.size()-1]->fromImage(resultImage);
    resultcontainer->setPixmap(*this->pixmaps[pixmaps.size()-1]);
    this->view->sub_windows[pixmaps.size()-1]->setWidget(resultcontainer);
    this->view->sub_windows[pixmaps.size()-1]->adjustSize();
    this->view->sub_windows[pixmaps.size()-1]->maximumSize();
    this->view->sub_windows[pixmaps.size()-1]->show();


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
