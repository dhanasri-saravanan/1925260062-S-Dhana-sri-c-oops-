#include <iostream>

enum class Zone
{
    Inner,
    Middle,
    Outer
};

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long getFare(Zone zone)
{
    switch (zone)
    {
        case Zone::Inner:
            return INNER_FARE_PAISE;

        case Zone::Middle:
            return MIDDLE_FARE_PAISE;

        case Zone::Outer:
            return OUTER_FARE_PAISE;
    }

    return 0;
}

int main()
{
    Zone zone = Zone::Middle;

    long long fare = getFare(zone);

    std::cout << "Base fare = Rs "
              << fare / 100 << "."
              << fare % 100 << '\n';

    std::cout << "Peak surcharge = "
              << PEAK_SURCHARGE_PERCENT
              << "%\n";

    std::cout << "Minimum balance = Rs "
              << MIN_BALANCE_PAISE / 100
              << '\n';

    return 0;
}
