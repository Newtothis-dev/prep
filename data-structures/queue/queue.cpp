//
//  stack.cpp
//  dsr
//

#include "queue.h"

#include "linked-list-queue.h"


std::unique_ptr<DataStructures::Queue> DataStructures::Queue::Factory(Type t) {
    switch (t) {
        case LinkedListQueue: {
            return std::make_unique<DataStructures::LinkedListQueue>();
        }
        default:
            return nullptr;
    }
}

std::string_view DataStructures::Queue::typeAsStr(Type t) {
    switch (t) {
        case LinkedListQueue: {
            return "Linked List Queue";
        }
        default: {
            return "INVALID_STACK";
        }
    }
}
