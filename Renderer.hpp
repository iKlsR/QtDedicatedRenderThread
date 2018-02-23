#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include <QWindow>
#include <QElapsedTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLContext>

class OpenGLWidget;

class Renderer : public QObject
{
    Q_OBJECT

public:
    explicit Renderer(OpenGLWidget *window);
    ~Renderer();

    bool createContext();
    void start();
    void run();

private:
    QOpenGLContext *threadContext;
    OpenGLWidget *surfaceWindow;
};

#endif // RENDERER_HPP
