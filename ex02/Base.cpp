/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:52 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/22 11:59:14 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base	*generate(void)
{
	int i = rand();

	switch (i % 3)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	default:
		break;
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Identiffy Pointer: The object is of type A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Identiffy Pointer: The object is of type B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Identiffy Pointer: The object is of type C" << std::endl;
	else
		std::cout << "Identiffy Pointer: The object is neither A, B nor C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Identiffy Reference: The object is of type A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Identiffy Reference: The object is of type B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Identiffy Reference: The object is of type C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Identiffy Reference: Neither A, B nor C" << std::endl;
}