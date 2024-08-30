#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	char me_ = 'a';
	Node* left_ = nullptr;
	Node* right_ = nullptr;
	Node(char first) { me_ = first; }

	Node* find_node(char target) {
		if (me_ == target) {
			return this;
		}

		Node* result = nullptr;

		if (left_) {
			result = left_->find_node(target);
			if (result) return result;
		}

		if (right_) {
			result = right_->find_node(target);
			if (result) return result;
		}

		return nullptr;
	}

	void add_left(char name) {
		left_ = new Node(name);
	}

	void add_right(char name) {
		right_ = new Node(name);
	}

	void preorder_traversal() {
		cout << me_;
		if (left_ != nullptr)
			left_->preorder_traversal();
		if (right_ != nullptr)
			right_->preorder_traversal();
	}

	void inorder_traversal() {
		if (left_ != nullptr)
			left_->inorder_traversal();
		cout << me_;
		if (right_ != nullptr)
			right_->inorder_traversal();
	}
	void postorder_traversal() {
		if (left_ != nullptr)
			left_->postorder_traversal();
		if (right_ != nullptr)
			right_->postorder_traversal();
		cout << me_;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	Node* tree = new Node('A');
	int N;
	cin >> N;
	char first, second, third;
	for (int i = 0; i < N; ++i) {
		Node* now;
		cin >> first >> second >> third;
		now = tree->find_node(first);
		if(second != '.')
			now->add_left(second);
		if (third != '.')
			now->add_right(third);
	}
	tree->preorder_traversal();
	cout << "\n";
	tree->inorder_traversal();
	cout << "\n";
	tree->postorder_traversal();
}