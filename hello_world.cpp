#include <iostream>

int main()
{
	char * name; // переменная для имени пользователя
	std::cout << "Enter your name: " ; std::cin >> name; // инициализация переменной
	std::cout << "Hello world from " << name << endl; // вывод
	return 0;
}
