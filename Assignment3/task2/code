#include <iostream>
#include <string>

class Prescription
{
private:
    int n;
    std::string* medicines;

public:
    // Constructor
    explicit Prescription(int count)
        : n(count),
          medicines(new std::string[count])
    {
    }

    // Deep-copy constructor
    Prescription(const Prescription& other)
        : n(other.n),
          medicines(new std::string[other.n])
    {
        std::cout << "Copy constructor called\n";

        for (int i = 0; i < n; ++i)
        {
            medicines[i] = other.medicines[i];
        }
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other)
    {
        std::cout << "Copy assignment called\n";

        if (this == &other)
        {
            return *this;
        }

        std::string* newMedicines =
            new std::string[other.n];

        for (int i = 0; i < other.n; ++i)
        {
            newMedicines[i] = other.medicines[i];
        }

        delete[] medicines;

        medicines = newMedicines;
        n = other.n;

        return *this;
    }

    // Destructor
    ~Prescription()
    {
        delete[] medicines;
    }

    void set(int i, const std::string& medicine)
    {
        if (i >= 0 && i < n)
        {
            medicines[i] = medicine;
        }
    }

    std::string get(int i) const
    {
        if (i >= 0 && i < n)
        {
            return medicines[i];
        }

        return "";
    }

    int size() const
    {
        return n;
    }
};

int main()
{
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    // Copy constructor
    Prescription q = p;

    q.set(1, "Cetirizine");

    // Copy assignment
    Prescription r(1);

    r = p;

    p.set(0, "Ibuprofen");

    std::cout
        << p.get(0) << ' '
        << p.get(1)
        << " | "
        << q.get(0) << ' '
        << q.get(1)
        << " | "
        << r.get(0) << ' '
        << r.get(1)
        << '\n';

    // Self-assignment test
    p = p;

    std::cout
        << "After self-assignment: "
        << p.get(0) << ' '
        << p.get(1)
        << '\n';

    return 0;
}
