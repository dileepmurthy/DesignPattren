
#include <iostream>
using namespace std;

class Singleton {
private:
    // Private constructor to prevent multiple objects
    Singleton() {
        cout << "Singleton Instance Created\n";
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static pointer to hold single instance
    static Singleton* instance;

public:
    // Public method to get instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();  // Lazy initialization
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton\n";
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    // Access Singleton instance
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    // Try creating another instance
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2)
        cout << "Both pointers point to the same instance\n";

    return 0;
}
