#pragma once
#include "Form.hpp"

class RobotomyRequestForm: public Form {

  public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	void			execute(Bureaucrat const & executor) const;

};