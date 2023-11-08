#pragma once
#include "Form.hpp"

class PresidentialPardonForm: public Form {

  public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	void			execute(Bureaucrat const & executor) const;

};