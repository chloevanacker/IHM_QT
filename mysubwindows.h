/** \file mysubwindows.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef MYSUBWINDOWS_H
#define MYSUBWINDOWS_H
#include "header.h"
#include "view.h"
#include "controller.h"

/** \class MySubWindows
 * \brief Classe pour les sous-fenêtres qui hérite de la class QMdiSubWindow
 */

class MySubWindows : public QMdiSubWindow
{

public:
     /**
       *  Constructeur de la classe MySubWindows
       *
       *  \param view pointeur vers la vue
       *  \param controler pointeur vers le controleur
       */

    explicit MySubWindows(View*, Controller*);
    ~MySubWindows();

protected:
       /**
         *  \brief Gestion de la fermeture des fenetres
         *
         *  Réimplémentation de la methode qui permet de répondre aux requêtes de fermeture du widget
         *
         *  \param event : evenement donné lorsque Qt reçoit une requête de fermeture du widget
         */

    void closeEvent(QCloseEvent *event);

public:

    
    Controller* controller; /**< La classe MySubWindows a comme attribut un pointeur vers le controlleur */
    View* view; /**< La classe MySubWindows a comme attribut un pointeur vers la vue */

};
#endif // MYSUBWINDOWS_H
