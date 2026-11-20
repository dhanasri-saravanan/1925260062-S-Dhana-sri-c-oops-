#include <iostream>
#include <vector>

// Returns reference to the highest mark
int& highest(int marks[], int n)
{
    int best = 0;

    for (int i = 1; i < n; ++i)
    {
        if (marks[i] > marks[best])
        {
            best = i;
        }
    }

    return marks[best];
}

// Dangerous function
// Do NOT use the returned reference.
int& dangerous()
{
    int local = 42;

    // Warning:
    // reference to local variable is returned
    return local;
}

// Return by value
int highestValue(const int marks[], int n)
{
    int best = marks[0];

    for (int i = 1; i < n; ++i)
    {
        if (marks[i] > best)
        {
            best = marks[i];
        }
    }

    return best;
}

// Return index
int highestIndex(const int marks[], int n)
{
    int best = 0;

    for (int i = 1; i < n; ++i)
    {
        if (marks[i] > marks[best])
        {
            best = i;
        }
    }

    return best;
}

// Return pointer
int* highestPointer(int marks[], int n)
{
    int best = 0;

    for (int i = 1; i < n; ++i)
    {
        if (marks[i] > marks[best])
        {
            best = i;
        }
    }

    return &marks[best];
}

int main()
{
    int marks[] = {72, 91, 84, 88};
    int n = 4;

    std::cout << "Original marks:\n";

    for (int x : marks)
    {
        std::cout << x << ' ';
    }

    std::cout << "\n\n";

    // Return by reference
    highest(marks, n) += 2;

    std::cout << "After moderation:\n";

    for (int x : marks)
    {
        std::cout << x << ' ';
    }

    std::cout << "\n\n";

    // Return by value
    std::cout << "Highest by value: "
              << highestValue(marks, n)
              << '\n';

    // Return index
    int index = highestIndex(marks, n);

    marks[index] += 1;

    std::cout << "After index modification: "
              << marks[index] << '\n';

    // Return pointer
    int* ptr = highestPointer(marks, n);

    *ptr += 1;

    std::cout << "After pointer modification: "
              << *ptr << '\n';

    // Vector demonstration
    std::vector<int> values = {10, 20, 30};

    int& ref = values[2];

    std::cout << "\nReference before vector growth: "
              << ref << '\n';

    // This may cause reallocation.
    values.push_back(40);

    std::cout << "Vector size after growth: "
              << values.size() << '\n';

    // Do NOT use ref here because it may be invalid.

    return 0;
}
