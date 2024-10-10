#include <iostream>

// SFINAE = SUbstitution Failure Is Not An Error (C++17)
template<typename T> 
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
myMax(T x, T y) {
	return (x > y) ? x : y;
}

// Concepts (ab C++20)
//template<typename T>
//requires is_floating_point_v<T>
//T add(T a, T b) {
//
//}

template <class T> void bubbleSort(T a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; i < j; j--) {
			if (a[j] < a[j - 1]) 
				std::swap(a[j], a[j - 1]);
		}
	}
}

int main_() {
	std::cout << myMax<int>(3, 7) << std::endl;
	std::cout << myMax<double>(3.2, 1.4) << std::endl;
	std::cout << myMax<char>('c', 'ä') << std::endl;

	int a[5]{ 50, 13 ,40 ,20, 33 };
	int n = std::size(a);

	bubbleSort<int>(a, n);
	for (auto i : a) std::cout << i << " ";
	return 0;
}