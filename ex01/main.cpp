/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:45:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/23 17:43:34 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    // 1. Crear e inicializar una estructura Data con valores de prueba
    Data miData;
    miData.id = 42;
    miData.name = "Evaluador de 42";
    miData.value = 3.1416;

    std::cout << "--- DATOS ORIGINALES ---" << std::endl;
    std::cout << "Dirección original : " << &miData << std::endl;
    std::cout << "ID                 : " << miData.id << std::endl;
    std::cout << "Nombre             : " << miData.name << std::endl;
    std::cout << "Valor (double)     : " << miData.value << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 2. Serializar: Convertir el puntero (Data*) a un entero sin signo (uintptr_t)
    std::cout << "Serializando puntero..." << std::endl;
    uintptr_t raw = Serializer::serialize(&miData);
    std::cout << "Valor entero (raw) : " << raw << " (en hexadecimal: 0x" << std::hex << raw << std::dec << ")" << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 3. Deserializar: Convertir el entero (uintptr_t) de vuelta a un puntero (Data*)
    std::cout << "Deserializando entero..." << std::endl;
    Data* ptrDeserializado = Serializer::deserialize(raw);

    std::cout << "--- DATOS RECONSTRUIDOS ---" << std::endl;
    std::cout << "Dirección devuelta : " << ptrDeserializado << std::endl;
    std::cout << "ID                 : " << ptrDeserializado->id << std::endl;
    std::cout << "Nombre             : " << ptrDeserializado->name << std::endl;
    std::cout << "Valor (double)     : " << ptrDeserializado->value << std::endl;
    std::cout << "------------------------" << std::endl << std::endl;

    // 4. Verificación de seguridad (La prueba de fuego del Subject)
    if (ptrDeserializado == &miData)
    {
        std::cout << "✅ ÉXITO: ¡Los punteros son idénticos!" << std::endl;
        std::cout << "La serialización y deserialización no corrompieron la memoria." << std::endl;
    }
    else
    {
        std::cout << "❌ ERROR: Los punteros NO coinciden." << std::endl;
    }

    return 0;
}