#ifndef CONVERTIMAGETHREAD_H
#define CONVERTIMAGETHREAD_H

#include "header.h"
#include "controller.h"

class ConvertImageThread : public QThread
{
public:
    ConvertImageThread();

public:


    explicit ConvertImageThread(QObject *parent, Controller* controller, View* view, int index);

    void run();

public:
    Controller* controller;
    View * view;
    QImage result;
    int index;

private:

};

#endif // CONVERTIMAGETHREAD_H

