#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    int copies;

public:
    // Default constructor
    Book()
        : Book("", "", 0)
    {
    }

    // Title-only constructor
    explicit Book(const std::string& t)
        : Book(t, "Unknown", 0)
    {
    }

    // Title + copies constructor
    Book(const std::string& t, int c)
        : Book(t, "Unknown", c)
    {
    }

    // Full parameterised constructor
    Book(const std::string& t,
         const std::string& a,
         int c)
        : title(t),
          author(a),
          copies(c >= 0 ? c : 0)
    {
    }

    void print() const
    {
        std::cout
            << "Title: " << title
            << ", Author: " << author
            << ", Copies: " << copies
            << '\n';
    }

    void setCopies(int c)
    {
        if (c >= 0)
            copies = c;
        else
            std::cout << "Invalid number of copies\n";
    }
};

int main()
{
    Book empty;

    Book donated("C++ Programming");

    Book limited("Data Structures", 5);

    Book full(
        "Object Oriented Programming",
        "Bjarne Stroustrup",
        10
    );

    std::cout << "Default book:\n";
    empty.print();

    std::cout << "\nDonated book:\n";
    donated.print();

    std::cout << "\nLimited book:\n";
    limited.print();

    std::cout << "\nFull book:\n";
    full.print();

    std::cout << "\nTesting invalid copies:\n";

    Book invalid("Invalid Book", "Unknown", -5);
    invalid.print();

    invalid.setCopies(-10);

    return 0;
}
