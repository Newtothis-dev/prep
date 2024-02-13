//
//  stack.cpp
//  dsr
//

#include "stack.h"

#include "vector-stack.h"

std::unique_ptr<DataStructures::Stack> DataStructures::Stack::Factory(Type t) {
    switch (t) {
        case VectorStack: {
            return std::make_unique<DataStructures::VectorStack>();
        }
        default:
            return nullptr;
    }
}
