#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 35;

	Data *a1 = &data;
	std::cout << "Original pointer: " << a1 << std::endl;
	std::cout << "Original value: " << a1->value << std::endl;

	uintptr_t t = Serializer::serialize(a1);
	std::cout << "Serialized value: " << t << std::endl;

	Data *a2 = Serializer::deserialize(t);
	std::cout << "Deserialized pointer: " << a2 << std::endl;
	std::cout << "Deserialized value: " << a2->value << std::endl;

	return 0;
}
