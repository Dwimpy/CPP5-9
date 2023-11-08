#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default_form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::~Form() {}

Form::Form(const Form &copy): _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
	checkArguments();
}

Form::Form(const std::string &name, ssize_t sign_grade, ssize_t exec_grade):
_name(name), _isSigned(false), _signGrade(sign_grade), _executeGrade(exec_grade) {
	checkArguments();
}

Form::Form(const std::string &name): _name(name), _signGrade(150), _executeGrade(150) {
	checkArguments();
}


Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

const std::string &Form::getName()
{
	return this->_name;
}

const ssize_t &Form::getSignGrade()
{
	return this->_signGrade;
}

const ssize_t &Form::getExecuteGrade()
{
	return this->_executeGrade;
}

void Form::beSigned(Bureaucrat &b)
{
	checkCanSign(b);
	std::cout << b.getName() << " signed form " << _name << std::endl;
	this->_isSigned = true;
}

bool Form::isSigned() const
{
	return (this->_isSigned);
}

const std::string &Form::getName() const
{
	return (this->_name);
}

const ssize_t &Form::getSignGrade() const
{
	return (this->_signGrade);
}

const std::string &Form::getTarget() const {
	return (this->_target);
}

const ssize_t &Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void Form::checkArguments()
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
}

void Form::checkCanSign(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
}

void Form::setTarget(const std::string target)
{
	this->_target = target;
}

void	Form::checkExecuteAllowed(const Bureaucrat &b) const
{
	if (b.getGrade() > _executeGrade)
		throw Form::GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException(): _message("Form -> Grade too high") {}

const char *Form::GradeTooHighException::what() const throw()
{
	return _message.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}


Form::GradeTooLowException::GradeTooLowException(): _message("Form -> Grade too low") {}

const char *Form::GradeTooLowException::what() const throw()
{
	return _message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "Name: " << obj.getName() << "\n"
	   << "Sign Grade: " << obj.getSignGrade() << "\n"
	   << "Execute Grade: " << obj.getExecuteGrade() << "\n"
	   << "Signed:: " << obj.getSignGrade() << "\n";
	return (os);
}