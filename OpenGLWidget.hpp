#ifndef OPENGLWIDGET_HPP
#define OPENGLWIDGET_HPP

#include <QThread>
#include <QWindow>

class Renderer;

/*
 * This class is an intermediary to get access to a QSurface to draw to
 * It will be cast? and used as a regular QWidget belonging to a parent
 *
 */

class OpenGLWidget : public QWindow
{
    Q_OBJECT

public:
    explicit OpenGLWidget();
    ~OpenGLWidget();

private:
    Renderer *renderer;
    QThread *rendererThread;
};

#endif // OPENGLWIDGET_HPP
