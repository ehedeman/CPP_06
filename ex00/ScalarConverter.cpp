/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:42 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 16:45:35 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter()
// {
// 	std::cout << "ScalarConverter default Constructor has been called." << std::endl;
// }
// ScalarConverter::ScalarConverter(std::string _s)
// {
// 	std::cout << "ScalarConverter Constructor has been called." << std::endl;
// }
// ScalarConverter::ScalarConverter(const ScalarConverter &copy)
// {
// 	std::cout << "ScalarConverter Copy Constructor has been called." << std::endl;
// 	*this = copy;
		
// }
// ScalarConverter::~ScalarConverter()
// {
// 	std::cout << "ScalarConverter Destructor has been called." << std::endl;
// }
	
// ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &scalar)
// {
// 	if (this == &scalar)
// 		return (*this);
// 	return (*this);
// }

void			ScalarConverter::convert(std::string _s)
{
	s_types numbers;

	if (PseudoLiterals(_s))
		return ;
	FindType(_s, numbers);
}

void			FindType(std::string _s, t_types numbers)
{
}

int				PseudoLiterals(std::string _s)
{
	std::string pseudo[8] = {"inff" ,"-inff", "+inff", "nanf", "-inf", "+inf", "inf", "nan"};
	int			error_case = -1;
	for (int i = 0; i < 8; i++)
	{
		if (_s == pseudo[error_case])
		{
			error_case = i;
			break ;
		}
	}
	if (error_case >= 0 && error_case < 4)
	{
		std::cout			<< 
		"char: impossible"	<< std::endl <<
		"int: impossible"	<< std::endl;	
		switch (error_case)
		{
		case 0:
			std::cout << 
			"float: " + _s	<< std::endl <<
			"double: inf"	<< std::endl;	
			break;
		case 1:
			std::cout << 
			"float: " + _s	<< std::endl <<
			"double: -inf"	<< std::endl;	
			break;
		case 2:
			std::cout << 
			"float: " + _s	<< std::endl <<
			"double: +inf"	<< std::endl;	
			break;
		case 3:
			std::cout << 
			"float: " + _s	<< std::endl <<
			"double: nan"	<< std::endl;	
			break;
		default:
			break;
		}
		return (1);
	}
	else
	{
		std::cout 				<< 
		"char: impossible"		<< std::endl <<
		"int: impossible"		<< std::endl <<
		"float: " + _s + "f" 	<< std::endl <<
		"double: " + _s			<< std::endl;
		return (1);
	}
	return (0);
}