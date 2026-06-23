/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:06:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/23 19:20:38 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	switch (std::rand() % 3)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
		
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
		
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
		
	}
	std::cout << "Unknow" << std::endl;
}

#include <iostream>
#include <unistd.h> // Para usleep y dar tiempo a que cambie std::time
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Prototipos de tus funciones para que el main las conozca
Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

int main(void)
{
    std::cout << "=== PRUEBA 1: IDENTIFICACIÓN ALEATORIA EN BUCLE ===" << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "--- Test #" << i + 1 << " ---" << std::endl;
        
        // 1. Generar la instancia aleatoria (A, B o C)
        Base* instance = generate();
        if (!instance)
        {
            std::cout << "Error: generate() devolvió NULL" << std::endl;
            continue;
        }

        // 2. Probar identificación pasándole el PUNTERO
        std::cout << "Identificación por puntero   : ";
        identify(instance);

        // 3. Probar identificación pasándole la REFERENCIA
        std::cout << "Identificación por referencia: ";
        identify(*instance);

        // 4. Liberar la memoria dinámicamente asignada por generate()
        // ¡CRÍTICAL para evitar leaks! Asegúrate de que Base tenga destructor virtual.
        delete instance;
        
        std::cout << std::endl;
        usleep(200000); // Pausa de 200ms para asegurar variedad en la semilla de tiempo
    }

    std::cout << "=== PRUEBA 2: INSTANCIA DESCONOCIDA ===" << std::endl;
    // Creamos un objeto directamente de la clase Base (no es ni A, ni B, ni C)
    Base* unk = new Base();
    
    std::cout << "Identificando clase Base pura (debería dar Unknow):" << std::endl;
    std::cout << "Por puntero   : ";
    identify(unk);
    std::cout << "Por referencia: ";
    identify(*unk);
    
    delete unk;

    return 0;
}