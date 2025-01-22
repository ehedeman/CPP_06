/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:31 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/22 11:31:41 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

class Base
{
public:
	virtual ~Base();
private:
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

Base	*generate(void);

void	identify(Base *p);

void	identify(Base &p);