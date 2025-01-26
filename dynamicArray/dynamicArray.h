#pragma once
#include <iostream>
using namespace std;

class dynamicArray
{
private:
	int size;
	int capacity;
	int* arr;
public:
	dynamicArray(int capacity):capacity(capacity),size(0)
	{
		arr = new int[capacity];
	}
	~dynamicArray() {
		delete[] arr;
		cout << "memory freed"<<endl;
	}
	void addElement(int number) {
		if (size < capacity)
		{
			arr[size++] = number;
		}
		else cout << "array is full";
	}
	void dispalyArray() {
		if (size == 0) { cout << "array is empty" << endl; }
		else {
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
	int getSize() const {
		return size;
	}
	

};
int main() {

	dynamicArray myArray(5);
	myArray.addElement(1);
	myArray.addElement(1);
	myArray.addElement(1);
	myArray.addElement(1);
	myArray.addElement(1);
	myArray.dispalyArray();

	return 0;
}

