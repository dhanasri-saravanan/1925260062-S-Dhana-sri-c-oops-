#include <iostream>
#include <string>

struct Parcel
{
    double kg;
    bool express;
    bool insured;
};

// Weight given in grams
double charge(int grams)
{
    std::cout << "charge(int grams)\n";

    return 50.0 + grams * 0.05;
}

// Weight given in kilograms
double charge(double kg,
              bool express = false,
              bool insured = false)
{
    std::cout << "charge(double kg, bool, bool)\n";

    double total = 50.0 + kg * 20.0;

    if (express)
    {
        total += 30.0;
    }

    if (insured)
    {
        total += 15.0;
    }

    return total;
}

// Parcel overload
double charge(const Parcel& p)
{
    std::cout << "charge(Parcel)\n";

    return charge(p.kg, p.express, p.insured);
}

int main()
{
    std::cout << "Call 1:\n";
    charge(2);

    std::cout << "\nCall 2:\n";
    charge(2.0);

    std::cout << "\nCall 3:\n";
    charge(2.0f);

    std::cout << "\nCall 4:\n";
    charge(2, true);

    std::cout << "\nCall 5:\n";
    charge(2.5, true, true);

    std::cout << "\nCall 6:\n";
    charge(Parcel{2.0, true, false});

    return 0;
}
