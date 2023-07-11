#include <iostream>
#include <string>
#include "stack.h"

bool correctPair(char a, char b) {
	switch (a) {
		case '(':
			return a + 1 == b;
		case '[':
		case '{':
			return a + 2 == b;
	}
	return false;
}

int bracket(string str) {
	Stack stack;
	for(int i=0; i<str.size(); i++) {
		switch(str[i]) {
			case '(':
			case '[':
			case '{':
				stack.push(str[i]);
				break;

			case ')':
			case ']':
			case '}':
				// Too many closing
				if(stack.empty()) return -1;
				char top = stack.getTop();
				stack.pop();
				// Wrong match
				if(!correctPair(top, str[i])) return 2147483647;
				break;
		}
	}
	// 1 Too many opening; 0 Correct
	return (int)(!stack.empty());
}

int main(int argc, char* argv[]) {

	for(int i = 1; i < argc; i++) {
		switch(bracket(argv[i])) {
			case 0:
				std::cout << "Correct" << std::endl;
				break;
			case 1:
				std::cout << "Too many opening brackets" << std::endl;
				break;
			case -1:
				std::cout << "Too many closing brackets" << std::endl;
				break;
			case 2147483647:
				std::cout << "Wrong match" << std::endl;
				break;
		}
	}

	return 0;
}
