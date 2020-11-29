#include "tree.h"
#include <iostream>

using namespace std;

int main() {
	tree t;
	t.push(1, 0), t.push(5, 2), t.push(3, 4), t.push(9, 0), t.push(6, 0), t.push(10, 1), t.push(8, -1), t.push(7, 3);
	show(1, t.getRoot());
	std::cin.get();
	t.erase(5);
	system("cls");
	show(1, t.getRoot());
	std::cin.get();
	taskB(t.getRoot());
	std::cin.get();
	return 0;
}