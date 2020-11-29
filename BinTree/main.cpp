#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	tree t;
	t.push(1, 0), t.push(5, 1), t.push(3, 1), t.push(9, 0), t.push(6, 0), t.push(10, 1), t.push(8, -1), t.push(7, 1);
	show(1, t.getRoot());
	bool fl = true;
	bool clean = true;
	while (fl) {
		if (clean) {
			system("cls");
			show(1, t.getRoot());
		}
		cout << "Add node - add <index> <weight>\n"
			"Erase node - erase <index>\n"
			"Task - task\n"
			"Exit - exit" << endl;
		string command;
		cin >> command;
		if (command == "add") {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			t.push(atoi(tmp1.c_str()), atoi(tmp2.c_str()));
			clean = true;
		}
		else if (command == "erase") {
			string tmp;
			cin >> tmp;
			t.erase(atoi(tmp.c_str()));
			clean = true;
		}
		else if (command == "task") {
			taskB(t.getRoot());
			cout << endl;
			clean = false;
		}
		else if (command == "exit") {
			fl = false;
		}
	}
	return 0;
}