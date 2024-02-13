//
//  linked-list-stack.h
//  dsr
//

#pragma once
#include "stack.h"

namespace DataStructures {

class LinkedListStack : public Stack {
public:
    
    bool push(DataStructures::Typ inp);
    DataStructures::Typ pop();
    DataStructures::Typ peek();
    bool isEmpty();
    void clear();
    
protected:
    struct LinkedItem {
        DataStructures::Typ t;
        LinkedItem* nxt = nullptr;
    };
    
    LinkedItem* Head = nullptr;
    LinkedItem* Tail = nullptr;
};

}
