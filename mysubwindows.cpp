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
    QString name_to_delete= this->accessibleName();
    for(index=0; index<this->view->sub_windows.size();index++)
    {
        QString sub_window_name = this->view->sub_windows[index]->accessibleName();
        if(sub_window_name == name_to_delete)
        {
            if (sub_window_name.toLower().endsWith(".png") || sub_window_name.toLower().endsWith(".jpg") || sub_window_name.toLower().endsWith(".jpeg"))
            {
                delete this->view->controller->pixmaps[index];
                this->view->controller->pixmaps.erase(this->view->controller->pixmaps.begin() + index);
            }
            else if (sub_window_name.toLower().endsWith(".avi") || sub_window_name.toLower().endsWith(".mp4"))
            {
                this->controller->video_surfaces[index]->stop();
                delete this->controller->video_surfaces[index];
                delete this->controller->videos[index];
                this->controller->video_surfaces.erase(this->controller->video_surfaces.begin() + index);
                this->controller->videos.erase(this->controller->videos.begin() + index);
            }
            this->view->sub_windows.erase(this->view->sub_windows.begin()+index);
            break;
        }
     }

    if(this->view->sub_windows.size()==0)
    {
        this->view->initial_actions_state();
    }
}
