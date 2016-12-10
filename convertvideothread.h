/** \file convertvideothread.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef CONVERTVIDEOTHREAD_H
#define CONVERTVIDEOTHREAD_H

#include "header.h"

/** \class ConvertVideoThread
 * \brief Classe héritant de QThread et permettant de gérer les threads pour la conversion des vidéos en noir et blanc *
 */

class ConvertVideoThread : public QThread
{
public:
    /**
     * \brief Constructeur de la classe ConvertVideoThread
     *
     * \param parent: un pointeur vers son objet parent
     * \param controller: un pointeur vers le contrôleur sur lequel il doit travailler
     * \param video_player: un pointeurs vers le QMediaPlayer qui contient la vidéo à convertir
     * \param video_surface: un pointeur vers le VideoSurface sur lequel on lira la vidéo convertie
     */
    explicit ConvertVideoThread(QObject *parent, Controller* controller, QMediaPlayer* video_player, VideoSurface* video_surface);

    /**
     * \brief run: surchage de la function run de la classe QThread. Cette fonction contient la fonction à exécuter par le thread, qui est,
     * \brief ici une fonction de conversion en noir et blanc frame par frame d'une vidéo
     */
    void run();

public:

    QMediaPlayer* video_player; /**< La classe ConvertVideoThread a comme attribut un pointeur vers un QMediaPlayer,qui contient la vidéo à convertir */
    VideoSurface* video_surface; /**< La classe ConvertVideoThread a comme attribut un pointeur vers une VideoSurface,  sur laquelle on lira la vidéo convertie */
    Controller* controller; /**< La classe ConvertVideoThread a comme attribut un pointeur vers le controlleur sur lequel le thread va travailler */

private:

};

#endif // CONVERTVIDEOTHREAD_H
