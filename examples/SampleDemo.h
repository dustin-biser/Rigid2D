#ifndef SAMPLE_DEMO_H
#define SAMPLE_DEMO_H

#include <QGLWidget>
#include <QTime>
#include <QTimer>
#include <iostream>
#include "Rigid2D.h"

class SampleDemo : public QGLWidget
{
  Q_OBJECT
  
  public: 
    SampleDemo(QWidget *parent = NULL);
    ~SampleDemo();
    int getFps();

  signals:
    void fpsChanged(int value);

  public slots:
    void paintGL();

  protected:
    QTimer *animationTimer;
    QTime *fpsTimer;
    int frameCount;
    int fps;
		Rigid2D::RigidBodySystem *rigidBodySystem;
    Rigid2D::RigidBody *body;

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void calculateFps();
};

#endif
