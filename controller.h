#ifndef Controller_H
#define Controller_H
// Fichier d'include du controleur
#include "model.h"
#include "view.h"
#include "header.h"
#include "project.h"

class Controller
{
public:
    Controller();

public:
    View* view;
    Model* model;

public:
    std::vector<QPixmap*> pixmaps;
    std::vector<QMediaPlayer*> videos;

public:
    /*Declaration of all the functions linked to the actions*/
//
    void open();
    void save();
    void save_as();
    void convert();
    void assemble();
    void undo();
    void redo();
    void help();
    void about();
};

#endif // Controller_H
