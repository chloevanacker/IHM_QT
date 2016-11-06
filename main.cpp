#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Model* model = new Model;
    View* view = new View;
    Controller* controller = new Controller;
    Project* project = new Project(model, view, controller);
    project->view->showMaximized();


    return application.exec();
}
