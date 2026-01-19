# include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        ++b1;
        std::cout << "After promotion: " << b1 << std::endl;

        --b1;
        std::cout << "After demotion: " << b1 << std::endl;

        Bureaucrat b2("Bob", 151);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}