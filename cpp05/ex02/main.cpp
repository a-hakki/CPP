# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main() {

    try {
        std::cout << "---- Test 0: Creating Bureaucrat and Forms ----" << std::endl; 
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Alice");

        std::cout << bob << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        bob.signForm(shrubberyForm);
        bob.signForm(robotomyForm);
        bob.signForm(pardonForm);

        shrubberyForm.execute(bob);
        robotomyForm.execute(bob);
        pardonForm.execute(bob);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n---- Test 1: Creating Bureaucrat with low grade ----" << std::endl; 
        Bureaucrat jim("Jim", 150);
        ShrubberyCreationForm shrubberyForm("Garden");

        std::cout << jim << std::endl;
        std::cout << shrubberyForm << std::endl;

        jim.signForm(shrubberyForm);
        shrubberyForm.execute(jim);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    

    return 0;
}