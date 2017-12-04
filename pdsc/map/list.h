#include <iostream>

template <class T> class list {
private:
  struct node
  {
    node* next;
    T* val;
  };
  node* head;
  node* current;
public:
  list ();
  list (const list& l);
  list& operator=(const list& l);
  ~list ();
  void insert (const T& t);
  void goToHead ();
  T& getCurrentData ();
  void advance ();
  bool moreData ();
};
