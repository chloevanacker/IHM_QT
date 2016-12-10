/** \file convertimagethread.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef CONVERTIMAGETHREAD_H
#define CONVERTIMAGETHREAD_H

#include "header.h"
#include "controller.h"

/** \class ConvertImageThread
 * \brief Classe héritant de QThread et permettant de gérer les threads pour la conversion des images en noir et blanc *
 */

class ConvertImageThread : public QThread
{

public:

    /**
      *  Constructeur de la classe ConvertImageThread
      *
      * \param parent: un pointeur vers son objet parent
      * \param controller: un pointeur vers le contrôleur sur lequel il doit travailler
      * \param pixmap pointeur vers l'image concernée
      */
    explicit ConvertImageThread(QObject *parent, Controller* controller, QPixmap* pixmap);

    /**
     * \brief run: surchage de la function run de la classe QThread. Cette fonction contient la fonction à exécuter par le thread, qui est,
     * \brief ici une fonction de conversion en noir et blanc d'une image
     */
    void run();

public:
    Controller* controller;/**< La classe ConvertImageThread a comme attribut un pointeur vers le controlleur */
    QImage result; /**< Chaque thread possède une QImage qui sera le résultat du traitement noir et blanc */

};

#endif // CONVERTIMAGETHREAD_H

