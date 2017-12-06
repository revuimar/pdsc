#ifndef __List_H__
#define __List_H__
#include <iostream>
using namespace std;

template <typename T> class list {
private:
  struct node {
    node* next;
    T* val;
  };
  node* head;
  node* current;
public:
  list ();
  list (const list<T>& l);
  list<T>& operator=(const list<T>& l);
  ~list ();
  void insert (T* t);
  void goToHead ();
  T* getCurrentData ();
  void advance ();
  bool moreData ();
};
#endif