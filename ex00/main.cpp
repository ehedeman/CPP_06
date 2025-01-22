/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:00:40 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/21 15:31:18 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string str;	

	if (argc != 2)
		return 0;
	str = argv[1];
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "575675442343247";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "2332.232f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "-2332.232f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "-2.1342639472693467";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "2332232f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "2332.23223f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "247947927.29342347f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "42.0f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "0";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "13";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "0f";
	ScalarConverter::convert(str);
	std::cout << std::endl;
	str = "0.0";
	ScalarConverter::convert(str);
}