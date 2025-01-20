/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/20 16:26:03 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#define DISPLAYABLE_MAX 126
#define DISPLAYABLE_MIN 33

typedef struct s_types
{
	std::string	str;
	int			length;
	int			i;
	float		f;
	double		d;
	std::string	char_err;
	bool		decimal;
	bool		f_decimal;
}				t_types;


class ScalarConverter
{
private:

public:
					ScalarConverter();
					ScalarConverter(const ScalarConverter &copy);
					~ScalarConverter();
	
	ScalarConverter	&operator=(const ScalarConverter &scalar);

	static void		convert(std::string _s);
	
	static void			printFloat(const float f, const int digits);
	static void			printInt(const int i);
	static void			printChar(const char c);
	static void			printDouble(const double d, const int digits);
	
	static int			PseudoLiterals(std::string str);
	static int			isNum(std::string str, t_types *t);
	static void			convertTypes(t_types *t);
	static void			setDigits(t_types *t, int *digits);
};