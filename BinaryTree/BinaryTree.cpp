#include "BinaryTree.h"

void BinaryTree::Insert(Node*& node, Node* parent, float value) {
	if (!node) { 
		node = new Node(parent, value);
	}
	else {
		if (value > node->Value) {
			Insert(node->Right, node, value);
		}
		else {
			Insert(node->Left, node, value);
		}
	}
}

bool BinaryTree::Search(Node* node, float value) {
	if (!node) {
		return false;
	}
	else if (node->Value == value) {
		return true;
	}
	else if (node->Value > value) {
		Search(node->Left, value);
	}
	else {
		Search(node->Right, value);
	}
}

bool BinaryTree::Erase(Node* node, float value) {
	if (!node) {
		return false;
	}
	else if (node->Value > value) {
		Erase(node->Left, value);
	}
	else if (node->Value < value) {
		Erase(node->Right, value);
	}
	else {
		EraseNode(node);
		return true;
	}
}

void BinaryTree::ReplaceNode(Node* node, Node* newNode) {
	if (node->Parent) {
		if (node->Parent->Left && node->Value == node->Parent->Left->Value) {
			node->Parent->Left = newNode;
		}
		else if (node->Parent->Right && node->Value == node->Parent->Right->Value) {
			node->Parent->Right = newNode;
		}
	}
	if (newNode) {
		newNode->Parent = node->Parent;
	}
}

void BinaryTree::EraseNode(Node* node) {
	if (node->Left && node->Right) {
		Node* min = Min(node->Right);
		node = min;
		EraseNode(min);
	}
	else if (node->Left) {
		ReplaceNode(node, node->Left);
		node->Left = nullptr;
		node->Right = nullptr;
		delete node;
	}
	else if (node->Right) {
		ReplaceNode(node, node->Right);
		node->Left = nullptr;
		node->Right = nullptr;
		delete node;
	}
	else {
		ReplaceNode(node, nullptr);
		node->Left = nullptr;
		node->Right = nullptr;
		delete node;
	}
}

Node* BinaryTree::Min(Node* node)
{
	if (!node) {
		return nullptr;
	}
	else if (node->Left) {
		return Min(node->Left);
	}
	else {
		return node;
	}
}

void BinaryTree::PrintPreOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		std::cout << node->Value << " - ";
		PrintPreOrder(node->Left);
		PrintPreOrder(node->Right);
	}
}

void BinaryTree::PrintInOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		PrintInOrder(node->Left);
		std::cout << node->Value << " - ";
		PrintInOrder(node->Right);
	}
}

void BinaryTree::PrintPostOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		PrintPostOrder(node->Left);
		PrintPostOrder(node->Right);
		std::cout << node->Value << " - ";
	}
}

BinaryTree::BinaryTree() {
	m_root = nullptr;
}

BinaryTree::~BinaryTree() {

}

void BinaryTree::Run() {
	int option = 0;
	float value;

	while (option != 7) {
		std::cout << "Menu principal\n Elige una opción:\n";
		std::cout << "1.- Insertar Nodo\n";
		std::cout << "2.- Buscar un valor\n";
		std::cout << "3.- Recorrido Pre-Orden\n";
		std::cout << "4.- Recorrido In-Orden\n";
		std::cout << "5.- Recorrido Post-Orden\n";
		std::cout << "6.- Eliminar un valor\n";
		std::cout << "7.- Salir\n";
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			std::cout << "Escriba el valor a insertar:\n";
			std::cin >> value;
			Insert(m_root, nullptr, value);
			std::cout << "\n";
			system("pause");
			break;
		}
		case 2:
		{
			std::cout << "Escriba el valor a buscar:\n";
			std::cin >> value;
			if (Search(m_root, value)) {
				std::cout << "El elemento " << value << " SI existe en el arbol\n";
			}
			else {
				std::cout << "El elemento " << value << " NO existe en el arbol\n";
			}
			system("pause");
			break;
		}
		case 3:
		{
			std::cout << "Recorrido Pre-Orden:\n";
			PrintPreOrder(m_root);
			std::cout << "\n";
			system("pause");
			break;
		}
		case 4:
		{
			std::cout << "Recorrido In-Orden:\n";
			PrintInOrder(m_root);
			std::cout << "\n";
			system("pause");
			break;
		}
		case 5:
		{
			std::cout << "Recorrido Post-Orden:\n";
			PrintPostOrder(m_root);
			std::cout << "\n";
			system("pause");
			break;
		}
		case 6:
		{
			std::cout << "Escriba el valor a eliminar:\n";
			std::cin >> value;
			if (Erase(m_root, value)) {
				std::cout << "Nodo eliminado correctamente\n";
			}
			else {
				std::cout << "No existe ningun nodo con ese valor\n";
			}
			system("pause");
			break;
		}
		default:
			std::cout << "Opción invalida\n";
			system("pause");
			break;
		}
		system("cls");
	}
}
