/** \file header.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef HEADER_H
#define HEADER_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QToolBar>
#include <QAction>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QString>
#include <QRgb>
#include <QFile>
#include <QMediaPlayer>
#include <QAbstractVideoSurface>
#include <QAbstractVideoBuffer>
#include <QVideoSurfaceFormat>
#include <QVideoWidget>
#include <QVideoFrame>
#include <QUrl>
#include <QPoint>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>

#define PICTURE 0
#define VIDEO 1

class MySubWindows;
class Project;
class View;
class Controller;
class Model;
class SubWindow;
class VideoSurface;
struct Playlist;
class ConvertImageThread;
class ConvertVideoThread;

#endif // HEADER_H
