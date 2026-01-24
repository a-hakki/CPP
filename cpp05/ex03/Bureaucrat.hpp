#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

typedef std::string str;

class Bureaucrat {
    private:
        const str   name;
        int         grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const str &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        Bureaucrat &operator++();
        Bureaucrat &operator--();
        ~Bureaucrat();
        str getname() const;
        int getgrade() const;
        void setgrade(int grade);

        void signForm(AForm& form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif //BUREAUCRAT_HPP

