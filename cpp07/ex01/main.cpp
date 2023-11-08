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


int main()
{
	std::string	strArray[] = {"hello", "world", "\n", "How are you?"};
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	iter(strArray, 4, display<std::string>);
	std::cout << std::endl;

    iter(intArray, 5, display<int>);
    std::cout << std::endl;

    iter(doubleArray, 5, display<double>);
    std::cout << std::endl;

    iter(charArray, 5, display<char>);
    std::cout << std::endl;

}
