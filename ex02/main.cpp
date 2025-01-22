/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:45 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/22 11:58:25 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *ptr;

	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		identify(ptr);
		identify((*ptr));
		std::cout << std::endl;
		delete(ptr);
	}
}