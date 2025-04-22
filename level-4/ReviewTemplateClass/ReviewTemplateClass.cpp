#include <iostream>

template <class T> class clsCalculater {
private:
    T n1, n2;

public:
    clsCalculater(T n1, T n2) {
        this->n1 = n1;
        this->n2 = n2;
    }

    T Sum() {
        return n1 + n2;
    }

    T Subtract() {
        return n1 - n2;
    }

    T Multiply() {
        return n1 * n2;
    }

    T Divied() {
        return n1 / n2;
    }

    void Print() {
        std::cout << "Results:-\n";
        std::cout << n1 << " + " << n2 << " = " << Sum() << std::endl;
        std::cout << n1 << " - " << n2 << " = " << Subtract() << std::endl;
        std::cout << n1 << " * " << n2 << " = " << Multiply() << std::endl;
        std::cout << n1 << " / " << n2 << " = " << Divied() << std::endl;
    }

};

int main()
{
    clsCalculater<int> intCalc(50, 5);
    intCalc.Print();

    std::cout << std::endl;

    clsCalculater<float> floatCalc(10.5, 2.5);
    floatCalc.Print();

    return 0;
}