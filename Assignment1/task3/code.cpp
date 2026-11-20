#include <climits>
#include <iostream>
#include <limits>

int main()
{
    bool peak = true;
    char grade = 'A';
    int hour = 8;
    long long balancePaise = 100000;
    unsigned int zoneNumber = 2;
    float percentage = 20.0f;
    double rupees = 36.00;
    auto journeyCount = 3000000LL;

    std::cout << "Data type sizes:\n";

    std::cout << "bool      : "
              << sizeof(bool) << " byte(s)\n";

    std::cout << "char      : "
              << sizeof(char) << " byte(s)\n";

    std::cout << "int       : "
              << sizeof(int) << " byte(s)\n";

    std::cout << "long long : "
              << sizeof(long long) << " byte(s)\n";

    std::cout << "unsigned  : "
              << sizeof(unsigned int) << " byte(s)\n";

    std::cout << "float     : "
              << sizeof(float) << " byte(s)\n";

    std::cout << "double    : "
              << sizeof(double) << " byte(s)\n";

    std::cout << "\nValues:\n";

    std::cout << "peak = " << peak << '\n';
    std::cout << "grade = " << grade << '\n';
    std::cout << "hour = " << hour << '\n';
    std::cout << "balance = " << balancePaise << " paise\n";
    std::cout << "zone = " << zoneNumber << '\n';
    std::cout << "percentage = " << percentage << '\n';
    std::cout << "rupees = " << rupees << '\n';
    std::cout << "journeys = " << journeyCount << '\n';

    std::cout << "\nInteger ranges:\n";

    std::cout << "INT_MIN = " << INT_MIN << '\n';
    std::cout << "INT_MAX = " << INT_MAX << '\n';

    std::cout << "LLONG_MIN = " << LLONG_MIN << '\n';
    std::cout << "LLONG_MAX = " << LLONG_MAX << '\n';

    std::cout << "\nMixed-type expressions:\n";

    int a = 7;
    int b = 2;

    double result1 = a / b;
    double result2 = static_cast<double>(a) / b;

    std::cout << "7 / 2 = " << result1 << '\n';
    std::cout << "static_cast<double>(7) / 2 = "
              << result2 << '\n';

    return 0;
}
