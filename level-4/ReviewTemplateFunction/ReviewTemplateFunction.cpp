#include <iostream>

template <typename T> T Sum(T n1, T n2) {
    return n1 + n2;
}

int main()
{
    std::cout << Sum(5.8, 1.8) << std::endl;
    std::cout << Sum<int>(7, 18) << std::endl;

    return 0;
}