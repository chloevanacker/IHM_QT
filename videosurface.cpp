#include "videosurface.h"

VideoSurface::VideoSurface()
{
    mylabel = new QLabel;

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
    QImage picture(frametodraw.bits(), frametodraw.width(), frametodraw.height(), frametodraw.bytesPerLine(),
                 video_frame.imageFormatFromPixelFormat(video_frame.pixelFormat()));

    for (int height = 0; height < picture.height(); height++)
    {
        uchar* scan = picture.scanLine(height);
        int depth = 4;
        for (int width = 0; width < picture.width(); width ++)
        {
            QRgb* rgb_pixels = reinterpret_cast<QRgb*>(scan+ width*depth);
            int gray = qGray (*rgb_pixels);
            *rgb_pixels = QColor(gray, gray, gray).rgba();
            picture.setPixel(width, height, *rgb_pixels);
            if (gray)
            {
                int z = 0;
                z++;
            }
        }
    }

    mylabel->resize(picture.size());

    //QPixmap::fromImage create a new buffer for the pixmap
    mylabel->setPixmap(QPixmap::fromImage(picture));

    //we can release the data
    frametodraw.unmap();

    mylabel->update();

    mylabel->show();

    return true;

}


bool VideoSurface::start(const QVideoSurfaceFormat &format)
{
    const QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
    const QSize size = format.frameSize();

    if (imageFormat != QImage::Format_Invalid && !size.isEmpty())
    {
        this->imageFormat = imageFormat;
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
