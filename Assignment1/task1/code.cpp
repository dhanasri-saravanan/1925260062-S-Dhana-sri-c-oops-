#include <iostream>
#include <string>

enum class Zone
{
    Inner,
    Middle,
    Outer
};

enum class PassengerType
{
    Regular,
    Student,
    Senior
};

class Passenger
{
private:
    std::string name;
    PassengerType type;

public:
    Passenger(const std::string& n, PassengerType t)
        : name(n), type(t)
    {
    }

    std::string getName() const
    {
        return name;
    }

    PassengerType getType() const
    {
        return type;
    }
};

class FareTable
{
public:
    static long long baseFare(Zone zone)
    {
        switch (zone)
        {
            case Zone::Inner:
                return 1000;

            case Zone::Middle:
                return 2000;

            case Zone::Outer:
                return 3000;
        }

        return 0;
    }
};

class SmartCard
{
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance)
        : balancePaise(balance)
    {
    }

    bool canTravel(long long fare) const
    {
        return balancePaise - fare >= 5000;
    }

    bool deduct(long long fare)
    {
        if (!canTravel(fare))
            return false;

        balancePaise -= fare;
        return true;
    }

    long long getBalance() const
    {
        return balancePaise;
    }
};

class Journey
{
private:
    Zone zone;
    bool peak;

public:
    Journey(Zone z, bool p)
        : zone(z), peak(p)
    {
    }

    long long calculateFare() const
    {
        long long fare = FareTable::baseFare(zone);

        if (peak)
        {
            fare += fare * 20 / 100;
        }

        return fare;
    }

    bool travel(SmartCard& card) const
    {
        return card.deduct(calculateFare());
    }
};

int main()
{
    Passenger passenger("Student", PassengerType::Student);

    SmartCard card(10000);

    Journey journey(Zone::Outer, true);

    long long fare = journey.calculateFare();

    std::cout << "Passenger: "
              << passenger.getName() << '\n';

    std::cout << "Fare: Rs "
              << fare / 100 << "."
              << (fare % 100 < 10 ? "0" : "")
              << fare % 100 << '\n';

    if (journey.travel(card))
    {
        std::cout << "Journey accepted\n";
    }
    else
    {
        std::cout << "Journey denied\n";
    }

    std::cout << "Remaining balance: Rs "
              << card.getBalance() / 100 << '\n';

    return 0;
}
