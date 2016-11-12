#include "videosurface.h"

VideoSurface::VideoSurface(bool flag_convert)
{
    this->flag_convert = flag_convert;
    frame_container = new QLabel;

}

VideoSurface::~VideoSurface()
{

}

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats (QAbstractVideoBuffer::HandleType handle_type) const
{
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
    QVideoFrame frametodraw(video_frame);

    if(!frametodraw.map(QAbstractVideoBuffer::ReadOnly))
    {
       return false;
    }

    //this is a shallow operation. it just refer the frame buffer
    QImage picture (frametodraw.bits(), frametodraw.width(), frametodraw.height(), frametodraw.bytesPerLine(),
                 video_frame.imageFormatFromPixelFormat(video_frame.pixelFormat()));

    if (this->flag_convert == true)
    {
        this->controller->conversion(&picture);
    }

    frame_container->resize(picture.size());

    //QPixmap::fromImage create a new buffer for the pixmap
    frame_container->setPixmap(QPixmap::fromImage(picture));

    //we can release the data
    frametodraw.unmap();

    //frame_container->update();

    //frame_container->show();

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
