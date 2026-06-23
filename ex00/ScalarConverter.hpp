/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:27:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/23 13:47:13 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <string>
#include <cctype>
#include <cmath>

class ScalarConverter
{
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter(void);

	ScalarConverter& operator=(const ScalarConverter& src);

	static bool isSpecialFloat(const std::string& s);
	static bool isSpecialDouble(const std::string& s);
	static bool isChar(const std::string& s);
	static bool isInt(const std::string& s);
	static bool isFloat(const std::string& s);
	static bool isDouble(const std::string& s);
	
public:

	static void printChar(double d);
	static void printInt(double d);
	static void printFloatDouble(double d);
	static void fromDouble(double d);

	static void convert(const std::string& literal);
};

#endif