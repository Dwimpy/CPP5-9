#include <string>
#include <exception>
#include <cstddef>
#include <cstdio>
#include <iostream>


class Bureaucrat;

class Form {

  public:
		Form();
		Form(const std::string &name);
		Form(const std::string &name, ssize_t sign_grade, ssize_t exec_grade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		const std::string		&getName();
		const std::string		&getName() const;
		bool					isSigned() const;
		const ssize_t			&getSignGrade();
		const ssize_t			&getSignGrade() const;
		const ssize_t			&getExecuteGrade();
		const ssize_t			&getExecuteGrade() const;
		void					beSigned(Bureaucrat &b);

  private:
	const std::string	_name;
	bool				_isSigned;
	const ssize_t		_signGrade;
	const ssize_t		_executeGrade;
	void				checkArguments();
	void 				checkCanSign(const Bureaucrat &b);


class GradeTooHighException: public std::exception {

  public:
	GradeTooHighException();
	~GradeTooHighException() throw();
	virtual const char *what() const throw();

  private:
	std::string	_message;
	};

class GradeTooLowException: public std::exception {

  public:
	GradeTooLowException();
	~GradeTooLowException() throw();
	virtual const char *what() const throw();

  private:
	std::string	_message;
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
