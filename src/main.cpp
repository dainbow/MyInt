#include "main.hpp"

template <class T>
uint64_t Microscope<T>::tmpCounter = 0;

template <class T>
const std::string Microscope<T>::m_typename = typeid(T).name();

int main() {
    Visualiser::GetInstance();

    Execute();

    Visualiser::RemoveInstance();
}

void Execute() {
    LOG_FUNC;

    MYINT_DEF(a, 3);
    MYINT_DEF(b, 6);

    MYINT_DEF(c, a + b);
}
