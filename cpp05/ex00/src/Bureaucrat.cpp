#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, ssize_t grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(ssize_t grade): _name("John"), _grade(grade)
{

}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName()
{
	return this->_name;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

ssize_t &Bureaucrat::getGrade()
{
	return this->_grade;
}

const ssize_t &Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing grade for " << getName() << " from " << this->_grade;
	this->_grade--;
	std::cout << " to " << this->_grade << std::endl;
	if (_grade < 1)
	{
		this->_grade = 1;
		throw GradeTooLowException();
	}
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing grade for " << getName() << " from " << this->_grade;
	this->_grade++;
	std::cout << " to " << this->_grade << std::endl;
	if (_grade > 150)
	{
		this->_grade = 150;
		throw GradeTooHighException();
	}
}
Bureaucrat::Bureaucrat(): _name("Default name: "), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}


GradeTooHighException::GradeTooHighException(): _message("Grade too high") {}

const char *GradeTooHighException::what() const throw()
{
	return _message.c_str();
}

GradeTooHighException::~GradeTooHighException() throw() {}


GradeTooLowException::GradeTooLowException(): _message("Grade too low") {}

const char *GradeTooLowException::what() const throw()
{
	return _message.c_str();
}

GradeTooLowException::~GradeTooLowException() throw() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}