#include <iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int value) {
			data = value;
			left = NULL;
			right = NULL;
		}
};

class Queue {
	private:
		struct QueueNode {
			Node* data;
			QueueNode* next;
			QueueNode(Node* value) {
				data=value;
				next=NULL;
			}
		};

		QueueNode* front;
		QueueNode* rear;

	public:
		Queue() {
			front=NULL;
			rear=NULL;
		}

		bool isEmpty() {
			return front == NULL;
		}

		void enqueue(Node* value) {
			QueueNode* newNode = new QueueNode(value);
			if (rear == NULL) {
				front = rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
		}

		void dequeue() {
			if (isEmpty()) {
				cout << "Queue is empty!" << endl;
				return;
			}
			QueueNode* temp = front;
			front = front->next;
			if (front == NULL) {
				rear = NULL;
			}
			delete temp;
		}

		Node* getFront() {
			if (isEmpty()) {
				cout << "Queue is empty!" << endl;
				return NULL;
			}
			return front->data;
		}
};

class BinaryTree {
	public:
		Node* root;

		BinaryTree() {
			root = NULL;
		}

		void inOrder(Node* root) {
			if (root != NULL) {
				inOrder(root->left);
				cout << root->data << " ";
				inOrder(root->right);
			}
		}

		void preOrder(Node* root) {
			if (root != NULL) {
				cout << root->data << " ";
				preOrder(root->left);
				preOrder(root->right);
			}
		}

		void postOrder(Node* root) {
			if (root != NULL) {
				postOrder(root->left);
				postOrder(root->right);
				cout << root->data << " ";
			}
		}

		void printLevelOrder(Node* root) {
			if (root == NULL)
				return;

			Queue q;
			q.enqueue(root);

			while (!q.isEmpty()) {
				Node* current = q.getFront();
				cout << current->data << " ";
				if (current->left != NULL)
					q.enqueue(current->left);
				if (current->right != NULL)
					q.enqueue(current->right);
				q.dequeue();
			}
		}
};

int main() {
	BinaryTree bt;
	bt.root = new Node(1);
	bt.root->left = new Node(2);
	bt.root->right = new Node(3);
	bt.root->left->left = new Node(4);
	bt.root->left->right = new Node(5);

	cout << "**PREORDER***\n";
	bt.preOrder(bt.root);
	cout << "\n**INORDER***\n";
	bt.inOrder(bt.root);
	cout << "\n**POSTORDER***\n";
	bt.postOrder(bt.root);
	cout << "\n**LEVEL ORDER**\n";
	bt.printLevelOrder(bt.root);

	return 0;
}
