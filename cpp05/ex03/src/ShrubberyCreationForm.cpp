#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("ShrubberyCreationForm", 145, 137) {
	setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form(copy) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		Form::operator=(copy);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
	std::string name = getTarget() + "_shruberry";
	std::ofstream output(name.c_str());
	if (output.good())
		output << "                                               |\n"
				  "                                              -x-\n"
				  "                                               |\n"
				  "              v .   ._, |_  .,\n"
				  "           `-._\\/  .  \\ /    |/_\n"
				  "               \\\\  _\\, y | \\//\n"
				  "         _\\_.___\\\\, \\\\/ -.\\||\n"
				  "           `7-,--.`._||  / / ,\n"
				  "           /'     `-. `./ / |/_.'\n"
				  "                     |    |//\n"
				  "                     |_    /\n"
				  "                     |-   |\n"
				  "                     |   =|\n"
				  "                     |    |\n"
				  "--------------------/ ,  . \\--------._";
	else
		return ;
	output.close();
}

