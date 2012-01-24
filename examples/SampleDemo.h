#ifndef SAMPLE_DEMO_H
#define SAMPLE_DEMO_H

#include <QGLWidget>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "RigidSettings.h"
#include "Objects/RigidBody.h"

class SampleDemo : public QGLWidget
{
  Q_OBJECT
  
  public: 
    SampleDemo(QWidget *parent = NULL);
    ~SampleDemo();

  signals:
    void fpsChanged(int value);

  public slots:
    void paintGL();

  protected:
    QTimer *animationTimer;
    QTime *fpsTimer;
    int frameCount;
    int fps;
    RigidBody *body;
    

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    int getFPS();
};

#endif
