/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:32 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 15:42:14 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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