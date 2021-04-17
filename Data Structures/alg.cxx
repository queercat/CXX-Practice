#include <iostream>

class Vector2 {
	private:
		double x;
		double y;

	public:
		Vector2(double x, double y) {
			this->x = x;
			this->y = y;
		}

		void printValues();

		double getX();
		double getY();

		Vector2 multiply(Vector2 multiplicand);
		Vector2 divide(Vector2 dividand);
};

void Vector2::printValues() {
	std::cout << "X: " << x << std::endl;
	std::cout << "Y: " << y << std::endl;
}

double Vector2::getX() {
	return x;
}

double Vector2::getY() {
	return y;
}

Vector2 Vector2::multiply(Vector2 multiplicand) {
	double x_product = x * multiplicand.getX();
	double y_product = y * multiplicand.getY();

	return Vector2(x_product, y_product);
}

Vector2 Vector2::divide(Vector2 dividend) {
	double x_dividend = x / dividend.getX();
	double y_dividend = y / dividend.getY();

	return Vector2(x_dividend, y_dividend);
}

class Node {
	private:
		double value;
		Node* next;

	public:
		Node (double value = 0, Node* next = NULL) {
			this->value = value;
			this->next = next;
		}

		void printValue();
		void setNext(Node* node);

		double getValue();

		Node* getNext();
		Node* getTail();

};

Node* Node::getNext() {
	return next;
}

Node* Node::getTail() {
	Node* head = this;
	
	while(head->getNext() != NULL) {
		head = head->getNext();
	}

	return head;
}

double Node::getValue() {
	return value;
}

void Node::printValue()  {
	std::cout << "Node(" << value << ")" << std::endl;
}

void Node::setNext(Node* node) {
	if(node == NULL) {
		next = NULL;
	} else {
		next = node;
	}
}

class BinaryNode {
	private:
		double value;
		BinaryNode* left;
		BinaryNode* right;

	public:
		BinaryNode(double value = 0, BinaryNode* left = NULL, BinaryNode* right = NULL) {
			this->value = value;
			this->left = left;
			this->right = right;
		}

		double getValue();
		
		void setValue(double value);
		void setLeft(BinaryNode* left);
		void setRight(BinaryNode* right);

		BinaryNode* getLeft();
		BinaryNode* getRight();

		void printValue();
		void printTree();
};

double BinaryNode::getValue() {
	return value;
}

void BinaryNode::setValue(double value) {
	this->value = value;
}

void BinaryNode::setLeft(BinaryNode* left) {
	this->left = left;
}

void BinaryNode::setRight(BinaryNode* right) {
	this->right = right;
}

BinaryNode* BinaryNode::getLeft() {
	return left;
}

BinaryNode* BinaryNode::getRight() {
	return right;
}

void BinaryNode::printValue() {
	std::cout << value << std::endl;
}

void BinaryNode::printTree() {
	if (this == NULL) {
		return;
	}

	this->getLeft()->printTree();
	this->printValue();
	this->getRight()->printTree();
}

int main() {
	BinaryNode root = BinaryNode(1);
	BinaryNode left = BinaryNode(0);
	BinaryNode right = BinaryNode(2);

	root.setLeft(&left);
	root.setRight(&right);

	BinaryNode left_temp = BinaryNode(-1);
	BinaryNode right_temp = BinaryNode(3);

	left.setLeft(&left_temp);
	left.setRight(&right_temp);


	root.printTree();
}