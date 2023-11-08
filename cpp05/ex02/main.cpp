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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b("John", 125);
	ShrubberyCreationForm sf("Home");
	RobotomyRequestForm rf("China");
	PresidentialPardonForm pf("China");

	try {
		b.signForm(pf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {
		b.signForm(rf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {
		b.signForm(sf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		b.executeForm(rf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {
		b.executeForm(sf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try {
		b.executeForm(pf);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

}
