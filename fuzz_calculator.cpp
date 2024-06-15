// fuzz_target.cpp
#include "calculator.hpp"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // Convert input data into a string
    std::string Input(reinterpret_cast<const char*>(Data), Size); 

    // Call calculator::eval with the fuzzed input  
    try {
        calculator::eval<int>(Input);
    } catch (const calculator::error&) {
        // Handle calculator errors, if necessary
    }

    return 0;
}
