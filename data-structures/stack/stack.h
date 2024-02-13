//
//  stack.h
//

#pragma once
#include "data-structures-shared.h"
#include <memory>

namespace DataStructures {
    
class Stack {
public:
    
    enum Type {
        VectorStack, /* vector-stack.h */
        
    };
    
    static std::unique_ptr<Stack> Factory(Type t);
    
    virtual ~Stack() { }
    /// @brief Should technically implement all the copy, move, assignment, etc. operators.
    virtual bool push(Typ inp) = 0;
    virtual Typ pop() = 0;
    virtual Typ peek() = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0; 
};







}


