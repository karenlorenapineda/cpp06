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

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter(void)
{
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return *this;
}

bool ScalarConverter::isSpecialFloat(const std::string& s)
{
	return s == "nanf" || s == "inff" || s == "+inff" || s == "-inff";
}

bool ScalarConverter::isSpecialDouble(const std::string& s)
{
	return s == "nan" || s == "inf" || s == "+inf" || s == "-inf";
}

bool ScalarConverter::isChar(const std::string& s)
{
	return s.length() == 1 && !std::isdigit(s[0]);
}

bool ScalarConverter::isInt(const std::string& s)
{
	if (s.empty()) return false;
	size_t start = 0;
	if (s[0] == '+' || s[0] == '-') start = 1;
	if (start >= s.length()) return false;

	for (size_t i = start; i < s.length(); i++)
		if (!std::isdigit(s[i])) return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string& s)
{
	if (s.empty() || s[s.length() - 1] != 'f') return false;
	std::string withoutF = s.substr(0, s.length() - 1);
	char *end;
	std::strtod(withoutF.c_str(), &end);
	return *end == '\0' && withoutF.find('.') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string& s)
{
	if (s.empty()) return false;
	char *end;
	std::strtod(s.c_str(), &end);
	return *end == '\0' && s.find('.') != std::string::npos;
}

void ScalarConverter::printChar(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || d != static_cast<long long>(d))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::printInt(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloatDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
	printChar(d);
	printInt(d);
	printFloatDouble(d);
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isSpecialFloat(literal))
	{
		std::string withoutF = literal.substr(0, literal.length() - 1);
		double d = std::strtod(withoutF.c_str(), NULL);
		fromDouble(d);
		return;
	}

	if (isSpecialDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		fromDouble(d);
		return;
	}

	if (isChar(literal))
	{
		fromDouble(static_cast<double>(literal[0]));
		return;
	}

	if (isInt(literal))
	{
		long l = std::strtol(literal.c_str(), NULL, 10);
		if ( l < INT_MIN || l > INT_MAX)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		fromDouble(static_cast<double>(l));
		return;
	}

	if (isFloat(literal))
	{
		std::string withoutF = literal.substr(0, literal.length() - 1);
		double d = std::strtod(withoutF.c_str(), NULL);
		fromDouble(d);
		return;
	}

	if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		fromDouble(d);
		return;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;

}