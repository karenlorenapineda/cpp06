/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:27:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/22 15:56:15 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	const std::string 	_name;
	int					_grade;
public:
	
	ScalarConverter(void);
	ScalarConverter(const std::string& name, int grade);
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter(void);

	ScalarConverter& operator=(const ScalarConverter& src);
};

std::ostream	&operator<<(std::ostream& str, const ScalarConverter& ScalarConverter);

#endif