#include "OpenGLWidget.hpp"
#include "Renderer.hpp"

OpenGLWidget::OpenGLWidget() : QWindow()
{
    setFlags(Qt::Widget);
    setSurfaceType(QSurface::OpenGLSurface);

    // Don't think this format needs to be in sync with that of the context
    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setVersion(3, 3);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    // format.setSwapInterval(0); // run as fast as possible for whatever reason

    setFormat(format);
    create();

    // create our Renderer and move it to a dedicated thread
    renderer = new Renderer(this);
    rendererThread = new QThread;

    renderer->moveToThread(rendererThread);

    // Use this to start the renderer in a specific function
    connect(rendererThread, &QThread::started, renderer, &Renderer::start);
    connect(rendererThread, &QThread::finished, rendererThread, &QObject::deleteLater);

    rendererThread->start();
}

OpenGLWidget::~OpenGLWidget()
{

}
