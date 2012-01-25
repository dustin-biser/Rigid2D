#include "SampleDemo.h"
#include <QMouseEvent>

using namespace Rigid2D;

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

  Real *vertex_array = new Real[8];
  Real temp_arr[8] = {-5, 5, 5, 5,
                          5, -5, -5, -5};
  memcpy(vertex_array, temp_arr, 8 * sizeof(Real));
  body = new RigidBody(Vector2(0, 0), 10.0, vertex_array, 8, Vector2(0, 0));
}

SampleDemo::~SampleDemo() 
{
}

void SampleDemo::initializeGL()
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);

  glEnable(GL_DEPTH_TEST);
  glEnableClientState(GL_VERTEX_ARRAY);
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

  glTranslatef(0, 0, -30);

  glColor3f (1, 1, 1);
  glVertexPointer(2, GL_FLOAT, 0, body->getVertexArray());
  glDrawArrays(GL_POLYGON, 0, body->getVertexCount());

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
