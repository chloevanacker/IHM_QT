#include "mysubwindows.h"
#include "header.h"


MySubWindows::MySubWindows(View* view, Controller* controller)
{
    this->controller = controller;
    this->view=view;
}

void MySubWindows::closeEvent(QCloseEvent *)
{

    unsigned int index;
    QString nametodelete= this->accessibleName();
    for(index=0; index<this->view->sub_windows.size();index++)
    {
        if(this->view->sub_windows.at(index)->accessibleName()==nametodelete)
        {
          this->view->sub_windows.erase(this->view->sub_windows.begin()+index);
          break;
        }
     }
    this->controller->pixmaps.erase(this->controller->pixmaps.begin()+index);

    if(this->view->sub_windows.size()==0)
    {
       this->view->initial_actions_state();
    }

}
