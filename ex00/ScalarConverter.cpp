/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:42 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/20 16:34:43 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstring>
int				PseudoLiterals(std::string str);
int				isNum(std::string str, t_types *t);
void			convertTypes(t_types *t);

ScalarConverter::ScalarConverter()
{
	std::cout	<< "ScalarConverter default Constructor has been called." << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout	<< "ScalarConverter Copy Constructor has been called." << std::endl;
	*this = copy;
		
}
ScalarConverter::~ScalarConverter()
{
	std::cout	<< "ScalarConverter Destructor has been called." << std::endl;
}
	
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &scalar)
{
	if (this == &scalar)
		return (*this);
	return (*this);
}

void			ScalarConverter::printFloat(const float f, const int digits)
{
	if (digits > 9)
	{
		std::cout		<<	"float: "		<<	f	<<	"f"				<< std::endl;
	}
	else
	{
		std::cout		<<	std::setprecision(digits)	<<	"float: "		<<
		f				<<	(floor(f) == f ? ".0f" : "f")				<< std::endl;
	}
}

void			ScalarConverter::printInt(const int i)
{
	std::cout		<<	"int: "					<<	i	<< std::endl;
}

void			ScalarConverter::printChar(const char c)
{
	if (!c)
		std::cout	<<	"char: "				<<	c	<< std::endl;
	else
		std::cout	<< "char: Non displayable"	<< std::endl;
}

void			ScalarConverter::printDouble(const double d, const int digits)
{
	if (digits > 9)
	{
		std::cout		<<	"double: "		<<	d	<< std::endl;
	}
	else
	{
		std::cout		<<	std::setprecision(digits)	<<	"double: "	<<
		d				<<	(floor(d) == d ? ".0" : "")				<< std::endl;
	}
}

void			ScalarConverter::convert(std::string str)
{
	t_types 	t;
	std::string copy;
	int			digits = 0;

	t.str = str;
	if (PseudoLiterals(str))
		return ;
	if (str[0] == '-')
		copy = &str[1];
	else
		copy = str;
	if (!isNum(copy, &t))
	{
		std::cout	<< "Error: Wrong Format." << std::endl;
		return ;
	}
	setDigits(&t, &digits);
	convertTypes(&t);
	if (t.i <= DISPLAYABLE_MAX && t.i >= DISPLAYABLE_MIN)
		printChar(0);
	else
		printChar(t.i);
	printInt(t.i);
	printFloat(t.f, digits);
	printDouble(t.d, digits);
}

void			ScalarConverter::convertTypes(t_types *t)
{
	char	**ptr = new char *;
	t->f = std::strtof(t->str.c_str(), ptr);
	if (**ptr && (strlen(*ptr) != 1))
		std::cout	<< "error" 					<< std::endl;
	t->d = std::strtod(t->str.c_str(), ptr);
	if (**ptr && (strlen(*ptr) != 1))
		std::cout	<< "error" 					<< std::endl;
	t->i = (int) t->d;
	delete(ptr);
}

void			ScalarConverter::setDigits(t_types *t, int *digits)
{
	int 	i = 0;
	int		count = 0;

	if (t->str[i] == '-')
		i++;
	while (t->str[i])
	{
		if (t->str[i] == '.')
			i++;
		if (t->str[i] == 'f')
			break ;
		count++;
		i++;
	}
	*digits = count;
}

int				ScalarConverter::PseudoLiterals(std::string str)
{
	std::string pseudo[8] = {"inff" ,"-inff", "+inff", "nanf", "inf", "-inf", "+inf", "nan"};
	int			error_case = -1;
	for (int i = 0; i < 8; i++)
	{
		if (str == pseudo[i])
		{
			error_case = i;
			break ;
		}
	}
	if (error_case >= 0 && error_case < 4)
	{
		std::cout		<< 
		"char: impossible"							<< std::endl <<
		"int: impossible"							<< std::endl;	
		switch (error_case)
		{
		case 0:
			std::cout	<< 
			"float: "	+ str						<< std::endl <<
			"double: "	+ pseudo[error_case + 4]	<< std::endl;	
			break;
		case 1:
			std::cout	<< 
			"float: "	+ str						<< std::endl <<
			"double: "	+ pseudo[error_case + 4]	<< std::endl;	
			break;
		case 2:
			std::cout	<< 
			"float: "	+ str						<< std::endl <<
			"double: "	+ pseudo[error_case + 4]	<< std::endl;	
			break;
		case 3:
			std::cout	<< 
			"float: "	+ str						<< std::endl <<
			"double: "	+ pseudo[error_case + 4]	<< std::endl;	
			break;
		default:
			break;
		}
		return (1);
	}
	else if (error_case >= 0)
	{
		std::cout	<< 
		"char: impossible"							<< std::endl <<
		"int: impossible"							<< std::endl <<
		"float: " + pseudo[error_case - 4]		 	<< std::endl <<
		"double: " + pseudo[error_case]				<< std::endl;
		return (1);
	}
	return (0);
}

int				ScalarConverter::isNum(std::string str, t_types *t)
{
	int	i = 0;
	t->length = str.length();
	int	dot_count = 0;
	
	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			if (i == t->length - 1)	//if its the last f for float then its ok. else no
			{
				if (str[i] == 'f')
				{
					t->f_decimal = true;
					return (1);
				}
			}
			else if (!(str[i] == '.') || dot_count > 0 )
			{
				if ((i == 0 && str[i] == '.' && str[i + 1] == '0'))
				{
					i++;
					continue ;
				}
				return (0);
			}
			dot_count++;
			t->decimal = true;
		}
		i++;
	}
	return (1);
}
