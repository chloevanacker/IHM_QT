#include "videosurface.h"


VideoSurface::VideoSurface(bool flag_convert)
{
    //On initialise les attributs de la VideoSurface à ceux donnés en paramètre
    this->flag_convert = flag_convert;
    frame_container = new QLabel;

}

VideoSurface::~VideoSurface()
{
  delete this->frame_container;
}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats (QAbstractVideoBuffer::HandleType handle_type) const
{
    //METTRE COMMENTAIRE
    if(handle_type == QAbstractVideoBuffer::NoHandle)
    {
        return QList<QVideoFrame::PixelFormat>()
                << QVideoFrame::Format_RGB32
                << QVideoFrame::Format_ARGB32
                << QVideoFrame::Format_ARGB32_Premultiplied
                << QVideoFrame::Format_RGB565
                << QVideoFrame::Format_RGB555;
    }

    else
    {
        return QList<QVideoFrame::PixelFormat>();
    }

}

bool VideoSurface::present(const QVideoFrame & video_frame)
{
    //On récupère la vidéo frame donnée en paramètre
    QVideoFrame frame_to_draw(video_frame);

    //Si le QAbstractVideoBuffer n'est pas en ReadOnly, on retourne false
    if(!frame_to_draw.map(QAbstractVideoBuffer::ReadOnly))
    {
       return false;
    }

    //On crée une image de la taille de la QVideoFrame
    QImage picture (frame_to_draw.bits(), frame_to_draw.width(), frame_to_draw.height(), frame_to_draw.bytesPerLine(),
                 video_frame.imageFormatFromPixelFormat(video_frame.pixelFormat()));

    //Si le flag_convert est à true, on convertit l'image
    if (this->flag_convert == true)
    {
        this->controller->conversion(&picture);
    }

    //On met l'image dans le QLabel en passant par un QPixmap
    frame_container->resize(picture.size());
    frame_container->setPixmap(QPixmap::fromImage(picture));

    //on libère la QVideoFrame
    frame_to_draw.unmap();

    return true;
}


bool VideoSurface::start(const QVideoSurfaceFormat &format)
{
    const QImage::Format image_format = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
    const QSize size = format.frameSize();

    if (image_format != QImage::Format_Invalid && !size.isEmpty())
    {
        this->image_format = image_format;
        QAbstractVideoSurface::start(format);
        return true;
    }

    else
    {
        return false;
    }
}

void VideoSurface::stop()
{
    QAbstractVideoSurface::stop();
}
