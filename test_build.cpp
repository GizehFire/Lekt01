#include <iostream>

int main() {
    std::cout << "Kompiliert mit Flags: " << BUILD_FLAGS << std::endl;
    std::cout << "C++-Standard: " << __cplusplus << std::endl;

    return 0;
}