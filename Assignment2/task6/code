#include <iostream>
#include <cstdlib>

class Time
{
private:
    int h;
    int m;

public:
    Time(int hh, int mm)
        : h(hh), m(mm)
    {
    }

    friend int minutesBetween(
        const Time& a,
        const Time& b
    );

    friend bool earlier(
        const Time& a,
        const Time& b
    );
};

// Friend + inline function
inline int minutesBetween(
    const Time& a,
    const Time& b)
{
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    return std::abs(timeA - timeB);
}

// Friend + inline function
inline bool earlier(
    const Time& a,
    const Time& b)
{
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    return timeA < timeB;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    std::cout
        << minutesBetween(departure, arrival)
        << ' '
        << std::boolalpha
        << earlier(arrival, departure)
        << '\n';

    // Same time
    Time t1(12, 30);
    Time t2(12, 30);

    std::cout
        << minutesBetween(t1, t2)
        << ' '
        << earlier(t1, t2)
        << '\n';

    // Before and after noon
    Time morning(11, 50);
    Time afternoon(12, 10);

    std::cout
        << minutesBetween(morning, afternoon)
        << ' '
        << earlier(morning, afternoon)
        << '\n';

    return 0;
}
