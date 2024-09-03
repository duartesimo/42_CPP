#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Animal* animal = new Animal();  // Compilation Error

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return (0);
}