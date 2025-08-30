/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:24:48 by alexandre         #+#    #+#             */
/*   Updated: 2025/08/31 00:53:01 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

int	main()
{
	std::string ft = "42";
	int ft_int = std::atoi(ft.c_str());
	double ft_double = static_cast<double>(ft_int);
	float ft_float = static_cast<float>(ft_int);
	float test = 42.1;
	std::cout << "str: " << ft << std::endl;
	std::cout << "int: " << ft_int << std::endl;
	std::cout << "double: " << ft_double << std::endl;
	std::cout << "float: " << ft_float << std::endl;
	std::cout << "test: " << test << (test % 1) ? "f" : ".0f" << std::endl;
}