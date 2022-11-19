// in case mutliple files in a project include strvector,
// this instruction says only compile this file once!
#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>

class StrVector
{
public:
    // type alias (this is how iterator types work!)
    using iterator = std::string *;
    using const_iterator = const std::string *;
    using size_type = std::size_t;
    using value_type = std::string;
    using reference = value_type &;
    using const_reference = const value_type &;

    // define an initial size for your underlying array
    const size_type kInitialSize = 2;

    // constructors and destructor
    StrVector();
    StrVector(size_type n, const std::string &val);
    ~StrVector();

    size_type size() const;
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;
    reference at(size_type pos);

    iterator insert(iterator pos, const_reference val);
    void push_back(const_reference val);

    iterator begin();
    iterator end();

    void grow();

private:
    value_type *data;
    size_type len;
    size_type cap;
};

#endif // STRVECTOR_H
