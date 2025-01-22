/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 15:42:09 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <float.h>
#include <sstream>
#include <limits>
#include "Types.hpp"

#define DISPLAYABLE_MAX 126
#define DISPLAYABLE_MIN 33


class ScalarConverter
{
private:

public:
					ScalarConverter();
					ScalarConverter(const ScalarConverter &copy);
					~ScalarConverter();
	
	ScalarConverter	&operator=(const ScalarConverter &scalar);

	static void		convert(std::string _s);
	
	static void			printFloat(const float f, const bool decimal);
	static void			printInt(const int i);
	static void			printChar(const char c);
	static void			printDouble(const double d, const bool decimal);
	static void			caseChar(const int i);
	static void			caseFloat(t_types *t);
	static void			caseDouble(t_types *t);
	static void			caseInt(const int i);

	static int			PseudoLiterals(std::string str);
	static int			isNum(std::string str, t_types *t);
	static void			convertTypes(t_types *t);
	// static void			setDigits(t_types *t, int *digits);
};