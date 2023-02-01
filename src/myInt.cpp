#include "myInt.hpp"

uint64_t MyInt::tmpCounter = 0;

MyInt::MyInt(const int32_t integer, const std::string& name, std::ostream& stream) :
    m_data(integer),
    m_demoCounter(0),
    m_name(name),
    m_log(stream)
{
    if (m_name.str() == "") {
        m_name << "tmp" << tmpCounter++;
    }

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " created from int with value " << integer << std::endl;
#endif
}

MyInt::MyInt(const MyInt& intToCopy, const std::string& name) :
    m_data(intToCopy.m_data),
    m_demoCounter(0),
    m_name(name),
    m_log(intToCopy.m_log)
{
    if (m_name.str() == "") {
        m_name << "tmp" << tmpCounter++;
    }

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " created from another MyInt with value " << intToCopy.m_data << " and its name is " << intToCopy.m_name.str() << std::endl;
#endif
}

MyInt::operator int() const {
    return m_data;
}


MyInt& MyInt::operator=(const MyInt& intToEq) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data = intToEq.m_data;
    m_demoCounter = intToEq.m_demoCounter;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was equaled by " << intToEq.m_data << " using " << intToEq.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator+=(const MyInt& intToPlus) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data += intToPlus.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was increased by " << intToPlus.m_data << " using " << intToPlus.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator-=(const MyInt& intToSub) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data -= intToSub.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was decreased by " << intToSub.m_data << " using " << intToSub.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator*=(const MyInt& intToMul) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data *= intToMul.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was multiplied by " << intToMul.m_data << " using " << intToMul.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator/=(const MyInt& intToDiv) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data /= intToDiv.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was dived by " << intToDiv.m_data << " using " << intToDiv.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator%=(const MyInt& intToMod) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data %= intToMod.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was modded by " << intToMod.m_data << " using " << intToMod.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator&=(const MyInt& intToAnd) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data &= intToAnd.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was ANDed by " << intToAnd.m_data << " using " << intToAnd.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator|=(const MyInt& intToOr) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data |= intToOr.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was ORed by " << intToOr.m_data << " using " << intToOr.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator^=(const MyInt& intToXor) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data ^= intToXor.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was XORed by " << intToXor.m_data << " using " << intToXor.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator<<=(const MyInt& intToShl) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data <<= intToShl.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was SHLed by " << intToShl.m_data << " using " << intToShl.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator>>=(const MyInt& intToShr) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    m_data >>= intToShr.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was SHRed by " << intToShr.m_data << " using " << intToShr.m_name.str() << " var" << std::endl;
#endif

    return *this;
}

MyInt& MyInt::operator++() {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    ++m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was incremented (prefix)" << std::endl;
#endif

    return *this;
}

MyInt MyInt::operator++(int) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    MyInt tmp = *this;

    tmp.m_data++;

#ifdef INT_LOG
    m_log << "MyInt " << tmp.m_name.str() << " was incremented (postfix)" << std::endl;
#endif

    return tmp;
}


MyInt& MyInt::operator--() {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    --m_data;

#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " was decremented (prefix)" << std::endl;
#endif

    return *this;
}

MyInt MyInt::operator--(int) {
    if (m_demoCounter > MaxOperationsAmount) {
        m_log << "Operations amount is reached. Please buy license for MyInt called " << m_name.str() << " otherwise, operations on this integer won't be accepted" << std::endl;

        return *this;
    }
    else {
        m_demoCounter++;
    }

    MyInt tmp = *this;

    tmp.m_data--;

#ifdef INT_LOG
    m_log << "MyInt " << tmp.m_name.str() << " was decremented (postfix)" << std::endl;
#endif

    return tmp;
}


MyInt MyInt::operator!() const {
    MyInt tmp = *this;

    tmp.m_data = !tmp.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << tmp.m_name.str() << " was !ed" << std::endl;
#endif

    return tmp;
}

MyInt MyInt::operator~() const {
    MyInt tmp = *this;

    tmp.m_data = ~tmp.m_data;

#ifdef INT_LOG
    m_log << "MyInt " << tmp.m_name.str() << " was inversed" << std::endl;
#endif

    return tmp;
}


MyInt MyInt::operator+(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp += integer;

    return tmp;
}

MyInt MyInt::operator-(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp -= integer;

    return tmp;
}

MyInt MyInt::operator*(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp *= integer;

    return tmp;
}

MyInt MyInt::operator/(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp /= integer;

    return tmp;
}

MyInt MyInt::operator%(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp %= integer;

    return tmp;
}

MyInt MyInt::operator&(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp &= integer;

    return tmp;
}

MyInt MyInt::operator|(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp |= integer;

    return tmp;
}

MyInt MyInt::operator^(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp ^= integer;

    return tmp;
}

MyInt MyInt::operator<<(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp <<= integer;

    return tmp;
}

MyInt MyInt::operator>>(const MyInt& integer) const {
    MyInt tmp = *this;
    tmp >>= integer;

    return tmp;
}

bool MyInt::operator==(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(==) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data == integer.m_data;
}

bool MyInt::operator!=(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(!=) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data != integer.m_data;
}

bool MyInt::operator>(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(>) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data >  integer.m_data;
}

bool MyInt::operator<(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(<) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data <  integer.m_data;
}

bool MyInt::operator>=(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(>=) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data >=  integer.m_data;
}

bool MyInt::operator<=(const MyInt& integer) const {
#ifdef INT_LOG
    m_log << "MyInt " << m_name.str() << " comapring(<=) with MyInt " << integer.m_name.str() << std::endl;
#endif

    return m_data <=  integer.m_data;
}



