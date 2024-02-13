//
//  stack.cpp
//  dsr
//

#include "stack.h"

#include "vector-stack.h"
#include "linked-list-stack.h"

std::unique_ptr<DataStructures::Stack> DataStructures::Stack::Factory(Type t) {
    switch (t) {
        case VectorStack: {
            return std::make_unique<DataStructures::VectorStack>();
        }
        case LinkedListStack: {
            return std::make_unique<DataStructures::LinkedListStack>();
        }
        default:
            return nullptr;
    }
}

std::string_view DataStructures::Stack::typeAsStr(Type t) {
    switch (t) {
        case VectorStack: {
            return "Vector Stack";
        }
        case LinkedListStack: {
            return "Linked List Stack";
        }
        default: {
            return "INVALID_STACK";
        }
    }
}
