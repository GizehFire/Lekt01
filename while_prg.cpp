
#include<iostream>

int userInput;

int main() {

while (true)
{
    std::cout << "Enter a positive number to exit: ";
    std::cin >> userInput;
    if (userInput > 0)
  {
        break;
    }
    std::cout << "Invalid input. Try again.";
}

}