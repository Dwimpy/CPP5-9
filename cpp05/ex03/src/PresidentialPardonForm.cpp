#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("PresidentialPardonForm", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form(copy) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

