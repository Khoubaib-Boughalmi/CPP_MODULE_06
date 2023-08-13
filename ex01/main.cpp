#include "Serializer.h"

int main()
{
    Data myDictionary = {1337};
    Data* dictionaryPtr = &myDictionary;
    uintptr_t serializedPtr;

    std::cout << &myDictionary._key << std::endl;
    std::cout << myDictionary._key<< std::endl;
    serializedPtr = Serializer::serialize(dictionaryPtr);
    std::cout << &myDictionary._key << std::endl;
    std::cout << myDictionary._key<< std::endl;
    dictionaryPtr = Serializer::deserialize(serializedPtr);
    std::cout << &myDictionary._key << std::endl;
    std::cout << myDictionary._key<< std::endl;
    return (0);
}
