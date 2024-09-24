#include <iostream>
#include <string>;

int factorial(int);
int fibonacci(int);
int sumArray(int[], int);
void reverseString(std::string&, int, int);

int main() {
	int n = 9;
	std::cout << "Fakultät von " << n << " = " << factorial(n) << std::endl;

	for (int i = 0; i < n; i++) {
		std::cout << fibonacci(i) << " ";
	}
	std::cout << std::endl;

	int arr[] { 1, 1, 1, 2, 5, 6, 8 };
	int length = std::size(arr);

	int sum = sumArray(arr, length);

	std::cout << "Summe des arrays: " << sum << std::endl;

	std::string str = "Hallo Freunde, wie geht es?";
	reverseString(str, 0, str.length() - 1);

	std::cout << "Umgekehrter string: " << str << std::endl;

	return 0;
}
/// <summary>
/// Berechnet die Fakultät einer ganzen Zahl ( n! = n * (n-1)! )
/// </summary>
/// <param name="n">Die Zahl, von der die Fakultät berechnet werden soll.</param>
/// <returns>Die Fakultät der Zahl n</returns>
int factorial(int n) {
	if (n <= 0) return 1;
	return n * factorial(n - 1);
}

/// <summary>
/// Erstellt die Fibonacci-Sequenz als Zahlenfolge. Jede Zahl ist die Summe der beiden vorherigen Zahlen.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumArray(int arr[], int n) {
	if (n == 0) return 0;
	return arr[n - 1] + sumArray(arr, n - 1);
}

/// <summary>
/// Einen string rekursive umkehren.
/// </summary>
/// <param name="str">Der String der umgekehrt werden soll</param>
/// <param name="start"></param>
/// <param name="end"></param>
void reverseString(std::string& str, int start, int end) {
	// Basisfall: Wenn start >= end ist, ist der string umgekehrt
	if (start >= end) return;

	// vertausche die Zeichen am Start- und Endindex
	std::swap(str[start], str[end]);
	// Rekursiver Fall:
	reverseString(str, start + 1, end - 1);
}