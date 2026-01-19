# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {

    try {
        std::cout << "---- Test 0: Creating Bureaucrat with invalid grade ----" << std::endl; 
        Bureaucrat john("John", 0);
        Form taxForm("Tax Form", 45, 30);

        john.signForm(taxForm);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n---- Test 1: Creating Form with invalid grade ----" << std::endl; 
        Bureaucrat john("John", 50);
        Form taxForm("Tax Form", 0, 30);

        john.signForm(taxForm);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n---- Test 2: Valid Bureaucrat signing a Form ----" << std::endl;
        Bureaucrat alice("Alice", 40);
        Form contract1("Contract", 50, 20);
        Form contract2("Contract", 30, 20);

        std::cout << alice << std::endl;
        std::cout << contract1 << std::endl;
        std::cout << contract2 << std::endl;

        alice.signForm(contract1);
        alice.signForm(contract2);

        std::cout << contract1 << std::endl;
        std::cout << contract2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}