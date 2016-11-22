#ifndef VIEW_H
#define VIEW_H

#include"controller.h"
#include "header.h"
#include "project.h"
#include "videosurface.h"
#include "mysubwindows.h"

namespace Ui
{
class View;
}



class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();

private:
    Ui::View *ui;

public:
    Controller* controller;

public:
    /*Declaration of the area of the main window*/
    QMdiArea* main_area;

public:
    std::vector<MySubWindows*> sub_windows;
    QMessageBox* message_box;
public:
    void initial_actions_state();
    void display_message_box(QString title, QString content);
    QStringList display_open_box_image();
    QStringList display_open_box_video();
    QString display_save_as_box();
    void add_sub_window();
    void display_sub_window(int index_of_sub_window);
    void hide_sub_window(int index_of_sub_window);
    void refresh_sub_window(int index_of_sub_window);



/*Declaration of all the actions attributes, and of the function that create these actions */
private:
    QAction* open_action_image;
    QAction* open_action_video;
    QAction* save_action;
    QAction* save_as_action;
    QAction* convert_action;
    QAction* assemble_action;
    QAction* undo_action;
    QAction* redo_action;
    QAction* help_action;
    QAction* about_action;
    QAction* new_project_action;
    void create_actions();
    void delete_actions();

private slots:
    void open_image();
    void open_video();
    void save();
    void save_as();
    void convert_all();
    void assemble();
    void undo();
    void redo();
    void help();
    void about();
    void new_project();

/*Creation of all the menu attributes, of the function that create the main menu, and the one that updates it*/
private:
    QMenu* file_menu;
    QMenu* action_menu;
    QMenu* help_menu;
    QMenu* about_menu;
    void create_menu();
    //void update_menu();
    void delete_menus();

private:
    /*Creation of all the toolbar attributes, of the function that create the main toolbar, and the one that updates it */
    QToolBar* file_tool_bar;
    QToolBar* modification_tool_bar;
    QToolBar* correction_tool_bar;
    void create_tool_bar();
    //void update_tool_bar();
    void delete_tool_bars();

};


#endif // VIEW_H
