#include "../include/onlymove.hpp"

int main() {
    // Some big matrix initialization
    IntMatrix bigMatrix;
    for (uint64_t curH = 0; curH < matrixHeight; curH++) {
        for (uint64_t curW = 0; curW < matrixWidth; curW++) {
            bigMatrix.SetElem(curH, curW, {curH + curW});
        }
    }

    // Wow that marix so big, I'll use std::move and increase speed of program
    IntMatrix anotherBigMatrix = mystd::move(bigMatrix);

    // After that move I need big matrix again
    bigMatrix.SetElem(42, 42, {42});

    // But now bigMatrix's m_data pointer is nullptr, so I got SEGFAULT :(
}
