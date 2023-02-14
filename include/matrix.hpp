#pragma once 

#include <utility>

#include <cassert>
#include <cstdint>

#include "mystd.hpp"

template<class T, uint64_t width, uint64_t height>
class Matrix {
    using CurrentMatrix = Matrix<T, width, height>;

    public:
        Matrix() :
            m_data(new T*[height]()) 
        {
            for (uint64_t currentH = 0; currentH < height; currentH++) {
                m_data[currentH] = new T[width]();
            }
        }

        Matrix(const CurrentMatrix& matrix) :
            m_data(new T*[height]())
        {
            for (uint64_t currentH = 0; currentH < height; currentH++) {
                m_data[currentH] = new T[width]();

                for (uint64_t currentW = 0; currentW < width; currentW++) {
                    m_data[currentH][currentW] = matrix.m_data[currentH][currentW];
                }
            }
        }

        Matrix(CurrentMatrix&& matrix) : 
            m_data(nullptr)
        {
            std::swap(m_data, matrix.m_data);
        }

        CurrentMatrix& operator=(const CurrentMatrix& matrix) {
            for (uint64_t currentH = 0; currentH < height; currentH++) {
                for (uint64_t currentW = 0; currentW < width; currentW++) {
                    m_data[currentH][currentW] = matrix.m_data[currentH][currentW];
                }
            }

            return *this;
        }

        CurrentMatrix& operator=(CurrentMatrix&& matrix) {
            std::swap(m_data, matrix.m_data);

            return *this;
        }

        ~Matrix() {
            if (m_data == nullptr) {
                return;
            }

            for (uint64_t currentH = 0; currentH < height; currentH++) {
                delete[] m_data[currentH];
            }
            delete[] m_data;
        }

        T GetElem(const uint64_t h, const uint64_t w) {
            assert(h < height);
            assert(w < width);

            return m_data[h][w];
        }

        void SetElem(const uint64_t h, const uint64_t w, T&& elem) {
            assert(h < height);
            assert(w < width);

            m_data[h][w] = mystd::forward<T>(elem);
        }

        void operator+=(const CurrentMatrix& matrix) {
            for (uint64_t currentH = 0; currentH < height; currentH++) {
                for (uint64_t currentW = 0; currentW < width; currentW++) {
                    m_data[currentH][currentW] += matrix.m_data[currentH][currentW];
                }
            }
        }

        CurrentMatrix operator+(const CurrentMatrix& matrix) const {
            CurrentMatrix tmp = *this;
            tmp += matrix;

            return tmp;
        }


    private:
        T** m_data;
};
