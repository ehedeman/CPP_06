/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:47:42 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 16:05:16 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

	data.c = 'c';
	data.i = 0;
	data.f = 0;
	data.d = 0;
	data.str = "hello";
	uintptr_t ptr;

	ptr = Serializer::serialize(&data);

	std::cout << &data	<< std::endl;
	std::cout << ptr	<< std::endl;
	std::cout << Serializer::deserialize(ptr) << std::endl;
}