#include <iostream>

class Startegy {
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public Startegy {
public:
	int doOperation(int num1, int num2) {
		return num1 + num2;
	};
};

class OperationSubstract : public Startegy {
public:
	int doOperation(int num1, int num2) {
		return num1 - num2;
	};
};

class OperationMultiply : public Startegy {
public:
	int doOperation(int num1, int num2) {
		return num1 * num2;
	};
};

class Context {
private:
	Startegy* startegy;
public:
	Context(Startegy* startegy) {
		this -> startegy = startegy;
	}
	int executeStartegy(int num1, int num2) {
		return startegy -> doOperation(num1, num2);
	}
};

int main() {
	Context *context = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << context ->executeStartegy(10, 5) << std::endl;
	context = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << context -> executeStartegy(10, 5) << std::endl;
	context = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << context -> executeStartegy(10, 5) << std::endl;
}
