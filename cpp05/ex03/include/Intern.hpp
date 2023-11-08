#include <string>
#include <vector>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern {
  public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	Form	*makeForm(const std::string &form, const std::string &target);

  private:
	std::vector <Form *> _createdForms;
};