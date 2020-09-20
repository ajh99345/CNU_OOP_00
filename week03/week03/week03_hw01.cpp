#include <iostream>
class SetValue {
private:
	int x, y;
public:
	void xsetter(int value);
	void ysetter(int value);
	int xgetter();
	int ygetter();
};

void SetValue::xsetter(int value) {
	x = value;
}

void SetValue::ysetter(int value) {
	y = value;
}

int SetValue::xgetter() {
	return x;
}

int SetValue::ygetter() {
	return y;
}

int main() {
	SetValue obj;
	obj.xsetter(33);
	obj.ysetter(44);

	std::cout << "X= " << obj.xgetter() << " , Y= " << obj.ygetter() << std::endl;
	system("pause");
	return 0;
}