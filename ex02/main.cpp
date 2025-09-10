/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:43:10 by alexandre         #+#    #+#             */
/*   Updated: 2025/09/10 22:38:28 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int main(void)
{
	Base *objectPoint = generate();
	usleep(500000);
	Base &objectRef = *generate();

	identify(objectPoint);
	identify(*objectPoint);
	identify(objectRef);
	identify(&objectRef);

	delete objectPoint;
	delete &objectRef;
}