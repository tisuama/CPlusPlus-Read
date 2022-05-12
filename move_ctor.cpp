#include <iostream>
class MyIntArray {
public:
	MyIntArray() = default;
	MyIntArray(int size) {
		arr = new int[size];
		this->size = size;
		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}
	}

	// copy construct
	MyIntArray(const MyIntArray& r) {
		arr = new int[r.size];
		size = r.size;
		for (int i = 0; i < size; i++) {
			arr[i] = r.arr[i];
		}
	}

	// move construct
	MyIntArray(MyIntArray&& r) {
		r.swap(*this);
	}

	~MyIntArray() {
		delete [] arr;
	}
	
	// copy assignment
	MyIntArray& operator=(const MyIntArray& r) {
		if (&r != this) {
			MyIntArray temp(r);
			temp.swap(*this);
		}
		std::cout << "move assignment " << std::endl;
		return *this;
	}
	
	// move assignment
	MyIntArray& operator=(MyIntArray&& r) {
		MyIntArray temp(std::move(r));
		temp.swap(*this);
		return *this;
	}

	void swap(MyIntArray& r) {
		std::swap(arr, r.arr);
		std::swap(size, r.size);
	}

private:
	int* arr = nullptr;
	int size = 0;
};

int main() {
	MyIntArray a;
}
