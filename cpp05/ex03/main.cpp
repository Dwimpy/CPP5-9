/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:57:53 by arobu             #+#    #+#             */
/*   Updated: 2023/07/03 18:48:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void leaks()
{
	system("leaks Bureaucrat");
}

int main()
{
	Bureaucrat b("John", 26);
	Intern		i;
	Form *test = i.makeForm("ShrubberyCreationForm", "hello");
	atexit(leaks);
	try {
		b.signForm(*i.makeForm("PresidentialPardonForm", "hello"));
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		b.signForm(*i.makeForm("RobotomyRequestForm", "hello"));
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		b.signForm(*i.makeForm("ShrubberyCreationForm", "hello"));
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	b.signForm(*test);
	b.signForm(*test);


	try {
		b.signForm(*i.makeForm("asd", "hello"));
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
