#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

typedef std::string str;

class Bureaucrat {
    private:
        const str   name;
        int         grade;
    
    public:
        Bureaucrat(const str &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        str getname() const;
        int getgrade() const;
        void setgrade(int grade);
};

#endif //BUREAUCRAT_HPP

