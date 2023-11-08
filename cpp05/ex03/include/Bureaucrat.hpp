#pragma once
#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
class Form;

class Bureaucrat {

  public:
	Bureaucrat();
	Bureaucrat(ssize_t grade);
	Bureaucrat(const std::string &name, ssize_t grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();
	const std::string	&getName();
	const std::string	&getName() const;
	ssize_t				&getGrade();
	const ssize_t		&getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &form);
	void				signForm(Form &form) const;
	void				executeForm(Form &form);
	void				executeForm(Form &form) const;

  private:
	const std::string	_name;
	ssize_t 			_grade;


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



std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);