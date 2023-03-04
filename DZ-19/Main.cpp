#include <iostream>
#include <cstdlib>
#include <ctime>

int p,maxx;
int max(int num1,int num2) {
	
	for (int i = 1; i <= num1; i++)
		if (num1 % i == 0 && num2 % i == 0)
			maxx = i;

	return maxx;
}
//int max(int num1, int num2) {
//	int m=0;
//	int i=2;
//	if (i == num1 || i == num2) return m;
//	if (num1 % i == 0 && num2 % i == 0)
//		m = i;
//	i++;
//	
//	return max(num1, num2);
//}

int mirror_number(int num) {
	int mirror = 0;
	while (num>=10){
		mirror += num % 10;
		mirror *= 10;
		num /= 10;
	}
	mirror += num;
	return mirror;
}

template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

int Pr_position(int arr[], const int length, int value) {
		for (int i = 0; i < length; i++) 
			if (arr[i] == value) 
				p = i;	
		for (int i = length - 1; i >= 0; i--)
			for (int j = p; j < i; j++)
				if (arr[j] > arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
		return p;
	return -1;
}

void filling(int arr[], const int length, int num1, int num2) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (num2 - num1) + num1;
}

int main() {
	setlocale(LC_ALL, "Russian");


	std::cout << " Çàäà÷à 1 \n ";
	int a, b;
	std::cout << " Ââåäèòå äâà ÷èñëà -> ";
	std::cin >> a >> b;
	std::cout << max(a,b) << '\n';
	std::cout << "\n\n";

	std::cout << " Çàäà÷à 2 \n ";
	int q;
	std::cout << " Ââåäèòå ÷èñëî -> ";
	std::cin >> q;
	std::cout << " Çåðêàëî ÷èñëà "<<q<<" - "<<mirror_number(q) << "\n";
	std::cout << "\n\n";

	std::cout << " Çàäà÷à 3 \n ";
	std::cout << "Ìàññèâ :\n";
	int n;
	const int size = 10;
	int arr[size]{ 10,16,49,34,2,6,16,10,5,24 };
	//            0  1 2   3 4 5  6  7 8  9 
	print_arr(arr, size);
	std::cout << " Ââåäèòå ÷èñëî èç ìàññèâà : ";
	std::cin >> n;
	int index = 0;
	index = Pr_position(arr, size, n);
	
	if (index != -1)
		std::cout << " Èíäåêñ ÷èñëà " << n << " : " << index << '\n';
	else
		std::cout << " ×èñëà íåò â ìàññèâå \n";
	print_arr(arr, size);
	std::cout << "\n\n";

	std::cout << " Çàäà÷à 4 \n ";
	const int size2 = 14;
	int arr2[size2]{};
	int g, h;
	std::cout << " Ââåäèòå äâà ÷èñëà, íà÷àëî è êîíåö äèàïàçîíà -> ";
	std::cin >> g >> h;
	filling(arr2, size2, g, h);
	std::cout << " Çàïîëíåííûé ìàññèâ \n";
	for (int i = 0; i < size2; i++)
		std::cout << arr2[i] << ' ';
	std::cout << "\n\n";



	return 0;
}
