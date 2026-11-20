#include <iostream>

class SavingsAccount
{
private:
    int accountNumber;
    long long balance;

    long long transactions[10];
    int count;

    void addTransaction(long long amount)
    {
        // Space available
        if (count < 10)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            // Shift older transactions
            for (int i = 1; i < 10; ++i)
            {
                transactions[i - 1] = transactions[i];
            }

            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int accNo, long long openingBalance = 0)
        : accountNumber(accNo),
          balance(openingBalance),
          count(0)
    {
    }

    void deposit(long long amount)
    {
        if (amount <= 0)
        {
            std::cout << "Invalid deposit\n";
            return;
        }

        balance += amount;

        addTransaction(amount);
    }

    bool withdraw(long long amount)
    {
        if (amount <= 0 || amount > balance)
        {
            std::cout << "Invalid withdrawal\n";
            return false;
        }

        balance -= amount;

        addTransaction(-amount);

        return true;
    }

    void miniStatement() const;
};

// Member function defined outside class
void SavingsAccount::miniStatement() const
{
    std::cout << "\n----------------------\n";
    std::cout << "Account Number: "
              << accountNumber << '\n';

    std::cout << "Balance: "
              << balance << '\n';

    std::cout << "Transactions:\n";

    for (int i = 0; i < count; ++i)
    {
        std::cout << transactions[i] << ' ';
    }

    std::cout << "\n----------------------\n";
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    // Generate more transactions
    for (int i = 1; i <= 10; ++i)
    {
        account.deposit(i * 100);
    }

    std::cout << "\nAfter more transactions:\n";

    account.miniStatement();

    return 0;
}
