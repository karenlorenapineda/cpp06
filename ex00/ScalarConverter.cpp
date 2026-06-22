/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:31:52 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/16 20:36:47 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void): _name("default"), _grade(150)
{
	
}

ScalarConverter::ScalarConverter(const std::string& name, int grade): _name(name)
{
	this->_grade = grade;
	if(this->_grade < 1)
		throw (ScalarConverter::GradeTooHighException());
	else if(this->_grade > 150)
		throw (ScalarConverter::GradeTooLowException());
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) : _name(src._name), _grade(src._grade)
{
	
}

ScalarConverter::~ScalarConverter(void)
{
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	if(this != &src)
	{
		this->_grade = src._grade;
	}
	return(*this);
}

std::ostream &operator<<(std::ostream& str, const ScalarConverter& ScalarConverter)
{
	return(str << ScalarConverter.getName() << ", bureacrat grade " << ScalarConverter.getGrade());
}