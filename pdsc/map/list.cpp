#include <iostream>
#include "list.h"
using namespace std;

template <typename T> list<T>::list() {
	head = nullptr;
	current = nullptr;
}

template <typename T> list<T>::~list() {
	while (head) {
		node *t = head->next;
		delete t->val;
		delete head;
		head = t;
	};
}

template <typename T> void list<T>::insert(T* t) {
	list<T>::node* temp = new node; //temp type = list<T>::node* 
	temp->next = head;
	head = temp;
	head->val = t;
}

template <typename T> void list<T>::goToHead() {
	current = head;
}

template <typename T> T* list<T>::getCurrentData() {
	return current->val;
}

template <typename T> void list<T>::advance() {
	current = current->next;
}

template <typename T> bool list<T>::moreData() {
	return current != nullptr;
}

template <typename T> list<T>::list (const list<T>& l) {
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

template <typename T> list<T>& list<T>::operator=(const list<T>& l) {
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
			node *temp = (*destination)->next;
			delete (*destination);
			(*destination) = temp;
		}
	}
	return *this;
}