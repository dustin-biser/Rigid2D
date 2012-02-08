/* Compare perforamnce between pointers and vectors with respect to:
 * - member access
 * - being passed as parameters to functions
 * - being returned from functions
*/

#include <iostream>
#include "Timer.h"
#include <new>
#include <vector>
using namespace std;

#define COUNT 10000

//== Vector Functions =====================================
vector<float> & foo (vector<float> & v){
  for(int i = 0; i < COUNT; ++i){
    v[i] += 1;
  }
  return v;
}

void foo (vector<float> & vIn, vector<float> & vOut){
  for(int i = 0; i < COUNT; ++i){
    vOut[i] = vIn[i] + 1;
  }
}

//== Pointer Functions ====================================
float * foo (float * f){
  for(int i = 0; i < COUNT; ++i){
    f[i] += 1;
  }

  return f;
}

void foo(float * fIn, float * fOut){
  for(int i = 0; i < COUNT; ++i){
    fOut[i] = fIn[i] + 1;
  }
}


int main(){
  Timer timer;
  // Fill in v with zeros
  vector<float> v(COUNT, 0);
  vector<float> tmpv(COUNT,0);
  float *p = new float [COUNT];
  float *tmpf;
  int i;

  // Fill in p with zeros
  for(i = 0; i < COUNT; ++i){
    p[i] = 0;
  }

  cout << "Pointer functions: \n";
  cout << "\tPointer return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    tmpf = foo(p);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  cout << "\tVoid return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    tmpf = foo(p);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  cout << "Vector functions: \n";
  cout << "\tVector reference return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    tmpv = foo(v);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  cout << "\tVoid return: ";
  timer.start();
  for(i = 0; i < COUNT; ++i){
    foo(v, tmpv);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  delete [] p;

  return 0;
}
