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
#include <whatever.hpp>


void	test() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main()
{
	int a = -15;
	int b = 112;
	std::cout << "Before swap:\na [" << a << "] b [" << b << "]\n";
	::swap(a, b);
	std::cout << "After swap:\na [" << a << "] b [" << b << "]\n";

	std::string mystr = "hello";
	std::string myostr = "world";
	std::cout << "Before swap:\na [" << mystr << "] b [" << myostr << "]\n";
	::swap(mystr, myostr);
	std::cout << "After swap:\na [" << mystr << "] b [" << myostr << "]\n";

	std::cout << "--------------------------\n";
	std::cout << "Min(" << a << ", " << b << ") = " << ::min(a, b) << "\n";
	std::cout << "Max(" << a << ", " << b << ") = " << ::max(a, b) << "\n";
	std::cout << "--------------------------\n";
	std::cout << "PDF tests: " << "\n";

	test();
}
