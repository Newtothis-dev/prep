//
//  linked-list-stack.cpp
//  dsr
//


#include "linked-list-queue.h"

using namespace DataStructures;

bool LinkedListQueue::enqueue(DataStructures::Typ inp) {

    LinkedItem* li = new LinkedItem;
    if (nullptr == li) {
        return false;
    }
    li->t = inp;
    
    if (nullptr == QueueHead)
    {
        QueueHead = li;
        QueueTail = li;
        return true;
    }
    
    QueueTail->nxt = li;
    QueueTail = li;
    return true;
    }

DataStructures::Typ LinkedListQueue::dequeue() {
    
    if (isEmpty()) {
        return EmptyContainer;
    }
    
    LinkedItem* tmp = QueueHead;
    Typ ret = tmp->t;
    
    if (QueueTail == QueueHead) {
        /// Last Element in the queue
        QueueTail = nullptr;
    }
    
    QueueHead = tmp->nxt;
    delete tmp;
    return ret;
}


bool LinkedListQueue::isEmpty() {
    return nullptr == QueueHead;
}

void LinkedListQueue::clear() {
    while (false == isEmpty()) {
        dequeue();
    }
}


