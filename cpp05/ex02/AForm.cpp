#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    :name("default"),  isSigned(false), signGrade(150), executeGrade(150)
{
}

AForm::AForm(const str &name, int signGrade, int executeGrade)
    :name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    :name(other.name),  isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

str AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getsignGrade() const
{
    return this->signGrade;
}

int AForm::getexecuteGrade() const
{
    return this->executeGrade;
}

void AForm::setIsSigned(const bool& isSigned)
{
    this->isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getgrade() <= this->getsignGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form Name: " << form.getName() << ", Sign Grade: " << form.getsignGrade()
        << ", Execute Grade: " << form.getexecuteGrade() << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm Exception: Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm Exception: Grade Too Low";
}