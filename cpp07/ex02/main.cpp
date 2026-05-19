#include "Array.hpp"

int main()
{
	std::cout << "--- TEST 1: Default Constructor ---" << std::endl;
	Array<int> emptyArr;
	std::cout << "Size of emptyArr: " << emptyArr.size() << std::endl;

	std::cout << "\n--- TEST 2: Parametrized Constructor & Default Init ---" << std::endl;
	Array<int> intArr(5);
	std::cout << "Size of intArr: " << intArr.size() << std::endl;
	std::cout << "Value at index 0 (should be 0): " << intArr[0] << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i * 10;
	std::cout << "\n--- TEST 3: Deep Copy Constructor ---" << std::endl;
	Array<int> copyArr(intArr);
	copyArr[0] = 999;
	std::cout << "Original intArr[0]: " << intArr[0] << " (should remain 0)" << std::endl;
	std::cout << "Copied copyArr[0]: " << copyArr[0] << " (should be 999)" << std::endl;

	std::cout << "\n--- TEST 4: Deep Assignment Operator ---" << std::endl;
	Array<int> assignedArr;
	assignedArr = intArr;
	assignedArr[1] = 888;
	std::cout << "Original intArr[1]: " << intArr[1] << " (should remain 10)" << std::endl;
	std::cout << "Assigned assignedArr[1]: " << assignedArr[1] << " (should be 888)" << std::endl;

	std::cout << "\n--- TEST 5: Out of Bounds Exception ---" << std::endl;
	try {
		std::cout << "Attempting to access intArr[10]..." << std::endl;
		std::cout << intArr[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}