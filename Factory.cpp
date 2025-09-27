#include <iostream>
#include <memory>

// Base class
class Account {
public:
    virtual void accountType() = 0;
    virtual ~Account() {}
};

// Derived classes
class SavingsAccount : public Account {
public:
    void accountType() override {
        std::cout << "Savings Account created.\n";
    }
};

class CurrentAccount : public Account {
public:
    void accountType() override {
        std::cout << "Current Account created.\n";
    }
};

class FixedDepositAccount : public Account {
public:
    void accountType() override {
        std::cout << "Fixed Deposit Account created.\n";
    }
};

// Factory
class AccountFactory {
public:
    static std::unique_ptr<Account> createAccount(const std::string& type) {
        if (type == "savings") return std::make_unique<SavingsAccount>();
        else if (type == "current") return std::make_unique<CurrentAccount>();
        else if (type == "fd") return std::make_unique<FixedDepositAccount>();
        else return nullptr;
    }
};

// Usage
int main() {
    auto account = AccountFactory::createAccount("savings");
    if (account) account->accountType();

    account = AccountFactory::createAccount("fd");
    if (account) account->accountType();

    return 0;
}
