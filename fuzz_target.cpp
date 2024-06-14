#include "calculator.hpp"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // Convert input data into a string
    std::string Input(reinterpret_cast<const char*>(Data), Size);

    // Call calculator::eval with the fuzzed input
    try {
        calculator::eval<int>(Input);

        // Introduce mutations to explore more paths
        for (size_t i = 0; i < Size; ++i) {
            // Example mutation strategy: Flip each bit in the input data
            uint8_t mutatedData = Data[i] ^ 0xFF;
            std::string MutatedInput(reinterpret_cast<const char*>(&mutatedData), Size);
            calculator::eval<int>(MutatedInput);
        }

        // Generate targeted inputs for specific operations or edge cases
        if (Size > 0) {
            // Example: Add inputs that focus on division operations
            std::string DivisionInput = "10 / " + Input.substr(1);  // Avoid starting with zero
            calculator::eval<int>(DivisionInput);

            // Example: Test with an input that might cause a specific error
            std::string ErrorInput = "invalid input";
            calculator::eval<int>(ErrorInput);
        }

    } catch (const calculator::error&) {
        // Handle calculator errors, if necessary
        // For example, log the error or ignore it based on the application's error handling strategy
    }

    return 0;
}
