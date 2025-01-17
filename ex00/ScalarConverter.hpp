/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:37:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/17 16:42:31 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef struct s_types
{
	int		i;
	char	c;
	float	f;
	double	d;
}				t_types;


class ScalarConverter
{
private:

public:
					ScalarConverter();
					ScalarConverter(std::string _s);
					ScalarConverter(const ScalarConverter &copy);
					~ScalarConverter();
	
	ScalarConverter	&operator=(const ScalarConverter &scalar);

	static void		convert(std::string _s);
};
