#include <iomanip>
#include <iostream>

class Money
{
private:
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p)
    {
    }

    // Addition
    Money operator+(const Money& other) const
    {
        Money result;

        result.paise =
            paise + other.paise;

        return result;
    }

    // Subtraction
    Money operator-(const Money& other) const
    {
        Money result;

        result.paise =
            paise - other.paise;

        return result;
    }

    // Compound addition
    Money& operator+=(const Money& other)
    {
        paise += other.paise;

        return *this;
    }

    // Equality
    bool operator==(const Money& other) const
    {
        return paise == other.paise;
    }

    // Less-than
    bool operator<(const Money& other) const
    {
        return paise < other.paise;
    }

    // Output
    friend std::ostream& operator<<(
        std::ostream& out,
        const Money& money)
    {
        long long rupees =
            money.paise / 100;

        long long p =
            money.paise % 100;

        if (money.paise < 0)
        {
            long long absolutePaise =
                -money.paise;

            rupees =
                absolutePaise / 100;

            p =
                absolutePaise % 100;

            out << "-Rs "
                << rupees
                << '.'
                << std::setw(2)
                << std::setfill('0')
                << p;

            out << std::setfill(' ');

            return out;
        }

        out << "Rs "
            << rupees
            << '.'
            << std::setw(2)
            << std::setfill('0')
            << p;

        out << std::setfill(' ');

        return out;
    }

    // Input
    friend std::istream& operator>>(
        std::istream& in,
        Money& money)
    {
        long long rupees;
        int p;

        in >> rupees >> p;

        money.paise =
            rupees * 100 + p;

        return in;
    }
};

int main()
{
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    std::cout
        << c
        << '\n';

    std::cout
        << std::boolalpha
        << (c == Money(200))
        << '\n';

    // Paise carry
    Money x(0, 75);
    Money y(0, 50);

    Money z = x + y;

    std::cout
        << "75 paise + 50 paise = "
        << z
        << '\n';

    // Subtraction producing negative value
    Money negative =
        Money(50) - Money(75);

    std::cout
        << "50 - 75 = "
        << negative
        << '\n';

    // +=
    Money total(100);

    total += Money(25, 50);

    std::cout
        << "After += : "
        << total
        << '\n';

    return 0;
}
