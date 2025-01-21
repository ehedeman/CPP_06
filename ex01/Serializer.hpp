/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:51 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 16:02:57 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	/* data */
public:
						Serializer();
						Serializer(const Serializer &copy);
						~Serializer();
	
	Serializer			&operator=(const Serializer &serial);

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
