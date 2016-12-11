#include "mysubwindows.h"
#include "header.h"


MySubWindows::MySubWindows(View* view, Controller* controller)
{
   //On connecte les MySubWindows aux vues et contrôleurs adéquats
    this->controller = controller;
    this->view=view;
}

MySubWindows::~MySubWindows()
{
}

void MySubWindows::closeEvent(QCloseEvent *)
{
    //Si on ferme une subwindow on veut trouver l'index de celle qui a reçu l'ordre de fermeture
    unsigned int index;
    QString name_to_delete= this->accessibleName();
    for(index=0; index<this->view->sub_windows.size();index++)
    {
        QString sub_window_name = this->view->sub_windows[index]->accessibleName();
        if(sub_window_name == name_to_delete)
        {
            //Si la fenetre contient une image, on libère la mémoire et on supprime le QPixmap du vecteur
            if (sub_window_name.toLower().endsWith(".png") || sub_window_name.toLower().endsWith(".jpg") || sub_window_name.toLower().endsWith(".jpeg"))
            {
                delete this->view->controller->pixmaps[index];
                this->view->controller->pixmaps.erase(this->view->controller->pixmaps.begin() + index);
            }

            //Si la fenetre contient une vidéo, on libère la mémoire et on supprime le QMediaPlayer et la VideoSurface de leur vecteurs respectifs
            else if (sub_window_name.toLower().endsWith(".avi") || sub_window_name.toLower().endsWith(".mp4"))
            {
                this->controller->video_surfaces[index]->stop();
                delete this->controller->video_surfaces[index];
                delete this->controller->videos[index];
                this->controller->video_surfaces.erase(this->controller->video_surfaces.begin() + index);
                this->controller->videos.erase(this->controller->videos.begin() + index);
            }

            //On libère la mémoire et supprime la sub window de son vecteur

              this->view->hide_sub_window(index);
              //delete this->view->sub_windows[index];
              this->view->sub_windows.erase(this->view->sub_windows.begin()+index);
              break;
        }
     }

    //S'il n'y a plus de sub window d'ouverte, on remet l'application dans son état initial
    if(this->view->sub_windows.size()==0)
    {
        this->view->initial_actions_state();
    }

    /*qDebug() << "POST SUPPRESSION : ";
    qDebug() << "Nbre sub windows : " << this->view->sub_windows.size();
    qDebug() << "Nbre pixmap : " << this->controller->pixmaps.size();
    qDebug() << "Nbre video player : " << this->controller->videos.size();
    qDebug() << "Nbre video surface : " << this->controller->video_surfaces.size();*/

}
