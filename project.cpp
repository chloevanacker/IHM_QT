#include "project.h"
#include "header.h"

Project::Project(Model* model, View* view, Controller* controller)
{
    this->model = model;
    this->view = view;
    this->controller = controller;
    this->view->controller = this->controller;
    this->model->controller = this->controller;
    this->controller->view = this->view;
    this->controller->model = this->model;
}

Project::~Project()
{
//    delete model;
//    delete view;
//    delete controller;

    //12 bytes in 1 blocks are definitely lost in loss record 2,918 of 14,455
    //in main in main.cpp:10
    //1: operator new(unsigned int) in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so
    //2: main in <a href="file:///home/np/Documents/GIT/IHM_QT/main.cpp:10" >main.cpp:10</a>


}
