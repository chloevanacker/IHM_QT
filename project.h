/** \file project.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef PROJECT_H
#define PROJECT_H

#include "header.h"
#include "model.h"
#include "view.h"
#include "controller.h"
#include "videosurface.h"

/**
 * \brief Classe Project: classe qui gère notre application
 */

class Project
{

public:
    /**
     * \brief Project: Constructeur de la classe Project
     * \param model: pointeur vers le modèle de l'application
     * \param view: pointeur vers la vue de l'application
     * \param controller: pointeur vers la vue de l'application
     */
    Project(Model* model, View* view, Controller* controller);
    /**
      \brief ~Project: Destructeur de la classe Project
     */
    ~Project();

    Model* model; /**< La classe Projet a un pointeur sur le modèle*/
    View* view; /**< La classe Projet a un pointeur sur la vue*/
    Controller* controller; /**< La classe Projet a un pointeur sur le contrôleur*/


};

/*
 *
np@Samsungnp:~/Documents/GIT/IHM_QT$ valgrind ./Project
==7064== Memcheck, a memory error detector
==7064== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==7064== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==7064== Command: ./Project
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x9160946: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x54B4728: g_cclosure_marshal_VOID__VOIDv (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x54B2CCD: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x54CC07F: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x54CD0B0: g_signal_emit_by_name (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x91C6236: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x54BA2DE: g_object_set_valist (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x54BAA77: g_object_set (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4002.0)
==7064==    by 0x4302CE0: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42FF857: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42E304C: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42756D3: QStyleFactory::create(QString const&) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==
==7064== Syscall param ioctl(generic) points to uninitialised byte(s)
==7064==    at 0x52280F9: ioctl (syscall-template.S:81)
==7064==    by 0x5E9C6EF: drmIoctl (in /usr/lib/i386-linux-gnu/libdrm.so.2.4.0)
==7064==    by 0x5E9F3FB: drmCommandWriteRead (in /usr/lib/i386-linux-gnu/libdrm.so.2.4.0)
==7064==    by 0xDFA932F: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==7064==    by 0xDFA9576: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==7064==    by 0xDFA9FE7: nouveau_device_new (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==7064==    by 0xD8D6269: nouveau_drm_screen_create (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD4C6FFB: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD8D10A2: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD8D0A9E: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD781BC2: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD77E1C4: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==  Address 0xd1b37fa is 2 bytes inside a block of size 72 alloc'd
==7064==    at 0x402A17C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0xDFA9512: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==7064==    by 0xDFA9FE7: nouveau_device_new (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==7064==    by 0xD8D6269: nouveau_drm_screen_create (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD4C6FFB: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD8D10A2: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD8D0A9E: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD781BC2: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0xD77E1C4: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==7064==    by 0x5852FB2: ??? (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==7064==    by 0x582FBF3: ??? (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==7064==    by 0x582B5F1: glXGetFBConfigs (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x9085990: DBusMenuExporter::doEmitLayoutUpdated() (in /usr/lib/i386-linux-gnu/libdbusmenu-qt5.so.2.6.0)
==7064==    by 0x908C28B: ??? (in /usr/lib/i386-linux-gnu/libdbusmenu-qt5.so.2.6.0)
==7064==    by 0x4E23B6F: QMetaObject::activate(QObject*, int, int, void**) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E240EA: QMetaObject::activate(QObject*, QMetaObject const*, int, void**) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E98FA4: QTimer::timeout(QTimer::QPrivateSignal) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E30B5A: QTimer::timerEvent(QTimerEvent*) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E249EB: QObject::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4206E23: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x420C800: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x4DF9AE9: QCoreApplication::notifyInternal(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E4BFEC: QTimerInfoList::activateTimers() (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4E4C517: ??? (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==
==7064== Invalid read of size 16
==7064==    at 0x47E0B51: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49C78E1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49CC728: QRasterPaintEngine::drawImage(QPointF const&, QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49D594D: QRasterPaintEngine::drawPixmap(QPointF const&, QPixmap const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49ED8F1: QPainter::drawPixmap(QPointF const&, QPixmap const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x42F9869: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42F07D5: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x43EFDAC: QToolBar::paintEvent(QPaintEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x424A6D3: QWidget::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x43F009B: QToolBar::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x4206E23: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x420C800: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==  Address 0x1113ea10 is 8 bytes before a block of size 25,280 alloc'd
==7064==    at 0x402A17C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x4848858: QImageData::create(QSize const&, QImage::Format, int) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4848972: QImage::QImage(int, int, QImage::Format) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4849D0B: QImage::copy(QRect const&) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x42F7DD1: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42F937C: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42F07D5: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x43EFDAC: QToolBar::paintEvent(QPaintEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x424A6D3: QWidget::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x43F009B: QToolBar::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x4206E23: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x420C800: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x99951A0: ??? (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x9978544: ??? (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x992E6F9: pixman_image_composite32 (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x9627646: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x96720B0: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9662916: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9663584: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x96645EC: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x961968D: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x962BFD0: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9667B64: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x96228AF: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x99954BB: ??? (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x9978544: ??? (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x992E6F9: pixman_image_composite32 (in /usr/lib/i386-linux-gnu/libpixman-1.so.0.30.2)
==7064==    by 0x9627646: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x96720B0: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9662916: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9663584: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x96642AB: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9619583: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x962BF70: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x9667A54: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==    by 0x962243C: ??? (in /usr/lib/i386-linux-gnu/libcairo.so.2.11301.0)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x16701FB3: ??? (in /usr/lib/i386-linux-gnu/librsvg-2.so.2.40.2)
==7064==    by 0x16702C13: rsvg_handle_get_pixbuf_sub (in /usr/lib/i386-linux-gnu/librsvg-2.so.2.40.2)
==7064==    by 0x16702C92: rsvg_handle_get_pixbuf (in /usr/lib/i386-linux-gnu/librsvg-2.so.2.40.2)
==7064==    by 0x107D1AD4: ??? (in /usr/lib/i386-linux-gnu/gdk-pixbuf-2.0/2.10.0/loaders/libpixbufloader-svg.so)
==7064==    by 0x9721377: gdk_pixbuf_loader_close (in /usr/lib/i386-linux-gnu/libgdk_pixbuf-2.0.so.0.3000.7)
==7064==    by 0x971D25D: ??? (in /usr/lib/i386-linux-gnu/libgdk_pixbuf-2.0.so.0.3000.7)
==7064==    by 0x971EFED: gdk_pixbuf_new_from_stream_at_scale (in /usr/lib/i386-linux-gnu/libgdk_pixbuf-2.0.so.0.3000.7)
==7064==    by 0x91AB184: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x91AE640: gtk_icon_info_load_icon (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x91AE7A0: gtk_icon_theme_load_icon (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x9183969: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==    by 0x918A15D: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.23)
==7064==
"Thread debut"
"Thread fin"
"Thread debut"
"Thread fin"
==7064== Invalid read of size 16
==7064==    at 0x47E0B51: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49C78E1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49CD80D: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49D5E03: QRasterPaintEngine::drawPixmap(QRectF const&, QPixmap const&, QRectF const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49EC36A: QPainter::drawPixmap(QRectF const&, QPixmap const&, QRectF const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x427421C: QStyle::drawItemPixmap(QPainter*, QRect const&, int, QPixmap const&) const (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42F73CA: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x429A892: QCommonStyle::drawControl(QStyle::ControlElement, QStyleOption const*, QPainter*, QWidget const*) const (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42F34A3: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x42EB4B0: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x43F7A79: QToolButton::paintEvent(QPaintEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==    by 0x424A6D3: QWidget::event(QEvent*) (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.2.1)
==7064==  Address 0x15bdedf0 is 8 bytes before a block of size 2,304 alloc'd
==7064==    at 0x402A17C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x4848858: QImageData::create(QSize const&, QImage::Format, int) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4848972: QImage::QImage(int, int, QImage::Format) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x49B3C4E: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x484CEFA: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x484D0FC: QImage::transformed(QTransform const&, Qt::TransformationMode) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x486A9B5: QPlatformPixmap::transformed(QTransform const&, Qt::TransformationMode) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x486516C: QPixmap::transformed(QTransform const&, Qt::TransformationMode) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x48652DF: QPixmap::scaled(QSize const&, Qt::AspectRatioMode, Qt::TransformationMode) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x48733FF: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4874595: QIcon::pixmap(QWindow*, QSize const&, QIcon::Mode, QIcon::State) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4874607: QIcon::pixmap(QSize const&, QIcon::Mode, QIcon::State) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D23F: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D230: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D25E: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D2F9: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D312: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D65C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D64D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D675: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D928: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D8E4: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D8E8: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x578D947: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==    by 0x805442D: Controller::save_as() (controller.cpp:92)
==7064==    by 0x804F35B: View::save_as() (view.cpp:178)
==7064==    by 0x805DD5E: View::qt_static_metacall(QObject*, QMetaObject::Call, int, void**) (moc_view.cpp:93)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EDC9: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402F06A: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE24: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EF1D: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EF2F: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE34: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EEA4: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x402EED3: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x403082D: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030853: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x403087D: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030881: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030888: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x4030890: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030897: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x402EE82: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030831: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x4030844: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x4030842: memset (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x5800769: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EDCF: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EDDB: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EDC1: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE1B: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EF0C: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EEAD: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EEDC: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EEEB: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x402EED0: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE60: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE8A: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE9B: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x402EE38: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x402EE80: memcpy (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x580064A: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5800FE6: ??? (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x5801FD9: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578CF19: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000C2: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000D3: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000F3: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800107: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580015A: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580016F: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x57FFFD5: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x57FFFEC: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580001A: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580002B: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580004B: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580005C: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580008A: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580009B: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000BB: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000CC: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58000FA: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580010E: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800122: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800139: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800161: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800168: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x57FFFE2: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x57FFFF3: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800013: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800024: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800083: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800094: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x580012F: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800052: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800063: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800140: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CF5D: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Syscall param write(buf) points to uninitialised byte(s)
==7064==    at 0x522002B: ??? (syscall-template.S:81)
==7064==    by 0x4D881D8: ??? (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D94B32: ??? (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D86DED: ??? (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D31EFD: QFileDevice::flush() (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D334BD: QFileDevice::writeData(char const*, long long) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D3C3B7: QIODevice::write(char const*, long long) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4884A6E: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x5790831: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A023: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==  Address 0xca5cfd8 is 192 bytes inside a block of size 32,768 alloc'd
==7064==    at 0x402C324: realloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==7064==    by 0x4C2631C: QByteArray::reallocData(unsigned int, QFlags<QArrayData::AllocationOption>) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4C26592: QByteArray::resize(int) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D34C52: ??? (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D334EB: QFileDevice::writeData(char const*, long long) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4D3C3B7: QIODevice::write(char const*, long long) (in /usr/lib/i386-linux-gnu/libQt5Core.so.5.2.1)
==7064==    by 0x4884A6E: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x5790831: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5789F06: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x579094F: png_write_info_before_PLTE (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5790BEB: png_write_info (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x48860DD: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Conditional jump or move depends on uninitialised value(s)
==7064==    at 0x5801E55: deflate (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578C89F: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CFA3: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4857CF5: QImageWriter::write(QImage const&) (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866B7D: QPixmap::doImageIO(QImageWriter*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4866D41: QPixmap::save(QIODevice*, char const*, int) const (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x8051B00: Model::save_as_file(QString, int) (model.cpp:76)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58001E5: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CA57: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CFA3: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58001D0: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CA57: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CFA3: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x58001DE: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CA57: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CFA3: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064== Use of uninitialised value of size 4
==7064==    at 0x5800226: crc32 (in /lib/i386-linux-gnu/libz.so.1.2.8)
==7064==    by 0x578131C: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A033: png_write_chunk_data (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A1D4: png_write_chunk (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578A92B: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CA57: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578CFA3: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x578D443: ??? (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791431: png_write_row (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x5791649: png_write_image (in /lib/i386-linux-gnu/libpng12.so.0.50.0)
==7064==    by 0x4886AE1: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==    by 0x4886F8A: ??? (in /usr/lib/i386-linux-gnu/libQt5Gui.so.5.2.1)
==7064==
==7064==
==7064== HEAP SUMMARY:
==7064==     in use at exit: 3,978,109 bytes in 40,488 blocks
==7064==   total heap usage: 741,328 allocs, 700,840 frees, 91,609,516 bytes allocated
==7064==
==7064== LEAK SUMMARY:
==7064==    definitely lost: 10,113 bytes in 238 blocks
==7064==    indirectly lost: 478,982 bytes in 1,320 blocks
==7064==      possibly lost: 234,256 bytes in 949 blocks
==7064==    still reachable: 3,028,982 bytes in 36,881 blocks
==7064==         suppressed: 0 bytes in 0 blocks
==7064== Rerun with --leak-check=full to see details of leaked memory
==7064==
==7064== For counts of detected and suppressed errors, rerun with: -v
==7064== Use --track-origins=yes to see where uninitialised values come from
==7064== ERROR SUMMARY: 1637326 errors from 91 contexts (suppressed: 7966454 from 137)
 *
 */

