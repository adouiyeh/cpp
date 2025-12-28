#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.name = "Test Data";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data value: " << data.value << std::endl;
    std::cout << "Original Data name: " << data.name << std::endl;

    unsigned long serialized = Serializer::serialize(&data);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Deserialized value: " << deserialized->value << std::endl;
    std::cout << "Deserialized name: " << deserialized->name << std::endl;
    
    return 0;
}
