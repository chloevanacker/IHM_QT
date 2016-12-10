/** \file videosurface.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include "view.h"
#include "controller.h"
#include "header.h"
#include "project.h"
#include "model.h"

/**
 * \class VideoSurface
 * \brief La classe VideoSurface hérite de QAbstractVideoSurface, elle lira la vidéo à partir d'un QMediaPlayer en la récupérant frame par frame et en l'affichant
 */
class VideoSurface : public QAbstractVideoSurface
{

public:
    /**
     * \brief VideoSurface: constructeur de la classe VideoSurface. Si le booléen donné en paramètre est true, on veut convertir la vidéo en noir et blanc, sinon non
     * \param flag_convert: un booleen qui permet de déterminer si on désire convertir la vidéo en noir et blanc (true) ou non (false)
     */
    VideoSurface(bool flag_convert);

    /** Destructeur de la classe VideoSurface
    */
    ~VideoSurface();

    QImage::Format image_format; /**< La classe VideoSurface a comme attribut le format des frames de la vidéo qu'elle lit */
    QLabel* frame_container; /**< La classe VideoSurface a comme attribut un label, dans lequel on va afficher les frames au fur et à mesure qu'on les reçoit*/
    bool flag_convert; /**< La classe VideoSurface a comme attribut un booléen qui lorsqu'il vaut true indique que l'on veut convertir la vidéo en noir et blanc*/

    Controller* controller; /**< La classe VideoSurface a comme attribut un pointeur vers le contrôleur sur lequel elle doit travailler */

    /**
     * \brief supportedPixelFormats: fonction qui permet de nous assurer que le format des frames sera supporté par la classe
     * \param handle_type: type supporté par le QAbstractVideoBuffer
     * \return Retourne, sous le format d'une liste, les formats qui sont supportés par la classe
     */
    QList<QVideoFrame::PixelFormat> supportedPixelFormats (QAbstractVideoBuffer::HandleType handle_type) const;

    /**
     * \brief start: fonction qui lance la video surface, et commence à récupérer les frames une à une
     * \param format: format de la QVideoSurface
     * \return Retourne true si on arrive à récupérer les frames, et false sinon
     */
    bool start(const QVideoSurfaceFormat &format);

    /**
     * \brief present: récupère la frame de la vidéo et l'affiche dans un QLabel
     * \param video_frame: la frame a afficher
     * \return Retourne true si on arrive à lire la frame
     */
    bool present(const QVideoFrame & video_frame);

    /**
     * \brief stop: stoppe la lecture de la vidéo
     */
    void stop();
};

#endif // VIDEOSURFACE_H
