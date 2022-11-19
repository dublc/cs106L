// dont forget to include the .h file!
// implementation for strvector.cpp goes here!
#include "strvector.h"

StrVector::StrVector() : len{0}, cap{kInitialSize}
{
    this->data = new std::string[this->cap];
}
StrVector::StrVector(size_type n, const_reference val) :
    len{n}, cap{2*n}
{
    this->data = new std::string[this->cap];
    std::fill(begin(), end(), val);
}
StrVector::~StrVector() {
    delete[] this->data;
}

StrVector::size_type StrVector::size() const
{
    return this->len;
}

void StrVector::grow()
{
    value_type* temp = new value_type[this->cap*2];
    std::copy(begin(), end(), temp);
    delete[] this->data;
    this->cap *= 2;
    this->data = temp; 
}

StrVector::iterator StrVector::insert(iterator pos, const_reference val)
{
    if (size() == this->cap)
        grow();
    std::copy_backward(pos, end(), end() + 1);
    *pos = val;
    ++len;
    return pos;
}

StrVector::iterator StrVector::begin()
{
    return this->data;
}
StrVector::iterator StrVector::end()
{
    return this->data + size();
}