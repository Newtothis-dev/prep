//
//  test-stack.cpp
//  dsr
//

#include "test-stack.h"
#include <string>

/// MARK: Get All
const Quality::TestBlock& DataStructures::getAllStackImplTests() {
    static Quality::TestBlock allTests;
    /// Clear for re-execution. Could do some kind of shortcut if this needed to get re-run but there was no expectation of change.
    /// Could add a "refresh" variable set if there's concerns about caching.
    allTests.clear();
    
    {
        std::unique_ptr<Stack> vectStack = std::make_unique<VectorStack>();
        const Quality::TestBlock& implTests = getStackImplTests(vectStack.get());
        allTests.insert(allTests.end(), implTests.begin(), implTests.end());
    }
    
    /// ... Other Impls?
    return allTests;
}

/// MARK: Tests
bool alwaysPass(std::string& inp) {
    return true;
}

bool alwaysFail(std::string& inp) {
    inp = "I FAILED :( :( ";
    return false;
}



/// MARK: Get Impl
/// Intentionally put this at bottom to allow for all the tests to be added aove.

const Quality::TestBlock& DataStructures::getStackImplTests(const Stack* iStackObj) {
    static Quality::TestBlock def = {
        {"Always Pass", alwaysPass},
        {"Always Fail", alwaysFail},
    };
    return def;
}
