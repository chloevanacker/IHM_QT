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

}
