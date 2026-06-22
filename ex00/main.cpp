/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/22 15:55:31 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	try 
	{
		ScalarConverter a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade(); // OK → pasa a 1
        std::cout << a << std::endl;

        a.incrementGrade(); // ERROR
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}