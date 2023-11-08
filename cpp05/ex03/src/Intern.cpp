#include "Intern.hpp"


Intern::Intern() {};

Intern::~Intern() {
	for (size_t i = 0; i < _createdForms.size(); ++i)
		delete _createdForms[i];
};

Intern::Intern(const Intern &copy)  {
	if (this != &copy)
		*this = copy;
}
Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

Form *Intern::makeForm(const std::string &form, const std::string &target)
{
	if (form == "ShrubberyCreationForm")
	{
		_createdForms.push_back(new ShrubberyCreationForm(target));
		return (_createdForms.back());
	}
	else if (form == "RobotomyRequestForm")
	{
		_createdForms.push_back(new RobotomyRequestForm(target));
		return (_createdForms.back());
	}
	else if (form == "PresidentialPardonForm")
	{
		_createdForms.push_back(new PresidentialPardonForm(target));
		return (_createdForms.back());
	}
	else
		std::cerr << "Invalid form" << std::endl;
	return (NULL);
};
