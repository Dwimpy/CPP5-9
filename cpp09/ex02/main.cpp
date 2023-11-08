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
#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	PMergeMe(std::string(argv[1]));
	return (0);
}
