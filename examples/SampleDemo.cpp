#include "SampleDemo.h"

SampleDemo::SampleDemo(QWidget *parent)
        : QGLWidget(parent) 
{
  setMouseTracking(true);
}

void SampleDemo::initializeGL()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
}

void SampleDemo::resizeGL(int w, int h)
{
  glViewport(0, 0, (GLint) w, (GLint)h);
}

void SampleDemo::paintGL()
{
  
}

void SampleDemo::mousePressEvent(QMouseEvent *event) 
{

}

void SampleDemo::mouseMoveEvent(QMouseEvent *event) 
{

}

void SampleDemo::keyPressEvent(QKeyEvent *event)
{

}
