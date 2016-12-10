/** \file controller.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

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


/** \class Controller
 * \brief Le classe Controller permet de gérer tous les évènements
 */


class Controller : public QObject
{

    Q_OBJECT

public:
    /**
     * \brief Constructeur de la classe Controller
     */
    Controller();

    /**
     * \brief Destructeur de la class Controller
     */
    ~Controller();


public:
    View* view;  /**< La classe Controller a comme attribut un pointeur vers la Vue */
    Model* model; /**< La classe Controller a comme attribut un pointeur vers le Model */


public:
    std::vector<QPixmap*> pixmaps; /**< Vecteur qui stocke toutes les images ouvertes*/
    std::vector<QMediaPlayer*> videos;/**< Vecteur qui stocke toutes les vidéos ouvertes */
    std::vector<VideoSurface*> video_surfaces;/**< Vecteur qui contient toutes les surfaces de lecture de vidéos*/
    std::vector <PlayItem> playlist;/**< Vecteur contenant la liste des éléments de vidéos à lire */
    std::vector<ConvertImageThread*> vector_threads_images;/**< Vecteur qui contient les threads pour les images*/
    std::vector<ConvertVideoThread*> vector_threads_videos;/**< Vecteur qui contient les threads pour les vidéos*/

    unsigned int index_of_playlist; /**< Index de l'élément dans la playlist*/

public:
    //Declaration des fonctions liées aux actions

    /**
     * \brief Fonction qui permet d'ouvrir une image
     */
    void open_image();

    /**
     * \brief Fonction qui permet d'ouvrir une video
     */
    void open_video();

    /**
     * \brief Fonction qui permet d'enregistrer une image dans un fichier existant
     */
    void save();

    /**
     * \brief Fonction qui permet d'enregistrer une image dans un nouveau fichier
     */
    void save_as();

    /**
     * \brief  Fonction qui convertit en noir et blanc toutes les fenetres ouvertes
     */
    void convert_all();

    /**
     * \brief Fonction qui fait le montage photo ou video
     */
    void assemble();

    /**
     * \brief Fonction qui permet l'affichage de l'aide
     */
    void help();

    /**
     * \brief Fonction qui affiche le à propos
     */
    void about();

    /**
     * \brief Passage en noir et blanc de l'image donnée en paramètre
     * \param picture: image a convertir en noir et blanc de type QImage
     */
    void conversion(QImage* picture);

public slots:
    /**
     * \brief Fonction qui va permettre la lecture à la suite des vidéos
     * \param state: état de la vidéo en lecture
     */
void media_state_changed(QMediaPlayer::MediaStatus state);

};

#endif // Controller_H
