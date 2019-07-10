#pragma once
#include "Headers.h"

class BinaryTree
{
	Node* m_root;

public:

	void Insert(Node*& node, Node* parent, float value);
	bool Search(Node* node, float value);
	void Run();

	void ReplaceNode(Node* node, Node* newNode);
	bool Erase(Node* node, float value);
	void EraseNode(Node* node);
	Node* Min(Node* node);

	void PrintPreOrder(Node* node);
	void PrintInOrder(Node* node);
	void PrintPostOrder(Node* node);

	BinaryTree();
	~BinaryTree();
};

