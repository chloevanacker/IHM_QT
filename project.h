#ifndef PROJECT_H
#define PROJECT_H

#include "header.h"
#include "model.h"
#include "view.h"
#include "controller.h"

class Project
{
public:
    Project(Model* model, View* view, Controller* controller);
    Model* model;
    View* view;
    Controller* controller;

    ~Project();
};

#endif // PROJECT_H
