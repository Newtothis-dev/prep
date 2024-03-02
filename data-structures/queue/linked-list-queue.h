//
//  linked-list-stack.h
//  dsr
//

#pragma once
#include "queue.h"

namespace DataStructures {

class LinkedListQueue : public Queue {
public:
    
    bool enqueue(Typ inp);
    Typ dequeue();
    bool isEmpty();
    void clear();
    
protected:
    struct LinkedItem {
        Typ t;
        LinkedItem* nxt = nullptr;
    };
    
    LinkedItem* QueueHead = nullptr;
    LinkedItem* QueueTail = nullptr;
};

}
