#ifndef CONVERTIMAGETHREAD_H
#define CONVERTIMAGETHREAD_H

#include "header.h"
#include "view.h"
#include "controller.h"

class ConvertImageThread : public QThread
{

public:
    explicit ConvertImageThread(QObject *parent = 0);
    void run();

   // ~convert_image_thread();

public:

    QImage result;

private:

};

#endif // CONVERTIMAGETHREAD_H

