#include "controller.h"

Controller::Controller()
{

}

Controller::~Controller()
{
    for (unsigned int index = 0; index < this->pixmaps.size(); index ++)
    {
        delete this->pixmaps[index];
    }
    this->pixmaps.clear();

    for (unsigned int index = 0; index < this->videos.size(); index ++)
    {
        delete this->videos[index];
        delete this->video_surfaces[index];
    }
    videos.clear();
    video_surfaces.clear();
    playlist.clear();
}

void Controller::open_image()
{
    //On appelle la vue pour qu'elle affiche une open box, et on récupère la liste des images à ouvrir
    QStringList file_names = this->view->display_open_box_image();

    //Si la liste n'est pas vide, on la parcourt entièrement
    //Pour chaque fichier :
    //  - on ajoute une sub_window
    //  - on appelle le modèle pour qu'il charge l'image
    //  - on affiche la sub_window correspondant à l'index du fichier
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
    //On appelle la vue pour qu'elle affiche une open box, et récupère la liste des vidéos à ouvrir
    QStringList file_names = this->view->display_open_box_video();

    //Si la liste n'est pas vide, on la parcourt entièrement
    //Pour chaque fichier :
    //  - on ajoute une sub_window
    //  - on appelle le modèle pour qu'il charge la vidéo
    //  - on affiche la sub_window correspondant à l'index de la vidéo
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
    //On parcourt toutes les sub_windows et on cherche l'index de la sub_window qui est active
    unsigned int index = 0;
    for (index = 0; index < this->view->sub_windows.size(); index ++)
    {
        if(this->view->sub_windows[index] == this->view->main_area->activeSubWindow())
        {
            break;
        }
    }

    //On récupère le nom de fichier de la sub_window active, et on appelle le modèle pour sauvegarder le fichier
    QString file_name = this->view->sub_windows[index]->accessibleName();
    if(!file_name.isEmpty())
    {
        this->model->save_file(file_name, index);
    }
}

void Controller::save_as()
{
    //On parcourt toutes les sub_windows et on cherche l'index de la sub_window qui est active
    unsigned int index = 0;
    for (index = 0; index < this->view->sub_windows.size(); index ++)
    {
        if(this->view->sub_windows[index] == this->view->main_area->activeSubWindow())
        {
            break;
        }
    }

    //On appelle la vue pour récupérer le nom sous avec lequel on veut sauvegarder le fichier et on appelle le modèle pour sauvegarder le fichier
    QString file_name = this->view->display_save_as_box();
    if(!file_name.isEmpty())
    {
        this->model->save_as_file(file_name, index);
    }

}

void Controller::convert_all()
{

    int number_of_sub_windows = this->view->sub_windows.size();

    //On récupère les noms de tous les fichiers, et on les stocke dans un vecteur
    std::vector <QString> file_names;

    for (int index = 0; index < number_of_sub_windows; index ++)
    {
        file_names.push_back(this->view->sub_windows[index]->accessibleName());
    }

    //On crée un thread par sub_window:
    //  - si le fichier est un png ou un jpg ou un jpeg on ajoute un thread image dans le vecteur de thread images
    //  - si le fichier est un avi ou mp4, on ajoute un thread video dans le vecteur de thread videos
    for(int index =0; index <number_of_sub_windows;index++)
    {

        if(file_names[index].toLower().endsWith(".png") || file_names[index].toLower().endsWith(".jpg") || file_names[index].toLower().endsWith(".jpeg"))
        {
           ConvertImageThread* new_thread_convert_image= new ConvertImageThread(NULL,this,this->pixmaps[index]);
           this->vector_threads_images.push_back(new_thread_convert_image);

        }
        else if(file_names[index].toLower().endsWith(".avi") || file_names[index].toLower().endsWith(".mp4"))
        {
            ConvertVideoThread* new_thread_convert_video = new ConvertVideoThread(NULL, this, this->videos[index], this->video_surfaces[index]);
            this->vector_threads_videos.push_back(new_thread_convert_video);
        }
    }

    //On lance les threads (images si le fichier est une image ou videos si le fichier est une video)
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

    //On attend la fin de chaque thread
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

    //On libère la mémoire en supprimant les pointeurs sur les threads
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

    //On vide les vecteurs
    this->vector_threads_images.clear();
    this->vector_threads_videos.clear();
}

