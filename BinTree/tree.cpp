#include "tree.h"
#include <iostream>
#include <iomanip>

tree::tree() : size(0), root(nullptr) {};

void tree::push(int val, int w) {
	link* new_node = new link(val, w);
	size++;
	if (root == nullptr) {
		root = new_node;
	}
	else {
		link* tmp = root;
		while (true) {
			if (val < tmp->id) {
				if (tmp->left == nullptr)
					break;
					tmp = tmp->left;
			}
			else {
				if (tmp->right == nullptr)
					break;
				tmp = tmp->right;
			}
		}
		if (val < tmp->id) {
			tmp->left = new_node;
		}
		else {
			tmp->right = new_node;
		}
	}
}

void tree::erase(int val) {
	size--;
	char c;
	link* tmp = root;
	link* prev = root;
	while (tmp->id != val) {
		prev = tmp;
		if (val < tmp->id) {
			tmp = tmp->left;
			c = 'l';
		}
		else {
			tmp = tmp->right;
			c = 'r';
		}
	}
	if (tmp->left == nullptr && tmp->left == nullptr) {
		if (c == 'l') {
			prev->left = nullptr;
		}
		else {
			prev->right = nullptr;
		}
	}
	else {
		if (tmp->left == nullptr) {
			if (c == 'l') {
				prev->left = tmp->right;
			}
			else {
				prev->right = tmp->right;
			}
		}
		else
			if (tmp->right == nullptr) {
				if (c == 'l') {
					prev->left = tmp->left;
				}
				else {
					prev->right = tmp->left;
				}
			}
			else {
				link* cop = tmp;
				prev = tmp;
				tmp = tmp->left;
				while (tmp->right != nullptr) {
					prev = tmp;
					tmp = tmp->right;
				}
				cop->id = tmp->id;
				if (tmp->left == nullptr) {
					if (prev == cop) {
						prev->left = nullptr;
					}
					else {
						prev->right = nullptr;
					}
				}
				else {
					if (prev == cop) {
						prev->left = tmp->left;
					}
					else {
						prev->right = tmp->left;
					}
				}
			}
	}
}

void taskB(link* l) {
	if (l != nullptr) {
		taskB(l->left);
		if ((l->left != nullptr || l->right != nullptr) && l->weight != 0) {
			std::cout << l->id << " ";
		}
		taskB(l->right);
	}
}

void show(int n, link* l) {
	link* tmp = l;
	if (tmp != nullptr) {
		show(n + 1, tmp->left);
		std::cout << std::setw(n * 3) << tmp->id << std::endl;
		show(n + 1, tmp->right);
	}
}