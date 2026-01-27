#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (bureaucrat.getgrade() > getexecuteGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
        return;
    }

    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
}