#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed");
    if (bureaucrat.getgrade() > getexecuteGrade())
        throw std::runtime_error("Bureaucrat grade too low to execute the form");
    std::cout << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}