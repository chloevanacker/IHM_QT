#include "model.h"


Model::Model()
{

}

Model::~Model()
{
}


void Model::load_image_file(QString file_name)
{
    //Quand on ouvre une image, on l'ouvre à la fin (dans la dernière sub_window)
    int index_of_new_sub_window = this->controller->view->sub_windows.size()-1;
    QLabel* picture_container = new QLabel;

    //On ouvre l'image (le fichier) dans un pixmap et on l'ajoute dans le vecteur pour garder la liste
    QPixmap* pixmap = new QPixmap(file_name);
    this->controller->pixmaps.push_back(pixmap);

    //On met le pixmap dans un label qu'on met dans la sub_window
    picture_container->setPixmap(*(this->controller->pixmaps[index_of_new_sub_window]));
    this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(picture_container);
    this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);

}

void Model::load_video_file(QString file_name)
{
    //Quand on ouvre une vidéo, on l'ouvre à la fin (dans la dernière sub_window)
    int index_of_new_sub_window = this->controller->view->sub_windows.size()-1;

    //On ne veut pas convertir la vidéo, uniquement l'ouvrir
    bool flag_convert = false;

    //On crée un QMediaPlayer qui va prendre comme Media le fichier et qu'on ajoute dans le vecteur de video_player
    QMediaPlayer* video_player = new QMediaPlayer;
    this->controller->videos.push_back(video_player);
    video_player->setMedia(QUrl::fromLocalFile(file_name));

    //On crée une VideoSurface qu'on ajoute dans un vecteur de video_surface
    //On met la sortie du QMediaPlayer vers la VideoSurface
    VideoSurface* video_surface = new VideoSurface(flag_convert);
    this->controller->video_surfaces.push_back(video_surface);
    video_surface->controller = this->controller;
    video_player->setVideoOutput(video_surface);

    //On lit la vidéo et affiche la sub_window correspondante
    video_player->play();
    this->controller->view->sub_windows[index_of_new_sub_window]->setWidget(video_surface->frame_container);
    this->controller->view->sub_windows[index_of_new_sub_window]->setAccessibleName(file_name);

    QSize size = video_surface->frame_container->size();
    this->controller->view->sub_windows[index_of_new_sub_window]->widget()->setFixedSize(size);

}


void Model::save_file(QString file_name, int index)
{
    //Si le fichier est un PNG, on le sauvegarde en PNG dans le fichier déjà existant
    if(file_name.toLower().endsWith(".png"))
    {
        this->controller->pixmaps[index]->save(file_name, "PNG");
    }


    //Si le fichier est un JPG ou un JPEG, on le sauvegarde en JPG dans le fichier déjà existant
    else if (file_name.toLower().endsWith(".jpg") || file_name.endsWith(".jpeg"))
    {
        this->controller->pixmaps[index]->save(file_name, "JPG");
    }

    /*else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
    {
        CvCapture* capture = 0;
        capture = cvCreateFileCapture(file_name.toStdString().c_str());
        if(!capture)
        {
            return;
        }
        IplImage *bgr_frame=cvQueryFrame(capture);//Init the video read
        double fps = cvGetCaptureProperty (capture,CV_CAP_PROP_FPS);

        CvSize size = cvSize((int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT));
        CvVideoWriter *writer = cvCreateVideoWriter("/home/pva/IHM_QT/videos/z.avi",CV_FOURCC_DEFAULT,fps,size);

        IplImage *grayScaleImage = cvCreateImage(size ,IPL_DEPTH_8U,1);



        while( (bgr_frame=cvQueryFrame(capture)) != NULL )
        {

            cvCvtColor(bgr_frame, grayScaleImage, CV_BGR2GRAY);
            cvWriteFrame( writer, grayScaleImage );


        }

        cvReleaseVideoWriter( &writer );
        cvReleaseCapture( &capture );
    }*/
}

void Model::save_as_file(QString file_name, int index)
{
    //On crée un nouveau fichier
    QFile file(file_name);
    file.open(QIODevice::WriteOnly);

    //Si le fichier est un PNG on l'enregistre dans le nouveau fichier en format PNG
    if(file_name.toLower().endsWith(".png"))
    {
        this->controller->pixmaps[index]->save(&file, "PNG");
    }

    //Si le fichier est un JPG ou JPEG on l'enregistre dans le nouveau fichier en format JPG
    else if (file_name.toLower().endsWith(".jpg") || file_name.endsWith(".jpeg"))
    {
        this->controller->pixmaps[index]->save(&file, "JPG");
    }

    /*else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
    {

    }*/

    file.close();
}