/*
 * nicol-pn@nicolpn:~/Documents/Cours/QT/GIT/IHM_QT$ valgrind --tool=memcheck ./Project
==20470== Memcheck, a memory error detector
==20470== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==20470== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==20470== Command: ./Project
==20470==
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libQt5Multimedia.so.5.5.1:
--20470-- Ignoring non-Dwarf2/3/4 block in .debug_info
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libQt5Multimedia.so.5.5.1:
--20470-- Last block truncated in .debug_info; ignoring
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libQt5Multimedia.so.5.5.1:
--20470-- parse_CU_Header: is neither DWARF2 nor DWARF3 nor DWARF4
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9B0B63D: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D866: g_cclosure_marshal_VOID__VOIDv (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BD8E: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58669F8: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5867496: g_signal_emit_by_name (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9B6C4A2: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x58530C3: g_object_set_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5853661: g_object_set (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x432C4AD: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4329F65: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4310847: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x42AE0A0: QStyleFactory::create(QString const&) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Syscall param ioctl(generic) points to uninitialised byte(s)
==20470== at 0x555FFE9: ioctl (syscall-template.S:84)
==20470== by 0x643857D: drmIoctl (in /usr/lib/i386-linux-gnu/libdrm.so.2.4.0)
==20470== by 0x643B721: drmCommandWriteRead (in /usr/lib/i386-linux-gnu/libdrm.so.2.4.0)
==20470== by 0xC3972FB: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==20470== by 0xC397554: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)
==20470== by 0xC398074: nouveau_device_new (in /usr/lib/i386-linux-
gnu/libdrm_nouveau.so.2.0.0)
==20470== by 0xE6274B3: nouveau_drm_screen_create (in /usr/lib/i386-linux-
gnu/dri/nouveau_dri.so)
==20470== by 0xE23CC48: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE6225AF: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE621FCC: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE4EF19A: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE4EB579: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== Address 0xcf388ba is 2 bytes inside a block of size 72 alloc'd
==20470== at 0x402D17C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==20470== by 0xC3974F7: ??? (in /usr/lib/i386-linux-gnu/libdrm_nouveau.so.2.0.0)==20470== by 0xC398074: nouveau_device_new (in /usr/lib/i386-linux-
gnu/libdrm_nouveau.so.2.0.0)
==20470== by 0xE6274B3: nouveau_drm_screen_create (in /usr/lib/i386-linux-
gnu/dri/nouveau_dri.so)
==20470== by 0xE23CC48: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE6225AF: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE621FCC: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE4EF19A: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0xE4EB579: ??? (in /usr/lib/i386-linux-gnu/dri/nouveau_dri.so)
==20470== by 0x5C50601: ??? (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==20470== by 0x5C29FD9: ??? (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==20470== by 0x5C259CF: glXGetFBConfigs (in /usr/lib/i386-linux-gnu/mesa/libGL.so.1.2.0)
==20470==
==20470== Syscall param writev(vector[...]) points to uninitialised byte(s)
==20470== at 0x55600BF: ??? (syscall-template.S:84)
==20470== by 0x629966D: ??? (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x6299BA4: ??? (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x629A447: ??? (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x629B2E1: ??? (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x629B358: xcb_wait_for_reply (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x62A281F: xcb_get_input_focus_reply (in /usr/lib/i386-linux-
gnu/libxcb.so.1.1.0)
==20470== by 0x8F11E20: QXcbConnection::sync() (in /usr/lib/i386-linux-
gnu/libQt5XcbQpa.so.5.5.1)
==20470== by 0x8F2C837: QXcbWindow::setWindowState(Qt::WindowState) (in /usr/lib/i386-
linux-gnu/libQt5XcbQpa.so.5.5.1)
==20470== by 0x49532FE: QWindow::setWindowState(Qt::WindowState) (in /usr/lib/i386-
linux-gnu/sse2/libQt5Gui.so.5.5.1)
==20470== by 0x427FA71: QWidget::setWindowState(QFlags<Qt::WindowState>) (in
/usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x42802D6: QWidget::showMaximized() (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== Address 0x8911732 is 4,450 bytes inside a block of size 21,016 alloc'd
==20470== at 0x402F0B8: calloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==20470== by 0x6299081: xcb_connect_to_fd (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x629D5D2: xcb_connect_to_display_with_auth_info (in /usr/lib/i386-linux-
gnu/libxcb.so.1.1.0)
==20470== by 0x629D74D: xcb_connect (in /usr/lib/i386-linux-gnu/libxcb.so.1.1.0)
==20470== by 0x59FCEFA: _XConnectXCB (in /usr/lib/i386-linux-gnu/libX11.so.6.3.0)
==20470== by 0x59ED4A5: XOpenDisplay (in /usr/lib/i386-linux-gnu/libX11.so.6.3.0)
==20470== by 0x8F1756C: QXcbConnection::QXcbConnection(QXcbNativeInterface*, bool,
unsigned int, char const*) (in /usr/lib/i386-linux-gnu/libQt5XcbQpa.so.5.5.1)
==20470== by 0x8F1ADCD: QXcbIntegration::QXcbIntegration(QStringList const&, int&,
char**) (in /usr/lib/i386-linux-gnu/libQt5XcbQpa.so.5.5.1)
==20470== by 0x403BE9E: ??? (in /usr/lib/i386-linux-gnu/qt5/plugins/platforms/libqxcb.so)
==20470== by 0x4939B52: QPlatformIntegrationFactory::create(QString const&, QStringList
const&, int&, char**, QString const&) (in /usr/lib/i386-linux-gnu/sse2/libQt5Gui.so.5.5.1)
==20470== by 0x4946F4E: QGuiApplicationPrivate::createPlatformIntegration() (in
/usr/lib/i386-linux-gnu/sse2/libQt5Gui.so.5.5.1)
==20470== by 0x4947DF3: QGuiApplicationPrivate::createEventDispatcher() (in /usr/lib/i386-
linux-gnu/sse2/libQt5Gui.so.5.5.1)
==20470====20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9A3A9AA: DBusMenuExporter::doEmitLayoutUpdated() (in /usr/lib/i386-
linux-gnu/libdbusmenu-qt5.so.2.6.0)
==20470== by 0x9A3F98B: ??? (in /usr/lib/i386-linux-gnu/libdbusmenu-qt5.so.2.6.0)
==20470== by 0x50AB460: QMetaObject::activate(QObject*, int, int, void**) (in /usr/lib/i386-
linux-gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x50AB95C: QMetaObject::activate(QObject*, QMetaObject const*, int, void**)
(in /usr/lib/i386-linux-gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x512E201: QTimer::timeout(QTimer::QPrivateSignal) (in /usr/lib/i386-linux-
gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x50B8060: QTimer::timerEvent(QTimerEvent*) (in /usr/lib/i386-linux-
gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x50AC04D: QObject::event(QEvent*) (in /usr/lib/i386-linux-
gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x423C159: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in
/usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x424181B: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x507B66E: QCoreApplication::notifyInternal(QObject*, QEvent*) (in
/usr/lib/i386-linux-gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x50D268B: QTimerInfoList::activateTimers() (in /usr/lib/i386-linux-
gnu/sse2/libQt5Core.so.5.5.1)
==20470== by 0x50D2C38: ??? (in /usr/lib/i386-linux-gnu/sse2/libQt5Core.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9F82037: gdk_rectangle_intersect (in /usr/lib/i386-linux-gnu/libgdk-x11-
2.0.so.0.2400.30)
==20470== by 0xAA92EB6: ??? (in /usr/lib/i386-linux-gnu/gtk-2.0/2.10.0/engines/libmurrine.so)
==20470== by 0xAA9AC9F: ??? (in /usr/lib/i386-linux-gnu/gtk-
2.0/2.10.0/engines/libmurrine.so)
==20470== by 0x9C0C3FD: gtk_paint_box (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x43243D1: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x431F9C1: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x43E724F: QScrollBar::paintEvent(QPaintEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4284369: QWidget::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4348D5B: QAbstractSlider::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x43E8B59: QScrollBar::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x423C159: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in
/usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x424181B: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9F82037: gdk_rectangle_intersect (in /usr/lib/i386-linux-gnu/libgdk-x11-
2.0.so.0.2400.30)
==20470== by 0xAA92DFC: ??? (in /usr/lib/i386-linux-gnu/gtk-
2.0/2.10.0/engines/libmurrine.so)==20470== by 0xAA9AC9F: ??? (in /usr/lib/i386-linux-gnu/gtk-
2.0/2.10.0/engines/libmurrine.so)
==20470== by 0x9C0C3FD: gtk_paint_box (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x43243D1: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x431B280: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x43E724F: QScrollBar::paintEvent(QPaintEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4284369: QWidget::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x4348D5B: QAbstractSlider::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x43E8B59: QScrollBar::event(QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x423C159: QApplicationPrivate::notify_helper(QObject*, QEvent*) (in
/usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470== by 0x424181B: QApplication::notify(QObject*, QEvent*) (in /usr/lib/i386-linux-
gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4AF1: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC5B4A: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62BD: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4B14: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC5B4A: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62BD: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4E7E: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62CA: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x431AF56: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4E9E: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62CA: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x431AF56: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4EBC: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62CA: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x431AF56: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470==
==20470== Conditional jump or move depends on uninitialised value(s)
==20470== at 0x9BC4EDC: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x9BC62CA: ??? (in /usr/lib/i386-linux-gnu/libgtk-x11-2.0.so.0.2400.30)
==20470== by 0x584D7EB: g_cclosure_marshal_VOID__VOID (in /usr/lib/i386-linux-
gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x584BB6A: g_closure_invoke (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x585DFFB: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x5866C95: g_signal_emit_valist (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x5866FC4: g_signal_emit (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x9AC4B70: gtk_adjustment_changed (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x584F445: ??? (in /usr/lib/i386-linux-gnu/libgobject-2.0.so.0.4800.1)
==20470== by 0x58524DC: g_object_thaw_notify (in /usr/lib/i386-linux-gnu/libgobject-
2.0.so.0.4800.1)
==20470== by 0x9AC4FF2: gtk_adjustment_configure (in /usr/lib/i386-linux-gnu/libgtk-x11-
2.0.so.0.2400.30)
==20470== by 0x431AF56: ??? (in /usr/lib/i386-linux-gnu/libQt5Widgets.so.5.5.1)
==20470==
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/qt5/plugins/mediaservice/libgstmediaplayer.so:
--20470-- Ignoring non-Dwarf2/3/4 block in .debug_info
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/qt5/plugins/mediaservice/libgstmediaplayer.so:
--20470-- Last block truncated in .debug_info; ignoring
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/qt5/plugins/mediaservice/libgstmediaplayer.so:
--20470-- parse_CU_Header: is neither DWARF2 nor DWARF3 nor DWARF4
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libqgsttools_p.so.1.0.0:
--20470-- Ignoring non-Dwarf2/3/4 block in .debug_info--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libqgsttools_p.so.1.0.0:
--20470-- Last block truncated in .debug_info; ignoring
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-gnu/libqgsttools_p.so.1.0.0:
--20470-- parse_CU_Header: is neither DWARF2 nor DWARF3 nor DWARF4
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/libQt5MultimediaWidgets.so.5.5.1:
--20470-- Ignoring non-Dwarf2/3/4 block in .debug_info
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/libQt5MultimediaWidgets.so.5.5.1:
--20470-- Last block truncated in .debug_info; ignoring
--20470-- WARNING: Serious error when reading debug info
--20470-- When reading debug info from /usr/lib/i386-linux-
gnu/libQt5MultimediaWidgets.so.5.5.1:
--20470-- parse_CU_Header: is neither DWARF2 nor DWARF3 nor DWARF4
Error: "Erreur du flux de données interne."
Warning: "De nombreux tampons sont éliminés."
Error: "GStreamer a rencontré une erreur générale de flux."
Error: "Erreur du flux de données interne."
==20470==
==20470== HEAP SUMMARY:
==20470== in use at exit: 4,882,819 bytes in 85,058 blocks
==20470== total heap usage: 548,246 allocs, 463,188 frees, 123,859,450 bytes allocated
==20470==
==20470== LEAK SUMMARY:
==20470== definitely lost: 27,751 bytes in 93 blocks
==20470== indirectly lost: 15,526 bytes in 954 blocks
==20470==
possibly lost: 5,692 bytes in 174 blocks
==20470== still reachable: 4,536,542 bytes in 81,921 blocks
==20470==
of which reachable via heuristic:
==20470==
newarray
: 13,600 bytes in 393 blocks
==20470==
suppressed: 0 bytes in 0 blocks
==20470== Rerun with --leak-check=full to see details of leaked memory
==20470==
==20470== For counts of detected and suppressed errors, rerun with: -v
==20470== Use --track-origins=yes to see where uninitialised values come from
==20470== ERROR SUMMARY: 67 errors from 12 contexts (suppressed: 0 from 0)
nicol-pn@nicolpn:~/Documents/Cours/QT/GIT/IHM_QT$
 */

#endif // PROJECT_H
