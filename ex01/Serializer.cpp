/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:03 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 16:03:53 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*--------------------------------Constructors------------------------------------*/
Serializer::Serializer()
{
	std::cout	<< "Serializer default Constructor called."		<< std::endl;
}
Serializer::Serializer(const Serializer &copy)
{
	std::cout	<< "Serializer Copy Constructor has been called."	<< std::endl;
	*this = copy;
		
}

/*--------------------------------Deconstructor-----------------------------------*/
Serializer::~Serializer()
{
	std::cout	<< "Serializer Destructor has been called."		<< std::endl;
}
/*--------------------------------Assignment-Operator-----------------------------*/
Serializer	&Serializer::operator=(const Serializer &scalar)
{
	if (this == &scalar)
		return (*this);
	return (*this);
}


uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t u_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (u_ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}