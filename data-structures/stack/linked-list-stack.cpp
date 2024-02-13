//
//  linked-list-stack.cpp
//  dsr
//


#include "linked-list-stack.h"

using namespace DataStructures;

bool LinkedListStack::push(DataStructures::Typ inp) {
    LinkedItem* li = new LinkedItem;
    li->t = inp;
    if (nullptr == Head) {
        Head = li;
        Tail = li->nxt;
        return true;
    }
    if (nullptr == Tail) {
        Head->nxt = li;
        Tail = li;
        return true;
    }
    
    Tail->nxt = li;
    Tail = li;
    return true;
}

DataStructures::Typ LinkedListStack::pop() {
    /// Empty List
    if (nullptr == Head) {
        return EmptyContainer;
    }
    /// One Item List
    if (nullptr == Tail) {
        DataStructures::Typ r = Head->t;
        delete Head;
        Head = nullptr;
        return r;
    }
    /// Multi-Item List
    LinkedItem* ptr = Head;
    while (nullptr != ptr->nxt->nxt) {
        ptr = ptr->nxt;
    }
    LinkedItem* rmv = ptr->nxt;

    Tail = ptr == Head ? nullptr : ptr;
    /// We don't have to set it to nullptr because the while loop shows it's already
    /// nullptr
    /// Tail->nxt = nullptr;
    DataStructures::Typ r = rmv->t;
    delete rmv;
    
    return r;
}

DataStructures::Typ LinkedListStack::peek() {
    LinkedItem* li = nullptr != Tail ? Tail : Head;
    if (nullptr != li) {
        return li->t;
    }
    return EmptyContainer;
}

bool LinkedListStack::isEmpty() {
    return Head == nullptr;
}

void LinkedListStack::clear() {
    while (false == isEmpty()) {
        pop();
    }
}


//    struct LinkedItem {
//        Typ t;
//        LinkedItem* nxt;
//    }
//    
//    LinkedItem* Head;
//    LinkedItem* Tail;

