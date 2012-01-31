#include <iostream>
#include "Timer.h"
#include <new>
#include <vector>
using namespace std;

#define COUNT 10000

vector<int> & foo (vector<int> & v){
  for(int i = 0; i < COUNT; ++i){
    v[i] += 1;
  }
  return v;
}

float * foo (float * f){
  for(int i = 0; i < COUNT; ++i){
    f[i] += 1;
  }

  return f;
}

void foo (vector<int> vIn, vector<int> vOut){
  for(int i; i < COUNT; ++i){
    vOut[i] = vIn[i] + 1;
  }
}

int main(){
  Timer timer;
  vector<int> v(COUNT, 0);
  vector<int> tmpv;
  float *p = new float [COUNT];
  float *tmpf;
  int i;

  //fill in p
  for(i = 0; i < COUNT; ++i){
    p[i] = 0;
  }

  cout << "Pointer return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    tmpf = foo(p);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  cout << "Vector return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    tmpv = foo(v);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  //cout << "Void return: ";
  //timer.start();
  //for(i = 0; i < COUNT; ++i){
    //foo(v, tmpv);
  //}
  //timer.stop();
  //cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  delete [] p;

  return 0;
}
