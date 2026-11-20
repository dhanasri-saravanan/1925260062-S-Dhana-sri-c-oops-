#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex()
        : real(0.0),
          imag(0.0)
    {
    }

    // Constructor from real part
    Complex(double r)
        : real(r),
          imag(0.0)
    {
    }

    // Constructor from real and imaginary parts
    Complex(double r, double i)
        : real(r),
          imag(i)
    {
    }

    double magnitude() const
    {
        return std::sqrt(
            real * real +
            imag * imag
        );
    }

    // Addition
    Complex operator+(const Complex& other) const
    {
        return Complex(
            real + other.real,
            imag + other.imag
        );
    }

    // Subtraction
    Complex operator-(const Complex& other) const
    {
        return Complex(
            real - other.real,
            imag - other.imag
        );
    }

    // Multiplication
    Complex operator*(const Complex& other) const
    {
        return Complex(
            real * other.real -
                imag * other.imag,

            real * other.imag +
                imag * other.real
        );
    }

    // Division
    Complex operator/(const Complex& other) const
    {
        double denominator =
            other.real * other.real +
            other.imag * other.imag;

        if (std::abs(denominator) < 1e-12)
        {
            throw std::runtime_error(
                "Division by zero complex number"
            );
        }

        return Complex(
            (real * other.real +
             imag * other.imag) /
                denominator,

            (imag * other.real -
             real * other.imag) /
                denominator
        );
    }

    // Equality
    bool operator==(const Complex& other) const
    {
        constexpr double EPS = 1e-9;

        return std::abs(real - other.real) < EPS &&
               std::abs(imag - other.imag) < EPS;
    }

    // Output
    friend std::ostream& operator<<(
        std::ostream& out,
        const Complex& z)
    {
        out << std::fixed
            << std::setprecision(4);

        out << z.real;

        if (z.imag >= 0)
        {
            out << " + "
                << z.imag
                << "j";
        }
        else
        {
            out << " - "
                << std::abs(z.imag)
                << "j";
        }

        return out;
    }
};

// Inductor impedance: jωL
Complex inductorImpedance(
    double frequency,
    double inductance)
{
    constexpr double PI =
        3.14159265358979323846;

    double omega =
        2.0 * PI * frequency;

    return Complex(
        0.0,
        omega * inductance
    );
}

// Capacitor impedance: -j/(ωC)
Complex capacitorImpedance(
    double frequency,
    double capacitance)
{
    constexpr double PI =
        3.14159265358979323846;

    double omega =
        2.0 * PI * frequency;

    return Complex(
        0.0,
        -1.0 /
            (omega * capacitance)
    );
}

// Parallel impedance
Complex parallel(
    const Complex& z1,
    const Complex& z2)
{
    return (z1 * z2) /
           (z1 + z2);
}

int main()
{
    constexpr double frequency = 50.0;

    // Components
    Complex resistor(100.0);

    Complex inductor =
        inductorImpedance(
            frequency,
            0.1
        );

    Complex capacitor =
        capacitorImpedance(
            frequency,
            100e-6
        );

    std::cout
        << "Resistor:   "
        << resistor
        << '\n';

    std::cout
        << "Inductor:   "
        << inductor
        << '\n';

    std::cout
        << "Capacitor:  "
        << capacitor
        << '\n';

    // Series RLC
    Complex series =
        resistor +
        inductor +
        capacitor;

    std::cout
        << "\nSeries RLC impedance:\n";

    std::cout
        << series
        << '\n';

    std::cout
        << "Magnitude: "
        << series.magnitude()
        << '\n';

    // Parallel RLC
    try
    {
        Complex parallelRLC =
            parallel(
                resistor,
                inductor
            );

        parallelRLC =
            parallel(
                parallelRLC,
                capacitor
            );

        std::cout
            << "\nParallel RLC impedance:\n";

        std::cout
            << parallelRLC
            << '\n';

        std::cout
            << "Magnitude: "
            << parallelRLC.magnitude()
            << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout
            << "Error: "
            << e.what()
            << '\n';
    }

    // Basic operator tests
    Complex x(3, 4);
    Complex y(1, 2);

    std::cout
        << "\nOperator tests:\n";

    std::cout
        << "x + y = "
        << x + y
        << '\n';

    std::cout
        << "x - y = "
        << x - y
        << '\n';

    std::cout
        << "x * y = "
        << x * y
        << '\n';

    std::cout
        << "x / y = "
        << x / y
        << '\n';

    std::cout
        << "x == y: "
        << std::boolalpha
        << (x == y)
        << '\n';

    // Division by zero test
    try
    {
        Complex zero(0, 0);

        Complex result =
            x / zero;

        std::cout
            << result
            << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout
            << "Division test: "
            << e.what()
            << '\n';
    }

    return 0;
}