void Controller::assemble()
{
    //Les fichiers ouverts ne sont que d'un type: soit des photos, soit des vidéos
    QString file_name = this->view->sub_windows[0]->accessibleName();

    //Si les fichiers sont des photos
    if(file_name.toLower().endsWith(".png") || file_name.toLower().endsWith(".jpg") || file_name.toLower().endsWith(".jpeg"))
    {
        //On récupère les coordonnées des points suivants (pour déterminer la taille de l'image finale):
        //  - la coordonnée x la plus petite
        //  - la coordonnée x la plus grande
        //  - la coordonnée y la plus petite
        //  - la coordonnée y la plus grande

        //On les initialise aux coordonnées de la première image
        QPoint sub_window_position = this->view->sub_windows[0]->pos();
        int max_height=sub_window_position.ry() + this->pixmaps[0]->height();
        int max_width=sub_window_position.rx() + this->pixmaps[0]->width();
        int min_height=sub_window_position.ry();
        int min_width=sub_window_position.rx();

        //On boucle sur toutes les images, et on trouve les coordonnées recherchées en comparant
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

        //On crée l'image qui stockera le résultat et le QPainter qui dessinera l'image
        QImage result_image(max_width-min_width, max_height-min_height, QImage::Format_RGB32);
        QPainter painter;

        painter.begin(&result_image);

        //On boucle sur toutes les images, et on dessine chaque image à sa position par rapport aux coordonnées récupérées auparavant
        for(unsigned int i=0; i < this->pixmaps.size(); i++)
        {
            QPoint sub_window_position = this->view->sub_windows[i]->pos();
            painter.drawImage(sub_window_position.rx()-min_width, sub_window_position.ry()-min_height,
                              this->pixmaps[i]->toImage(), 0, 0, max_width-min_width, max_height-min_height, Qt::AutoColor);
        }

        painter.end();

        //On supprime toutes les sub_windows et tous les pixmaps pour libérer la mémoire
        for (unsigned int index = 0; index < this->view->sub_windows.size(); index ++)
        {
            this->view->hide_sub_window(index);
            delete this->view->sub_windows[index];
            delete this->pixmaps[index];
        }

        //On vide les vecteurs
        this->pixmaps.clear();
        this->view->sub_windows.clear();

        //On crée une nouvelle sub_window et un nouveau pixmap qui sont ajoutés dans les vecteurs
        QPixmap* pixmap = new QPixmap;
        *pixmap = pixmap->fromImage(result_image);

        this->pixmaps.push_back(pixmap);

        this->view->add_sub_window();

        QLabel* result_container = new QLabel;
        result_container->setPixmap(*this->pixmaps[0]);

        //On affiche la sub_window contenant l'assemblage des images
        this->view->sub_windows[0]->setWidget(result_container);
        this->view->sub_windows[0]->setAccessibleName("assemble.png");
        this->view->display_sub_window(0);
    }

    else if(file_name.toLower().endsWith(".avi") || file_name.toLower().endsWith(".mp4"))
    {
        this->index_of_playlist = 0;

        //Pour chacune des vidéos ouvertes, on crée un PlayItem, qui contient les informations sur la vidéo, et qu'on ajoute dans le vecteur playlist
        //On met la vidéo en pause et on cache la sub_window
        for (unsigned int index = 0; index < this->videos.size(); index ++)
        {
            PlayItem item;
            item.flag_convert = this->video_surfaces[index]->flag_convert;
            item.url = this->videos[index]->media().canonicalUrl();

            this->videos[index]->stop();
            this->view->sub_windows[index]->hide();
            this->playlist.push_back(item);
        }

        //On libère la mémoire de toutes les vidéos et de toutes les sub_windows
        for (unsigned int index = 0; index < this->videos.size(); index ++)
        {
            delete this->videos[index];
            delete this->video_surfaces[index];
            delete this->view->sub_windows[index];
        }

        //On vide les vecteurs de vidéos et des sub_windows
        this->videos.clear();
        this->video_surfaces.clear();
        this->view->sub_windows.clear();

        //On crée un nouveau QMediaPlayer dans lequel on lit la première vidéo
        QMediaPlayer* video_player = new QMediaPlayer;
        this->videos.push_back(video_player);
        video_player->setMedia(playlist[index_of_playlist].url);

        //Dès que que l'état du player change, on appelle la fonction media_state_changed du contrôleur
        connect(video_player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(media_state_changed(QMediaPlayer::MediaStatus)));

        //On créée une vidéo surface qui va lire la vidéo d'index index_of_playlist
        VideoSurface* video_surface = new VideoSurface(false);
        this->video_surfaces.push_back(video_surface);
        video_surface->controller = this;
        video_surface->flag_convert = playlist[index_of_playlist].flag_convert;

        video_player->setVideoOutput(video_surface);
        video_player->play();

        //On ajoute une sub_window, qui contiendra l'assemblage des vidéos
        this->view->add_sub_window();
        this->view->sub_windows[0]->setWidget(video_surface->frame_container);
        this->view->sub_windows[0]->setAccessibleName("assemble.avi");

        QSize size = video_surface->frame_container->size();
        this->view->sub_windows[0]->widget()->setFixedSize(size);

        this->view->display_sub_window(0);
    }
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
    //On parcourt toutes les lignes de l'image
    for (int height = 0; height < picture->height(); height++)
    {
        //On récupère la ligne de pixel de l'image
        uchar* scan = picture->scanLine(height);
        int depth = 4;
        //On parcourt chaque pixels de la ligne
        for (int width = 0; width < picture->width(); width ++)
        {
            //On traduit les pixels en niveau de gris
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
    //Si le QMediaPlayer a fini de lire la vidéo, on lit la vidéo suivante
    if (state == QMediaPlayer::EndOfMedia)
    {
        this->index_of_playlist ++;
        //Tant qu'il reste des vidéos à lire on les lit dans le Video Surface
        if(this->index_of_playlist != this->playlist.size())
        {
            this->videos[0]->setMedia(this->playlist[this->index_of_playlist].url);
            this->video_surfaces[0]->flag_convert = this->playlist[index_of_playlist].flag_convert;
            this->videos[0]->play();
        }
        //S'il n'y a plus de vidéos à lire, on stoppe le VideoSurface
        else
        {
            this->videos[0]->stop();
        }
    }
}
