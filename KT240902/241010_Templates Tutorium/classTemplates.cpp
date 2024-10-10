#include<iostream>

template <typename T> class Array {
private:
	T* ptr;
	int size;

public:
	Array(T arr[], int s);
	void print();
};

template <typename T> Array<T>::Array(T arr[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++) ptr[i] = arr[i];
}

template <typename T> void Array<T>::print() {
	for (int i = 0; i < size; i++) std::cout << ptr[i] << " ";
	std::cout << std::endl;
}

template <typename T1, typename T2 = char> class PairClass {
	T1 x;
	T2 y;
public:
	PairClass() {
		std::cout << "Konstruktor aufgerufen" << std::endl;
	}
};

// class das gleiche wie typename
template <class T, int max> int arrMin(T arr[], int n) {
	int m = max;
	for (int i = 0; i < n; i++) if (arr[i] < m) m = i;
	return m;
};

template <typename T> class Info {
public:
	Info(T a) {
		std::cout << "a = " << a << " Anzahl der bytes: " << sizeof(a) << std::endl;
	}
};

int main() {
	char arr[5] = { 'h', 'H', 'a', 'x', 'X' };
	Array<char> charArray(arr, 5);
	charArray.print();

	PairClass<int, double> somePair;
	PairClass<int> pairWithDefault;

	int arrInt[] = { 3,4,1,6,8 };

	std::cout << arrMin<int, 1000>(arrInt, std::size(arrInt)) << std::endl;
	std::cout << arrMin<char, 256>(arr, 5) << std::endl;

	Info<char> p('x');
	Info<int> q(22);
	Info<double> r(2.25);
	Info<float> s(3.12);

	return 0;
}