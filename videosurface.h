#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include "view.h"
#include "controller.h"
#include "header.h"
#include "project.h"
#include "model.h"


class VideoSurface : public QAbstractVideoSurface
{
public:
    VideoSurface(bool flag_convert);
    ~VideoSurface();

    QImage::Format image_format;
    QLabel* frame_container;
    bool flag_convert;

    Controller* controller;

    QList<QVideoFrame::PixelFormat> supportedPixelFormats (QAbstractVideoBuffer::HandleType handle_type) const;

    bool start(const QVideoSurfaceFormat &format);

    bool present(const QVideoFrame & video_frame);

    void stop();
};

#endif // VIDEOSURFACE_H
