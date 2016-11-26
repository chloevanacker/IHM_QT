#ifndef MODEL_H
#define MODEL_H

#include "view.h"
#include "controller.h"
#include "header.h"
#include "project.h"
#include "videosurface.h"

class Model
{
public:
    Model();
    ~Model();

public:
    Controller* controller;
    void load_image_file(QString file_name);
    void load_video_file(QString file_name);
    void save_file(QString file_name, int index);
    void save_as_file(QString file_name, int index);
};

#endif // MODEL_H
