//
//  test-stack.h
//  dsr
//

#pragma once

/// Interface
#include "stack.h"
/// Specific implementation
#include "vector-stack.h"

/// Include the quality namespace
#include "test-runner.h"

namespace DataStructures {

/// @brief All stack tests should be designed to the interface to make sure all stacks work in the same way
const Quality::TestBlock& getStackImplTests(const Stack* iStackObj);

/// @brief get all tests for all implementations of a stack. 
const Quality::TestBlock& getAllStackImplTests();

}

