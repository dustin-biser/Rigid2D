#include "SampleDemo.h"

SampleDemo::SampleDemo(QWidget *parent)
        : QGLWidget(parent) 
{
  setMouseTracking(true);

  std::cout << "t";
  animationTimer = new QTimer(this);
  connect(animationTimer, SIGNAL(timeout()), this, SLOT(paintGL()));
  animationTimer->start(0);

  fpsTimer = new QTime;
  fpsTimer->start();
  frameCount = 0;
}

SampleDemo::~SampleDemo() 
{
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
  ///std::cout << "T";
  // Figure out fps
  float elapsed = fpsTimer->elapsed();
  if (elapsed >= 1000) {
    fps = frameCount * (elapsed/1000);
    fpsTimer->restart();
    frameCount = 0;
    emit fpsChanged(fps);
  }
  frameCount++;

  // Do drawing here!!
  glClear (GL_COLOR_BUFFER_BIT);
  glClearColor(1.0, 0.0, 0.0, 0.0);

  glBegin (GL_TRIANGLES);
  glColor3f (1.0, 0.0, 0.0);
  glVertex2f (5.0, 5.0);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2f (25.0, 5.0);
  glColor3f (0.0, 0.0, 1.0);
  glVertex2f (5.0, 25.0);
  glEnd();

  glFlush();
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

int SampleDemo::getFPS()
{
  return fps;
}
