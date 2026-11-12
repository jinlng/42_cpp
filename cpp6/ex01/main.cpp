#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.id = 42;
    originalData.name = "Module 06";

    Data* ptr = &originalData;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << ptr << std::endl;
    std::cout << "Serialized uintptr:   " << raw << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (ptr == deserializedPtr) {
        std::cout << "SUCCESS: Pointers match perfectly!" << std::endl;
    } else {
        std::cout << "FAILURE: Pointers do not match!" << std::endl;
    }

    return 0;
}