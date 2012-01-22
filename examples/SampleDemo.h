#ifndef SAMPLE_DEMO_H
#define SAMPLE_DEMO_H

#include <QGLWidget>


class SampleDemo : public QGLWidget
{
  Q_OBJECT
  
  public: 
    SampleDemo(QWidget *parent = NULL);

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif
