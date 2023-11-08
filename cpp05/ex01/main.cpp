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
#include "Form.hpp"

int main()
{
	Bureaucrat b("John", 150);
	Bureaucrat c("Walnut", 1);
	try {
		Bureaucrat("Higher", 0);
	} catch (std::exception &e) {
		std::cerr << "   Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat("Lower", 151);
	} catch (std::exception &e) {
		std::cerr << "   Exception caught: " << e.what() << std::endl;
	}

	try {
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << "   Exception caught: " << e.what() << std::endl;
	}

	b.incrementGrade();
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	try {
		c.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << "   Exception caught: " << e.what() << std::endl;
	}
	Form theform("hello", 1, 15);

	try {
		b.signForm(theform);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b.signForm(theform);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form form("Hello", 0, 145);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
