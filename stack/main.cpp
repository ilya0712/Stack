#include <iostream>
#include "stack.h"


int main()
{
	try {
		Stack<int> stack;

		stack.push(100);
		stack.push(200);
		stack.push(300);
		stack.push(400);
		stack.push(100);
		stack.push(200);
		stack.push(300);
		std::cout << stack.getSize() << '\n';

		stack.pop();
		stack.pop();

		std::cout << stack.getSize() << '\n';
	}
	catch (int result)
	{
		if (result == -1)
			std::cout << "Overflow of stack\n";
	}


	return 0;
}