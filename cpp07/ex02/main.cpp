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
#include <Array.hpp>

int main()
{
    Array<int> a(3);
    Array<char> a2(10);
    Array<char> a3(a2);
	std::cout << "a2 size: " << a2.size() << std::endl;
	std::cout << "a3 size: " << a3.size() << std::endl;
	a2[6] = 'a';
	a3[6] = 'b';
	std::cout << a2[6] << std::endl;
    std::cout << a3[6] << std::endl;

    try {
        std::cout << a[3]<< std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	}

    try{
        std::cout << a2.size() << std::endl;
        a3 = a2;
        a2[1] = 'A';
        a3[1] = 'B';
        std::cout << a2[1] << std::endl;
        std::cout << a3[1] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	}
    return (0);
}
