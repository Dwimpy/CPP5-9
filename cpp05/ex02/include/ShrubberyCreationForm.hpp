#pragma once
#include "Form.hpp"

class ShrubberyCreationForm: public Form {

  public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	void			execute(Bureaucrat const & executor) const;

};