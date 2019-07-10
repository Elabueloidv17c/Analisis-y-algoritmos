#pragma once
#include <iostream>

struct Node {
	float Value;
	Node* Parent;
	Node* Left;
	Node* Right;

	Node(Node* parent, float value) {
		Value = value;
		Parent = parent;
		Left = nullptr;
		Right = nullptr;
	}
};

