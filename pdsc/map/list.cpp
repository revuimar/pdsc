#include <iostream>
using namespace std;
#include "list.h"

template <typename T> list<T>::list() {
	head = NULL;
	current = NULL;
}

template <typename T> list<T>::~list() {
	while (head) {
		node *t = head->next;
		delete t->val;
		delete head;
		head = t;
	};
}

template <typename T> void list<T>::insert(const T& t) {
	node *a = new node;
	t->next = head;
	head = a;
	head->val = &t;
}

template <typename T> void list<T>::goToHead() {
	current = head;
}

template <typename T> T& list<T>::getCurrentData() {
	return current->val;
}

template <typename T> void list<T>::advance() {
	current = current->next;
}

template <typename T> bool list<T>::moreData() {
	if (current) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T> list<T>::list (const list& l) {
	current=NULL;
	node *src, **dst;
	head = NULL;
	src = l.head;
	dst = &head;
	while (src)
	{
		*dst = new node;
		(*dst)->val = src->val;
		(*dst)->next = NULL;
		if(src == l.current) {
			current = *dst;
		}
		src = src->next;
		dst = &((*dst)->next);
    }
}

template <typename T> list<T>& list<T>::operator=(const list& l) {
	if (&l == this) {
		return *this;
	}
	current = NULL;
	node** destination = &head;
	node* source = l.head;
	while (source) {
		
		if(*destination != NULL) {
			(*destination)->val = source->val;
			source = source->next;
			destination = &((*destination)->next);
		}
		else {
			(*destination) = new node;
			(*destination)->val = source->val;
			(*destination)->next = NULL;
			source = source->next;
			destination = &((*destination)->next);
		}
		if(source == l.current) {
			current = *destination;
		}
	}
	if((*destination) != NULL && source == NULL) {
		while(*destination) {
			if(source == l.current) {
				current = *destination;
			}
			node *t = (*destination)->next;
			delete (*destination);
			(*destination) = t;
		}
	}
	return *this;
}