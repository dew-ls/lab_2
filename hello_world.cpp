#include <iostream>

int
main()
{
  char* name; // varible for user's name
  std::cout << "Enter your name: ";
  std::cin >> name;                                 // initialising name
  std::cout << "Hello world from " << name << endl; // output
  return 0;
}
