#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

typedef std::string str;


class AForm {
	private:
		const str	name;
		bool		isSigned;
		const int	signGrade;
		const int	executeGrade;
	
	public:
		AForm();
		AForm(const str &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		str		getName()		const;
		bool	getIsSigned()	const;
		int		getsignGrade()		const;
		int		getexecuteGrade()	const;

		void 	setIsSigned(const bool& isSigned);

		void	beSigned(const Bureaucrat &bureaucrat);

		virtual void	execute(const Bureaucrat &bureaucrat) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP