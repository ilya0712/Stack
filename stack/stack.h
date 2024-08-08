
#include <iostream>
#define MAX_SIZE 10


template<class T>
struct Node
{
	Node* next;
	T data;

	Node()
	{
		next = nullptr;
		data = 0;
	}
	Node(T value)
	{
		next = nullptr;
		data = value;
	}
};


template<class T>
struct Stack
{
	Node<T>* top;
	int size = 0;

	Stack()
	{
		top = nullptr;
	}
	~Stack();

	void deleteAll();
	void getTopInfo() const;
	void print() const;
	void pop();
	int  getSize() const;
	bool isEmpty() const;
	Node<T>* push(T value);
};


template<class T>
Stack<T>::~Stack<T>()
{
	deleteAll();
}


template<class T>
void Stack<T>::deleteAll()
{
	while (top != nullptr)
		pop();
}


template<class T>
void Stack<T>::print() const
{
	if (top == nullptr)
	{
		std::cout << "Stack is empty, no info to output\n";
		return;
	}

	Node<T>* node = top;
	while (node != nullptr)
	{
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << '\n';
}


template<class T>
void Stack<T>::pop()
{
	if (top == nullptr)
	{
		std::cout << "Stack have no elements to delete;\n";
		return;
	}

	size--;
	Node<T>* node = top->next;
	delete top;
	top = node;
}


template<class T>
int Stack<T>::getSize() const
{
	return size;
}


template<class T>
bool Stack<T>::isEmpty() const
{
	return (top == nullptr) ? true : false;
}


template<class T>
Node<T>* Stack<T>::push(T value)
{
	if (size == MAX_SIZE)
	{
		std::cout << "Stack is full now\n";
		throw - 1;
	}

	Node<T>* curr = new Node<T>(value);
	size++;

	if (top == nullptr)
	{
		top = curr;
		return curr;
	}

	curr->next = top;
	top = curr;

	return curr;
}


template<class T>
void Stack<T>::getTopInfo() const
{
	std::cout << "Top of stack have a value of: " << top->data;
	std::cout << "\t and the addres: " << top << '\n';
}
