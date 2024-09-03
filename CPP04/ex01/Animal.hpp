#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(); //when a derived object is deleted through a base class pointer, calls ~Dog First
		
		std::string getType() const;
		virtual void makeSound() const;
};

#endif