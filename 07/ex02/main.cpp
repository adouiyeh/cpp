#include "Array.hpp"

int main() {
    std::cout << "=== Array Template Tests ===" << std::endl;

    // Test 1: Default constructor
    std::cout << "\n1. Default constructor:" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.getSize() << std::endl;

    // Test 2: Constructor with size
    std::cout << "\n2. Constructor with size:" << std::endl;
    Array<int> intArray(5);
    std::cout << "Integer array size: " << intArray.getSize() << std::endl;
    for (std::size_t i = 0; i < intArray.getSize(); ++i)
        intArray[i] = i * 10;
    
    // Test 3: Display array
    std::cout << "\n3. Display array contents:" << std::endl;
    for (std::size_t i = 0; i < intArray.getSize(); ++i)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    // Test 4: Copy constructor
    std::cout << "\n4. Copy constructor:" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.getSize() << std::endl;
    std::cout << "copiedArray[2] = " << copiedArray[2] << std::endl;

    // Test 5: Assignment operator
    std::cout << "\n5. Assignment operator:" << std::endl;
    Array<int> assignedArray(3);
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.getSize() << std::endl;
    std::cout << "assignedArray[3] = " << assignedArray[3] << std::endl;

    // Test 6: Array of strings
    std::cout << "\n6. Array of strings:" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (std::size_t i = 0; i < stringArray.getSize(); ++i)
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

    // Test 7: Out of bounds exception
    std::cout << "\n7. Out of bounds exception:" << std::endl;
    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 8: Const reference access
    std::cout << "\n8. Const reference access:" << std::endl;
    const Array<int>& constRef = intArray;
    std::cout << "constRef[1] = " << constRef[1] << std::endl;

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
