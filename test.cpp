#include <iostream>
#include <string>

using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int num;
};

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int total = 0;
	Node* front = nullptr;
	Node* back = nullptr;

	int N;
	cin >> N;
	string s;
	int num;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		if (s == "push_front") {
			cin >> num;
			Node* new_node = new Node;
			new_node->num = num;
			if (total == 0) {
				new_node->next = nullptr;
				front = new_node;
				back = new_node;
			}
			else {
				front->prev = new_node;
				new_node->next = front;
				front = new_node;
			}
			total++;
		}
		else if (s == "push_back") {
			cin >> num;
			Node* new_node = new Node;
			new_node->num = num;
			if (total == 0) {
				new_node->next = nullptr;
				front = new_node;
				back = new_node;
			}
			else {
				back->next = new_node;
				new_node->prev = back;
				back = new_node;
			}
			total++;
		}
		else if (s == "pop_front") {
			if (total == 0) {
				cout << "-1\n";
			}
			else {
				cout << front->num << "\n";
				Node* now_node = front;
				front = front->next;
				delete now_node;
				total--;
			}
		}
		else if (s == "pop_back") {
			if (total == 0) {
				cout << "-1\n";
			}
			else {
				cout << back->num << "\n";
				Node* now_node = back;
				back = back->prev;
				delete now_node;
				total--;
			}
		}
		else if (s == "size") {
			cout << total << "\n";
		}
		else if (s == "empty") {
			if (total == 0) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (s == "front") {
			if (total == 0) {
				cout << "-1\n";
			}
			else {
				cout << front->num << "\n";
			}
		}
		else if (s == "back") {
			if (total == 0) {
				cout << "-1\n";
			}
			else {
				cout << back->num << "\n";
			}
		}
	}
}	