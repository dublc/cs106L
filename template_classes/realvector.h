#ifndef CS106L_REALVECTOR_H_
#define CS106L_REALVECTOR_H_

#include <cstddef>

template <typename T>
class RealVector
{
public:
    // type alias (this is how iterator types work!)
    using iterator = T *;
    using const_iterator = T const *;
    using size_type = std::size_t;
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;

    // define an initial size for your underlying array
    const size_type kInitialSize = 2;

    // constructors and destructor
    RealVector();
    RealVector(size_type n, const_reference val);
    ~RealVector();

    size_type size() const;

    void insert(size_type pos, const_reference val);
    void push_back(const_reference val);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    void grow();
    value_type *data;
    size_type len;
    size_type cap;
};

#include "realvector.cpp"
#endif