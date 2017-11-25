#include <iostream>
using namespace std;
#include "list.h"

list::list() {
  head = NULL;
  current = NULL;
}

list::~list() {
  while (head) {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void list::insert(int a) {
  node *t = new node;
  t->next = head;
  head = t;
  head->val = a;
}

void list::goToHead() {
  current = head;
}

int list::getCurrentData() {
  return current->val;
}

void list::advance() {
  current = current->next;
}

bool list::moreData() {
  if (current) {
    return true;
  }
  else {
    return false;
  }
}

list::list(const list & l) {
  current=NULL;
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src) {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current) {
        current = *dst;
      }
      src = src->next;
      dst = &((*dst)->next);
    }
}

list & list::operator=(const list & l) {
  if (&l == this) {
    return *this;
  }
  node** destination = &head;
  node* source = l.head;
  while (true) {
      if(source == l.current) {
        current = *destination;
      }
      if(source != NULL && *destination != NULL) {
        (*destination)->val = source->val;
        source = source->next;
        destination = &((*destination)->next);
      }
      else if((*destination) != NULL && source == NULL) {
        while(*destination) {
          node *t = (*destination)->next;
          delete (*destination);
          (*destination) = t;
        }
      }
      else if(source != NULL && *destination == NULL) {
        while(source) {
          (*destination) = new node;
          (*destination)->val = source->val;
          (*destination)->next = NULL;
          source = source->next;
          destination = &((*destination)->next);
        }
      }
      else if ((*destination) == NULL && source == NULL) {
        break;
      }
    };
  return *this;
}
