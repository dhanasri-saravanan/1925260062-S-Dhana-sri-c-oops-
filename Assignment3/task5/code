#include <iostream>
#include <stdexcept>
#include <string>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    void normalise()
    {
        int total =
            hours * 3600 +
            minutes * 60 +
            seconds;

        hours = total / 3600;

        total %= 3600;

        minutes = total / 60;
        seconds = total % 60;
    }

public:
    Time(int h = 0, int m = 0, int s = 0)
        : hours(h),
          minutes(m),
          seconds(s)
    {
        normalise();
    }

    // Prefix ++
    Time& operator++()
    {
        ++seconds;

        normalise();

        return *this;
    }

    // Postfix ++
    Time operator++(int)
    {
        Time old = *this;

        ++(*this);

        return old;
    }

    bool operator==(const Time& other) const
    {
        return hours == other.hours &&
               minutes == other.minutes &&
               seconds == other.seconds;
    }

    bool operator<(const Time& other) const
    {
        if (hours != other.hours)
            return hours < other.hours;

        if (minutes != other.minutes)
            return minutes < other.minutes;

        return seconds < other.seconds;
    }

    friend std::ostream& operator<<(
        std::ostream& out,
        const Time& t)
    {
        out << t.hours << ':';

        if (t.minutes < 10)
            out << '0';

        out << t.minutes << ':';

        if (t.seconds < 10)
            out << '0';

        out << t.seconds;

        return out;
    }
};

class Playlist
{
private:
    std::string* tracks;
    int count;

public:
    explicit Playlist(int n)
        : tracks(new std::string[n]),
          count(n)
    {
    }

    ~Playlist()
    {
        delete[] tracks;
    }

    std::string& operator[](int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range(
                "Playlist index out of range");
        }

        return tracks[index];
    }

    const std::string& operator[](int index) const
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range(
                "Playlist index out of range");
        }

        return tracks[index];
    }

    int size() const
    {
        return count;
    }
};

int main()
{
    Time t(0, 59, 59);

    std::cout
        << "Initial time: "
        << t
        << '\n';

    // Postfix
    Time a = t++;

    std::cout
        << "a after t++: "
        << a
        << '\n';

    std::cout
        << "t after t++: "
        << t
        << '\n';

    // Prefix
    Time b = ++t;

    std::cout
        << "b after ++t: "
        << b
        << '\n';

    std::cout
        << "t after ++t: "
        << t
        << '\n';

    // Comparisons
    std::cout
        << std::boolalpha
        << "a == b: "
        << (a == b)
        << '\n';

    std::cout
        << "a < b: "
        << (a < b)
        << '\n';

    // Playlist
    Playlist playlist(3);

    playlist[0] = "Song A";
    playlist[1] = "Song B";
    playlist[2] = "Song C";

    std::cout << "\nPlaylist:\n";

    for (int i = 0; i < playlist.size(); ++i)
    {
        std::cout
            << playlist[i]
            << '\n';
    }

    // Range checking
    try
    {
        std::cout
            << playlist[-1]
            << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout
            << "Error: "
            << e.what()
            << '\n';
    }

    try
    {
        std::cout
            << playlist[playlist.size()]
            << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout
            << "Error: "
            << e.what()
            << '\n';
    }

    return 0;
}
