#include "Serializer.hpp"

int main()
{
	Data myData;

	myData.num = 42;
	std::cout << "Original Data Address: " << &myData << std::endl;
	std::cout << "Original Data ID:      " << myData.num << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	uintptr_t rawPtr = Serializer::serialize(&myData);
	std::cout << "Serialized (uintptr_t): " << rawPtr << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	Data* deserializedPtr = Serializer::deserialize(rawPtr);
	std::cout << "Deserialized Address:  " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data ID:  " << deserializedPtr->num << std::endl;
	return 0;
}