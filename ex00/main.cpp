/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/23 13:40:47 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void runTest(const std::string& literal) {
    std::cout << "========================================" << std::endl;
    std::cout << "Testing literal: \"" << literal << "\"" << std::endl;
    std::cout << "========================================" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    // Si se pasa un argumento por línea de comandos (Requisito del Subject)
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    // Batería de pruebas automáticas si se ejecuta sin argumentos
    std::cout << "--- STARTING AUTOMATIC TESTS ---" << std::endl << std::endl;

    // 1. Pruebas de CHAR
    runTest("a");
    runTest("Z");

    // 2. Pruebas de INT
    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647"); // INT_MAX
    runTest("2147483648"); // Overflow (Debería dar imposible en int)

    // 3. Pruebas de FLOAT
    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");

    // 4. Pruebas de DOUBLE
    runTest("0.0");
    runTest("42.42");
    runTest("-42.42");

    // 5. Casos Especiales (Pseudo-literales)
    runTest("nan");
    runTest("nanf");
    runTest("+inf");
    runTest("-inf");
    runTest("+inff");
    runTest("-inff");

    // 6. Casos Inválidos / Errores
    runTest("abc");
    runTest("42.42f42");
    runTest("");

    std::cout << "--- TESTS FINISHED ---" << std::endl;
    return 0;
}