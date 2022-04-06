#include <iostream>

void change(int&& right_value) {
	right_value = 8;
}

void f(const int& x) {
	std::cout << "f1 " << x << std::endl;
}

// void f(int&& x) {
// 	std::cout << "f2 " << x << std::endl;
// }

int main() {
	// "abc" 左值
	int x = 1;
	std::cout << &(++x) << std::endl;
	// std::cout << &(x++) << std::endl;
	std::cout << &("abc") << std::endl;
	const int& y = x;
	std::cout << y << std::endl;
	
	int a = 5;
	int &ref_a_left = a;
	int &&ref_a_right = std::move(a);
	
	// change(a); // ERROR a是左值，change要求右值参数
	// change(ref_a_left);// 编译不过，ref_a_left本身也是个左值
	// change(ref_a_right);// 编译不过，ref_a_right本身也是个左值

	change(std::move(a)); // OK
	change(std::move(ref_a_left));
	change(std::move(ref_a_right));
		
	change(5);
	
	std::cout << &a << std::endl;
	std::cout << &ref_a_left << std::endl;
	std::cout << &ref_a_right << std::endl;
	
	f(5);
}
