#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>

#define INT_LOG

class MyInt {
    public:
        MyInt(const int32_t integer, const std::string& name = "", std::ostream& stream = std::cout);
        MyInt(const MyInt& intToCopy, const std::string& name = "");

        operator int() const;

        MyInt& operator=(const MyInt& intToEq);
        MyInt& operator+=(const MyInt& intToPlus);
        MyInt& operator-=(const MyInt& intToSub);
        MyInt& operator*=(const MyInt& intToMul);
        MyInt& operator/=(const MyInt& intToDiv);
        MyInt& operator%=(const MyInt& intToMod);
        MyInt& operator&=(const MyInt& intToAnd);
        MyInt& operator|=(const MyInt& intToOr);
        MyInt& operator^=(const MyInt& intToXor);
        MyInt& operator<<=(const MyInt& intToShl);
        MyInt& operator>>=(const MyInt& intToShr);

        MyInt& operator++();
        MyInt operator++(int);

        MyInt& operator--();
        MyInt operator--(int);

        MyInt operator!() const;
        MyInt operator~() const;

        MyInt operator+(const MyInt& integer) const;
        MyInt operator-(const MyInt& integer) const;
        MyInt operator*(const MyInt& integer) const;
        MyInt operator/(const MyInt& integer) const;
        MyInt operator%(const MyInt& integer) const;
        MyInt operator&(const MyInt& integer) const;
        MyInt operator|(const MyInt& integer) const;
        MyInt operator^(const MyInt& integer) const;
        MyInt operator<<(const MyInt& integer) const;
        MyInt operator>>(const MyInt& integer) const;

        bool operator==(const MyInt& integer) const;
        bool operator!=(const MyInt& integer) const;
        bool operator>(const MyInt& integer) const;
        bool operator<(const MyInt& integer) const;
        bool operator>=(const MyInt& integer) const;
        bool operator<=(const MyInt& integer) const;

    private:
        int32_t m_data;
        uint32_t m_demoCounter;
        const static uint64_t MaxOperationsAmount = 5;

        std::stringstream m_name;
        static uint64_t tmpCounter;

        std::ostream& m_log;
};
