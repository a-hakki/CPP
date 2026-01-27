#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const str &name, int grade)
: name(name)
{
    setgrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: name(other.name), grade(other.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat &Bureaucrat::operator++()
{
    setgrade(grade - 1);
    return *this;
}   

Bureaucrat &Bureaucrat::operator--()
{
    setgrade(grade + 1);
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

str Bureaucrat::getname() const
{
    return name;
}

int Bureaucrat::getgrade() const
{
    return grade;
}

void Bureaucrat::setgrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getname() << ", bureaucrat grade " << b.getgrade() << ".";
    return os;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}