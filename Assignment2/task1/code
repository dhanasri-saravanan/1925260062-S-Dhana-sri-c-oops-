#include <iostream>

// Call by value
void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by reference
void applyByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long* fee, int percent)
{
    *fee -= (*fee) * percent / 100;
}

// Given prediction program
void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10)
{
    std::cout << x + y + z << ' ';
}

int main()
{
    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);
    std::cout << "After call by value: " << hostelFee << '\n';

    applyByReference(hostelFee, 10);
    std::cout << "After call by reference: "
              << hostelFee << '\n';

    applyByPointer(&hostelFee, 10);
    std::cout << "After call by pointer: "
              << hostelFee << '\n';

    std::cout << "\nPredict Output Program:\n";

    int a = 1, b = 2, c = 3;

    change(a, b, &c);

    std::cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;

    std::cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);

    std::cout << '\n';

    return 0;
}
