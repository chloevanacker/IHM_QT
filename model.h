/** \file model.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef MODEL_H
#define MODEL_H

#include "view.h"
#include "controller.h"
#include "header.h"
#include "project.h"
#include "videosurface.h"

/** \class Model model.h */
/** \brief La classe Modele traite les accès à la mémoire (récupère les fichiers)
 */

class Model

{
public:
    /**
     * \brief Constructeur du modèle
     */
    Model();

    /**
     * \brief Destructeur du modèle
     */
    ~Model();


public:
    Controller* controller; /** La classe Model a comme attribut un pointeur vers le Controller */

    /**
     * \brief Charge l'image depuis la mémoire dans un tableau de QPixmap
     *
     * \param file_name: Nom du fichier à charger
     */
    void load_image_file(QString file_name);

    /**
     * \brief Charge une vidéo
     *
     * \param file_name: Nom du fichier à charger
     */
    void load_video_file(QString file_name);



    /**
     * \brief: Fonction qui permet d'enregistrer une image dans un fichier déjà existant
     * \param file_name: nom du fichier dans lequel sauvegarder l'image
     * \param index: position de l'image dans le vecteur de pixmap
     */
    void save_file(QString file_name, int index);

    /**
     * \brief: Fonction qui permet d'enregistrer une image dans un nouveau fichier
     * \param file_name: nom du fichier dans lequel sauvegarder l'image
     * \param index: position de l'image dans le vecteur de pixmap
     */
    void save_as_file(QString file_name, int index);
};

#endif // MODEL_H
