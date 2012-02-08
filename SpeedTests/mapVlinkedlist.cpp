/* Compare performance of unordered_set and linked lists as they would
 * be used in Force and RigidBodySystem.
*/

// COMPILE WITH -std=c++0x flag

#include <iostream>
#include <vector>
#include <unordered_set>
#include "Timer.h"

using namespace std;

typedef unordered_set<float*> FloatPointerSet;

template<class T> class LLNode {
public:
  LLNode *next;
  LLNode *prev;
  T data;
};

template<class T> class LinkedList {
public:
  LLNode<T> *root;
  LinkedList() {
    root = new LLNode<T>;
  }
  void insertNoCheck(T el) {
    LLNode<T> *new_root = new LLNode<T>;
    new_root->next = root;
    if (root)
      root->prev = new_root;
    new_root->data = el;
    root = new_root;
  }
};

int main(){
  Timer timer;
  int numEntries = 1000;
  float **listOfAddresses = new float*[numEntries];
  FloatPointerSet set;
  LinkedList<float*> ll;

  /* Init pointers */
  for (int i = 0; i < numEntries; i++) {
    listOfAddresses[i] = new float;
  }

  cout << "Testing with " << numEntries << endl;
  cout << "Using unordered_set inserts for init (checks duplicates): ";
  timer.start();
  for (int i = 0; i < numEntries/2; i++) {
    set.insert(listOfAddresses[i]);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  cout << "Using list inserts for init (does not check duplicates): ";
  timer.start();
  for (int i = 0; i < numEntries/2; i++) {
    ll.insertNoCheck(listOfAddresses[i]);
  }
  timer.stop();
  cout << timer.getElapsedTimeInMilliSec() << " ms.\n";

  

  return 0;
}
