/** \file project.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef PROJECT_H
#define PROJECT_H

#include "header.h"
#include "model.h"
#include "view.h"
#include "controller.h"
#include "videosurface.h"

/**
 * \brief Classe Project: classe qui gère notre application
 */

class Project
{

public:
    /**
     * \brief Project: Constructeur de la classe Project
     * \param model: pointeur vers le modèle de l'application
     * \param view: pointeur vers la vue de l'application
     * \param controller: pointeur vers la vue de l'application
     */
    Project(Model* model, View* view, Controller* controller);
    /**
      \brief ~Project: Destructeur de la classe Project
     */
    ~Project();

    Model* model; /**< La classe Projet a un pointeur sur le modèle*/
    View* view; /**< La classe Projet a un pointeur sur la vue*/
    Controller* controller; /**< La classe Projet a un pointeur sur le contrôleur*/


};

#endif // PROJECT_H
