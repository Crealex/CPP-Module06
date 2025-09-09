/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:24:48 by alexandre         #+#    #+#             */
/*   Updated: 2025/09/08 17:57:50 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
//	std::cout << argc << std::endl;
	//std::cout << argv[1] << std::endl;
	if (argc != 2)
	{
		std::cerr << "Not the right number of arguments" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	// std::string ft = "42";
	// int ft_int = std::atoi(ft.c_str());
	// double ft_double = static_cast<double>(ft_int);
	// float ft_float = static_cast<float>(ft_int);
	// float test = 4.2;
	// std::string unit = test - static_cast<int>(test) ? "f" : ".0f";
	// std::cout << "str: " << ft << std::endl;
	// std::cout << "int: " << ft_int << std::endl;
	// std::cout << "double: " << ft_double << std::endl;
	// std::cout << "float: " << ft_float << std::endl;
	// std::cout << "test: " << test << unit << std::endl;
}