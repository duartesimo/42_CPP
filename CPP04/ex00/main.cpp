#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// ability of different classes to be treated as instances of the same class through a common interface (inheritance)
	// can only call methods that are defined in the Animal class. However, if those methods are virtual and overridden in Cat, the Cat version will be called
	std::cout << "Testing with Animal, Cat and Dog:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();  // Cat sound
	j->makeSound();  // Dog sound
	meta->makeSound(); // Animal sound

	delete meta;
	delete j;
	delete i;

	std::cout << "\nTesting with WrongAnimal and WrongCat:" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	//const WrongCat* wrongCat2 = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();  // Wrong animal sound
	wrongMeta->makeSound(); // Wrong animal sound
	//wrongCat2->makeSound();

	delete wrongMeta;
	delete wrongCat;
	//delete wrongCat2;

	return (0);
}