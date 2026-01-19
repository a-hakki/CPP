#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    :name("default"),  isSigned(false), signGrade(150), executeGrade(150)
{
}

Form::Form(const str &name, int signGrade, int executeGrade)
    :name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw std::out_of_range("Form::GradeTooHighException");
    if (signGrade > 150 || executeGrade > 150)
        throw std::out_of_range("Form::GradeTooLowException");
}

Form::Form(const Form &other)
    :name(other.name),  isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

str Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getsignGrade() const
{
    return this->signGrade;
}

int Form::getexecuteGrade() const
{
    return this->executeGrade;
}

void Form::setIsSigned(const bool& isSigned)
{
    this->isSigned = isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getgrade() <= this->getsignGrade())
        this->isSigned = true;
    else
        throw std::out_of_range("Form::GradeTooLowException");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form Name: " << form.getName() << ", Sign Grade: " << form.getsignGrade()
        << ", Execute Grade: " << form.getexecuteGrade() << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}
