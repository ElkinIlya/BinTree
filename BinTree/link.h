#pragma once

class tree;

class link {
public:
	link(int id_val, int w);
	friend void show(int n, link* l);
	friend void taskB(link* l);
	friend class tree;

private:
	int id;
	int weight;
	link *left, *right;
};