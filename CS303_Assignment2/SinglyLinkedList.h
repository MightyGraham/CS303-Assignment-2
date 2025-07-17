#pragma once

#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H
#include <cstddef> // to use for size_t

class SinglyList {

private: //only accessible inside class
	struct Node {
		int data;
		Node* next;
		Node(int val) : data(val), next(nullptr) {}

	};
	Node* head;
	Node* tail;
	size_t num_items;

public: //accessible everywhere else
	//Constructors
	SinglyList();
	~SinglyList();

	void push_front(int item);
	void push_back(int item);
	void pop_front();
	void pop_back();
	int front() const;
	int back() const;
	bool empty() const;

	void insert(size_t index, const int& item);
	bool remove(size_t index);
	size_t find(const int& item) const;
};

#endif
