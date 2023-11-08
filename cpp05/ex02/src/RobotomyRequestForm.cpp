#include <ctime>
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("RobotomyRequestForm", 72, 45) {
	setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form(copy) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Generate a random number between 0 and 1
    double random_number = static_cast<double>(std::rand()) / RAND_MAX;
	if (random_number <= 0.5)
		std::cout << getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Failed to robotomize " << getTarget() << std::endl;
}

