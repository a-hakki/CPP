#ifndef BASE_HPP
# define BASE_HPP

# include <exception>

class A;
class B;
class C;

class Base {
    public:
        Base();
        virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif // BASE_HPP