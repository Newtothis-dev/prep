//
//  vector-stack.h
//  dsr
//

#pragma once


#include "stack.h"
#include <vector>

namespace DataStructures {

class VectorStack:  public Stack {
public:
    ~VectorStack(){}
    
    virtual bool push(Typ inp);
    virtual Typ pop();
    virtual Typ peek();
    virtual bool isEmpty();
    virtual void clear(); 
protected:
    std::vector<Typ> vec;
};

}

