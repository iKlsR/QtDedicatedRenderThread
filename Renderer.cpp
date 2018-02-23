#include "Renderer.hpp"
#include "OpenGLWidget.hpp"

#include <QOpenGLFunctions_3_3_Core>

Renderer::Renderer(OpenGLWidget *widget) : threadContext(Q_NULLPTR), surfaceWindow(widget)
{
    // pass
}

Renderer::~Renderer()
{
    surfaceWindow->destroy();
}

bool Renderer::createContext()
{
    threadContext = new QOpenGLContext;
    return threadContext->create();
}

void Renderer::start()
{
    if (!createContext()) return;

    forever {
        run();
    }
}

void Renderer::run()
{
    // Save some cycles and only run if the window is being exposed
    if (surfaceWindow->isExposed()) {
        threadContext->makeCurrent(surfaceWindow);

        auto gl = threadContext->versionFunctions<QOpenGLFunctions_3_3_Core>();

        gl->glViewport(0, 0, surfaceWindow->width(), surfaceWindow->height());
        gl->glClearColor(.1f, .1f, .1f, .4f);
        gl->glClear(GL_COLOR_BUFFER_BIT);

        // do some stuff

        threadContext->swapBuffers(surfaceWindow);
    }
}
