#pragma once

#include <chrono>
#include <iostream>

#include "matrix.hpp"
#include "mystd.hpp"

constexpr uint64_t matrixWidth = 1000;
constexpr uint64_t matrixHeight = 1000;
using IntMatrix = Matrix<uint64_t, matrixWidth, matrixHeight>;

constexpr uint64_t testsAmount = 1000;

void FillStartPosition(IntMatrix& f0, IntMatrix& f1);
void CalculateOnlyForward(IntMatrix& matrix1, IntMatrix& matrix2);
void CalculateFast(IntMatrix& matrix1, IntMatrix& matrix2);
