#include <cstring>
#include <iostream>

class Text
{
private:
    char* data;

public:
    // Constructor
    Text(const char* str = "")
    {
        if (str == nullptr)
        {
            str = "";
        }

        data = new char[
            std::strlen(str) + 1
        ];

        std::strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other)
    {
        data = new char[
            std::strlen(other.data) + 1
        ];

        std::strcpy(data, other.data);

        std::cout
            << "[copy] ";
    }

    // Copy assignment
    Text& operator=(const Text& other)
    {
        if (this == &other)
        {
            return *this;
        }

        char* newData =
            new char[
                std::strlen(other.data) + 1
            ];

        std::strcpy(newData, other.data);

        delete[] data;

        data = newData;

        return *this;
    }

    // Destructor
    ~Text()
    {
        delete[] data;
    }

    // Concatenation
    Text operator+(const Text& other) const
    {
        std::size_t length =
            std::strlen(data) +
            std::strlen(other.data);

        char* buffer =
            new char[length + 1];

        std::strcpy(buffer, data);
        std::strcat(buffer, other.data);

        Text result(buffer);

        delete[] buffer;

        return result;
    }

    // Equality
    bool operator==(const Text& other) const
    {
        return std::strcmp(
            data,
            other.data
        ) == 0;
    }

    // Inequality
    bool operator!=(const Text& other) const
    {
        return !(*this == other);
    }

    // Output
    friend std::ostream& operator<<(
        std::ostream& out,
        const Text& text)
    {
        out << text.data;

        return out;
    }
};

int main()
{
    Text a("Hello");
    Text b(" ");
    Text c("World");

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';

    Text message = a + b + c;

    std::cout
        << "Message: "
        << message
        << '\n';

    std::cout
        << std::boolalpha
        << "a == b: "
        << (a == b)
        << '\n';

    std::cout
        << "a != b: "
        << (a != b)
        << '\n';

    // Self-assignment
    message = message;

    std::cout
        << "After self-assignment: "
        << message
        << '\n';

    // Empty string
    Text empty;

    std::cout
        << "Empty: ["
        << empty
        << "]\n";

    return 0;
}
