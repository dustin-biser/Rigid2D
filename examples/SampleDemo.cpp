#include "SampleDemo.h"
#include <QMouseEvent>

SampleDemo::SampleDemo(QWidget *parent)
        : QGLWidget(parent) 
{
  setMouseTracking(true);
  setAutoBufferSwap(true);
 
  animationTimer = new QTimer(this);
  connect(animationTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
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
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  glEnable(GL_DEPTH_TEST);
}

void SampleDemo::resizeGL(int w, int h)
{
  h = h?h:1;

  glViewport( 0, 0, (GLint)w, (GLint)h );

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)w / (GLfloat)h, 0.1f, 1000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void SampleDemo::paintGL()
{
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
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0, 0, -300);

  glBegin (GL_TRIANGLES);
  glColor3f (1, 0, 0);
  glVertex2f (0, 0);
  glColor3f (0, 1, 0);
  glVertex2f (30, 0);
  glColor3f (0, 0, 1);
  glVertex2f (15, 15);
  glEnd();

}

void SampleDemo::mousePressEvent(QMouseEvent *event) 
{
  std::cout << event->y() << std::endl;
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
