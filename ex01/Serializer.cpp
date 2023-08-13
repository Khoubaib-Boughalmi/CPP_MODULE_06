#include "Serializer.h"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void) other;}
const Serializer& Serializer::operator=(const Serializer& other) { 
    (void)other;
    return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t uptr;
    uptr = reinterpret_cast<uintptr_t>(&ptr);
    return (uptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* data;
    data = reinterpret_cast<Data*>(&raw);
    return (data);
}