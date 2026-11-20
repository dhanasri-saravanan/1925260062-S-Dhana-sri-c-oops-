#include <iostream>

class CircularHistory
{
private:
    long long* data;

    int capacity;
    int start;
    int count;

public:
    explicit CircularHistory(int size)
        : data(new long long[size]),
          capacity(size),
          start(0),
          count(0)
    {
    }

    ~CircularHistory()
    {
        delete[] data;
    }

    void add(long long value)
    {
        if (count < capacity)
        {
            int position =
                (start + count) % capacity;

            data[position] = value;

            count++;
        }
        else
        {
            // Replace oldest transaction
            data[start] = value;

            // Move start to next oldest
            start =
                (start + 1) % capacity;
        }
    }

    int size() const
    {
        return count;
    }

    long long get(int index) const
    {
        if (index < 0 || index >= count)
        {
            return 0;
        }

        int position =
            (start + index) % capacity;

        return data[position];
    }

    void display() const
    {
        std::cout
            << "Transactions: ";

        for (int i = 0; i < count; ++i)
        {
            std::cout
                << get(i)
                << ' ';
        }

        std::cout << '\n';
    }
};

int main()
{
    CircularHistory history(5);

    history.add(100);
    history.add(200);
    history.add(300);
    history.add(400);
    history.add(500);

    std::cout << "Initial history:\n";
    history.display();

    // These replace the oldest values
    history.add(600);
    history.add(700);

    std::cout << "\nAfter adding 600 and 700:\n";
    history.display();

    std::cout
        << "\nNumber of transactions: "
        << history.size()
        << '\n';

    return 0;
}
