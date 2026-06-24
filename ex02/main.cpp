/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:06:00 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/24 10:45:50 by kpineda-         ###   ########.fr       */
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
#include <unistd.h> // To usleep y give time to change std::time
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// My functions prototype for main
Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

int main(void)
{
    std::cout << "=== TEST 1: RANDOM IDENTIFICATION IN LOOP ===" << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "--- Test #" << i + 1 << " ---" << std::endl;
        
        // 1. Generate the random instance (A, B, or C)
        Base* instance = generate();
        if (!instance)
        {
            std::cout << "Error: generate() returned NULL" << std::endl;
            continue;
        }

        // 2. Test identification by passing the POINTER
        std::cout << "Identification by pointer   : ";
        identify(instance);

        // 3. Test identification by passing the REFERENCE
        std::cout << "Identification by reference: ";
        identify(*instance);

        // 4. Free the memory dynamically allocated by generate()
        // CRITICAL to avoid leaks! Make sure Base has a virtual destructor.
        delete instance;
        
        std::cout << std::endl;
        usleep(200000); // 200ms pause to ensure variety in the time seed
    }

    std::cout << "=== TEST 2: UNKNOWN INSTANCE ===" << std::endl;
    // We create an object directly from the Base class (it is neither A, B, nor C)
    Base* unk = new Base();
    
    std::cout << "Identifying pure Base class (should result in Unknown):" << std::endl;
    std::cout << "By pointer   : ";
    identify(unk);
    std::cout << "By reference: ";
    identify(*unk);
    
    delete unk;

    return 0;
}