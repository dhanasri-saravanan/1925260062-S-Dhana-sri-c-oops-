#include <iostream>
#include <string>

class Auditorium
{
private:
    int rows;
    int seatsPerRow;
    char** seatMap;

    int booked;

public:
    Auditorium(int r, int s)
        : rows(r),
          seatsPerRow(s),
          seatMap(nullptr),
          booked(0)
    {
        std::cout
            << "Constructor: "
            << rows << " x "
            << seatsPerRow
            << '\n';

        if (rows <= 0 || seatsPerRow <= 0)
        {
            rows = 0;
            seatsPerRow = 0;
            return;
        }

        seatMap = new char*[rows];

        for (int i = 0; i < rows; ++i)
        {
            seatMap[i] = new char[seatsPerRow];

            for (int j = 0; j < seatsPerRow; ++j)
            {
                seatMap[i][j] = 'O';
            }
        }
    }

    ~Auditorium()
    {
        if (seatMap != nullptr)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] seatMap[i];
            }

            delete[] seatMap;
        }

        std::cout
            << "Destructor: "
            << booked
            << " seat(s) booked\n";
    }

    bool book(int row, int seat)
    {
        if (!valid(row, seat))
        {
            return false;
        }

        if (seatMap[row][seat] == 'X')
        {
            return false;
        }

        seatMap[row][seat] = 'X';
        ++booked;

        return true;
    }

    bool cancel(int row, int seat)
    {
        if (!valid(row, seat))
        {
            return false;
        }

        if (seatMap[row][seat] == 'O')
        {
            return false;
        }

        seatMap[row][seat] = 'O';
        --booked;

        return true;
    }

    void display() const
    {
        std::cout << "\nSeat Map:\n";

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < seatsPerRow; ++j)
            {
                std::cout << seatMap[i][j] << ' ';
            }

            std::cout << '\n';
        }
    }

private:
    bool valid(int row, int seat) const
    {
        return row >= 0 &&
               row < rows &&
               seat >= 0 &&
               seat < seatsPerRow;
    }
};

int main()
{
    std::cout << "Stack object:\n";

    {
        Auditorium event1(3, 4);

        event1.book(0, 0);
        event1.book(1, 2);
        event1.book(2, 3);

        event1.display();

        event1.cancel(1, 2);

        std::cout << "\nAfter cancellation:\n";
        event1.display();
    }

    std::cout << "\nHeap object:\n";

    Auditorium* event2 =
        new Auditorium(2, 5);

    event2->book(0, 1);
    event2->book(1, 4);

    event2->display();

    delete event2;

    std::cout << "\nZero-row event:\n";

    Auditorium emptyEvent(0, 10);

    return 0;
}
