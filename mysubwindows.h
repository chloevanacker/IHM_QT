#ifndef MYSUBWINDOWS_H
#define MYSUBWINDOWS_H
#include "header.h"
#include "view.h"
#include "controller.h"


class MySubWindows : public QMdiSubWindow
{

public:

    explicit MySubWindows(View*, Controller*);

protected:
    void closeEvent(QCloseEvent *event);
public:
    Controller* controller;
    View* view;

};
#endif // MYSUBWINDOWS_H
