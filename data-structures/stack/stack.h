//
//  stack.h
//

#pragma once
#include "data-structures-shared.h"


namespace DataStructures {
    
class Stack {
public:
    virtual ~Stack() { }
    /// @brief Should technically implement all the copy, move, assignment, etc. operators.
    virtual bool push(Typ inp) = 0;
    virtual Typ pop() = 0;
    virtual Typ peek() = 0;
    virtual bool isEmpty() = 0;
};



}


