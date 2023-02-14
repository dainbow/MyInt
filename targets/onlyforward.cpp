#include "../include/onlyforward.hpp"

int main() {
    // In this example we will calculate Fibonacci numbers in every cell of 100x100 matrix  
    IntMatrix prevValue;
    IntMatrix nextValue;

    FillStartPosition(prevValue, nextValue);
    auto onlyForwardStart = std::chrono::steady_clock::now();
    CalculateOnlyForward(prevValue, nextValue);
    auto onlyForwardEnd = std::chrono::steady_clock::now();
    
    FillStartPosition(prevValue, nextValue);
    auto fastStart = std::chrono::steady_clock::now();
    CalculateFast(prevValue, nextValue);
    auto fastEnd = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsedOnlyForward = onlyForwardEnd - onlyForwardStart;
    std::chrono::duration<double> elapsedFast = fastEnd - fastStart;

    // If you run the program, you can see that apropriate usage of move semantics can double your speed.
    std::cout << "Test with only forward took " << elapsedOnlyForward.count() << "s" << std::endl;
    std::cout << "Test with smart usage of move semantics took " << elapsedFast.count() << "s" << std::endl;
}

void FillStartPosition(IntMatrix& f0, IntMatrix& f1) {
    for (uint64_t curH = 0; curH < matrixHeight; curH++) {
        for (uint64_t curW = 0; curW < matrixWidth; curW++) {
            f0.SetElem(curH, curW, 0);
            f1.SetElem(curH, curW, 1);
        }
    }
}

// Example of wrong and useless usage of std::forward everything
void CalculateOnlyForward(IntMatrix& matrix1, IntMatrix& matrix2) {
    for (uint64_t curTest = 0; curTest < testsAmount; curTest++) {
        IntMatrix newValue = mystd::forward<decltype(matrix1 + matrix2)>(matrix1 + matrix2);
        
        matrix1 = mystd::forward<decltype(matrix2)>(matrix2);
        matrix2 = newValue;
    }

    std::cout << "F(" << testsAmount + 1 << ") = " << matrix2.GetElem(0, 0) << std::endl;
}

// Example of proper usage of move semantics
void CalculateFast(IntMatrix& matrix1, IntMatrix& matrix2) {
    for (uint64_t curTest = 0; curTest < testsAmount; curTest++) {
        IntMatrix newValue = matrix1 + matrix2;
        
        matrix1 = mystd::move(matrix2);
        matrix2 = mystd::forward<decltype(newValue)>(newValue);
    }

    std::cout << "F(" << testsAmount + 1 << ") = " << matrix2.GetElem(0, 0) << std::endl;
}
