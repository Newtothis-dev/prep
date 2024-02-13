//
//  vector-stack.cpp
//  dsr
//

#include "vector-stack.h"
using  namespace DataStructures;

bool VectorStack::push(Typ inp)
{
    auto len = vec.size();
    vec.push_back(inp);
    return len < vec.size();
}

Typ VectorStack::pop()
{
    auto v = peek();
    vec.pop_back();
    return v;
}

Typ VectorStack::peek()
{
    if (vec.empty()) {
        return {};
    }
    auto v = vec.back();
    return v;
}

bool VectorStack::isEmpty()
{
    return vec.empty();
}

void VectorStack::clear()
{
    vec.clear();
}
