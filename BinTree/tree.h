#pragma once
#include "link.h"

class tree {
	friend void show(int n, link* l);

	friend void taskB(link* l);
public:
	tree();

	link* getRoot() {
		return root;
	}

	void push(int val, int w);

	void erase(int val);

private:
	link* root;
	int size;
};