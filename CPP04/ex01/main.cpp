#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Subject Tests
	const int count = 4;
	Animal* animals[count];

	for (int i = 0; i < count / 2; ++i)
		animals[i] = new Dog();
	
	for (int i = count / 2; i < count; ++i)
		animals[i] = new Cat();
	
	for (int i = 0; i < count; ++i)
		animals[i]->makeSound();
	
	for (int i = 0; i < count; ++i)
		delete animals[i];


	// Virtual Testing
	/* Animal* animal100 = new Dog();
	delete animal100;
	Animal* animal200 = new Cat();
	delete animal200; */

	// Test deep copy with Brain content
	/* std::cout << "Creating basic Dog" << std::endl;
	Dog basic;
	basic.setBrainIdea(0, "Run Run Run");
	basic.setBrainIdea(1, "Bark Bark Bark");

	std::cout << "\nBasic Dog's Brain ideas before copy:" << std::endl;
	std::cout << "Idea 0: " << basic.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << basic.getBrainIdea(1) << std::endl;

	{
		std::cout << "\nCreating tmp Dog as a copy of basic" << std::endl;
		Dog tmp = basic;
		std::cout << "\nTmp Dog's Brain ideas after copy:" << std::endl;
		std::cout << "Idea 0: " << tmp.getBrainIdea(0) << std::endl;
		std::cout << "Idea 1: " << tmp.getBrainIdea(1) << std::endl;

		std::cout << "\nModifying tmp Dog's Brain ideas" << std::endl;
		tmp.setBrainIdea(0, "Sleep Sleep Sleep");
		tmp.setBrainIdea(1, "Eat Eat Eat");

		std::cout << "\nTmp Dog's Brain ideas after modification:" << std::endl;
		std::cout << "Idea 0: " << tmp.getBrainIdea(0) << std::endl;
		std::cout << "Idea 1: " << tmp.getBrainIdea(1) << std::endl;
	}

	std::cout << "\nAfter the scope, basic Dog's Brain ideas should be intact:" << std::endl;
	std::cout << "Idea 0: " << basic.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << basic.getBrainIdea(1) << std::endl; */

	// Direct Access: direct access to all methods and attributes of Cat, including those inherited from Animal
	/* Cat* animal = new Cat();
	animal->makeSound();
	animal->setBrainIdea(0, "Chase the mouse");
	std::cout << animal->getBrainIdea(0) << std::endl;
	delete animal; */

	// Through Polymorphism: would need to typecast if we wanted to access Cats specific methods
	/* Animal* animal = new Cat();
	animal->makeSound(); //works because is in Animal and is virtual
	animal->setBrainIdea(0, "Chase the mouse"); // Error: 'Animal' has no member named 'setBrainIdea'
	std::cout << animal->getBrainIdea(0) << std::endl; // Error: 'Animal' has no member named 'getBrainIdea'
	delete animal; */

	return 0;
}
