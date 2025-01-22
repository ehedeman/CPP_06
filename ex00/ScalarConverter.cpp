/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:42 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 15:42:12 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstring>

/*--------------------------------Constructors------------------------------------*/
ScalarConverter::ScalarConverter()
{
	std::cout	<< "ScalarConverter default Constructor called."		<< std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout	<< "ScalarConverter Copy Constructor has been called."	<< std::endl;
	*this = copy;
		
}

/*--------------------------------Deconstructor-----------------------------------*/
ScalarConverter::~ScalarConverter()
{
	std::cout	<< "ScalarConverter Destructor has been called."		<< std::endl;
}
/*--------------------------------Assignment-Operator-----------------------------*/
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &scalar)
{
	if (this == &scalar)
		return (*this);
	return (*this);
}

/*--------------------------------Main Static Function----------------------------*/
void			ScalarConverter::convertTypes(t_types *t)
{
	char	**ptr = new char *;
	t->d = std::strtod(t->str.c_str(), ptr);
	if (**ptr && (strlen(*ptr) != 1))
		std::cout	<< "error" 											<< std::endl;
	std::ostringstream s;
	s << t->d;
	std::string str(s.str());
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.')
			t->decimal = true;
	}
	t->f =	static_cast<float>(t->d);
	t->i =  static_cast<int>(t->d);
	delete(ptr);
}
/*------------------------------Static Helper Functions---------------------------*/
void			ScalarConverter::printDouble(const double d, const bool decimal)
{
	if (!decimal || !d)
		std::cout		<<	"double: "	<<	d			<<	".0"		<< std::endl;
	else if (decimal)
	std::cout			<<	"double: "	<<	d							<< std::endl;
}

void			ScalarConverter::printInt(const int i)
{
	std::cout		<<	"int: "					<<	i					<< std::endl;
}

void			ScalarConverter::printChar(const char c)
{
	if (c == -1)
		std::cout	<<	"char: Impossible"								<< std::endl;
	else if (c > DISPLAYABLE_MAX || c < DISPLAYABLE_MIN)
		std::cout	<<	"char: Non displayable"							<< std::endl;
	else
		std::cout	<<	"char: "				<<	c					<< std::endl;
}

void			ScalarConverter::printFloat(const float f, const bool decimal)
{
	if (!decimal)
		std::cout		<<	"float: "	<<	f			<<	".0f"		<< std::endl;
	else if (decimal)
	std::cout			<<	"float: "	<<	f			<<	"f"			<< std::endl;
}

void			ScalarConverter::caseChar(const int i)
{
	if (i < 0 || i > 127)
		printChar(-1);
	else
		printChar(i);
}

void			ScalarConverter::caseFloat(t_types *t)
{
	if (!t->f)
		printFloat(0, false);
	else if (t->f > std::numeric_limits<float>::max())
		std::cout << "float: Non displayable (overflow)"				<< std::endl;
	else if (t->f < -std::numeric_limits<float>::max())
		std::cout << "float: Non displayable (overflow)"				<< std::endl;
	else
		printFloat(t->f, t->decimal);
}

void			ScalarConverter::caseDouble(t_types *t)
{
	if (!t->d)
		printDouble(0, false);
	else if (t->d > std::numeric_limits<double>::max())
		std::cout << "double: Non displayable (overflow)"				<< std::endl;
	else if (t->d < -std::numeric_limits<double>::max())
		std::cout << "double: Non displayable (overflow)"				<< std::endl;
	else
		printDouble(t->d, t->decimal);
}

void			ScalarConverter::caseInt(const int i)
{
	if (i > std::numeric_limits<int>::max())
		std::cout << "int: Non displayable (overflow)"					<< std::endl;
	else if (i < std::numeric_limits<int>::min())
		std::cout << "int: Non displayable (overflow)"					<< std::endl;
	else
		printInt(i);
}

void			ScalarConverter::convert(std::string str)
{
	t_types 	t;
	std::string copy;

	t.str = str;
	t.decimal = false;
	if (PseudoLiterals(str))
		return ;
	if (str[0] == '-')
		copy = &str[1];
	else
		copy = str;
	if (!isNum(copy, &t))
	{
		std::cout	<< "Error: Wrong Format."							<< std::endl;
		return ;
	}
	convertTypes(&t);
	std::cout << "string: " << t.str									<< std::endl;
	caseChar(t.i);
	caseInt(t.i);
	caseFloat(&t);
	caseDouble(&t);
}

int				ScalarConverter::PseudoLiterals(std::string str)
{
	std::string pseudo[8] = {"inff" ,"-inff", "+inff", "nanf", "inf", \
		"-inf", "+inf", "nan"};
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
			if (i == t->length - 1)
			{
				if (str[i] == 'f')
					return (1);
			}
			else if (!(str[i] == '.') || dot_count > 0 )
			{
				if ((i == 0 && str[i] == '.' && str[i + 1] == '0'))
				{
					i++;
					dot_count++;
					t->decimal = true;
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

// void			ScalarConverter::setDigits(t_types *t, int *digits)
// {
// 	int 	i = 0;
// 	int		count = 0;

// 	if (t->str[i] == '-')
// 		i++;
// 	while (t->str[i])
// 	{
// 		if (t->str[i] == '.')
// 			i++;
// 		if (t->str[i] == 'f')
// 			break ;
// 		count++;
// 		i++;
// 	}
// 	*digits = count;
// }