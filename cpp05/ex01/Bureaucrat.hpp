#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

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

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
    
        str getname() const;
        int getgrade() const;
        void setgrade(int grade);

        void signForm(Form& form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif //BUREAUCRAT_HPP

