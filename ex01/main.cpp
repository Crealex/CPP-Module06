/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:24:48 by alexandre         #+#    #+#             */
/*   Updated: 2025/09/10 14:42:57 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"
#include <cstdlib>

int	main(void)
{
	uintptr_t raw;
	Data data;
	Data *newData = NULL;

	data.value = 42;
	std::cout << "Data adress:" << &data << std::endl;
	std::cout << "value in Data before: " << data.value << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Serialize: " << raw << std::endl;
	newData = Serializer::deserialize(raw);
	std::cout << "Deserialize: " << newData << std::endl;
	std::cout << "value in data after: " << newData->value << std::endl;
}