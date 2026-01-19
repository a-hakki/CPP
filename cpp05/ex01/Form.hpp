#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

typedef std::string str;


class Form {
	private:
		const str	name;
		bool		isSigned;
		const int	signGrade;
		const int	executeGrade;
	
	public:
		Form();
		Form(const str &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		str		getName()		const;
		bool	getIsSigned()	const;
		int		getsignGrade()		const;
		int		getexecuteGrade()	const;

		void 	setIsSigned(const bool& isSigned);

		void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // FORM_HPP