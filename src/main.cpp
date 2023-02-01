#include "main.hpp"

#define MYINT_DEF(name, value) MyInt name = MyInt(value, #name)

int main() {
    MyInt array[] = {12, 82, 87, 75, 99, 21, 76, 2, 24, 4, 58, 48, 39, 17, 84};

    SortBubbleFirst(array, sizeof(array) / sizeof(MyInt), 0);

    for (auto& it : array) {
        std::cout << int(it) << " ";
    }
    std::cout << std::endl;
}

void SwapMyInt(MyInt* int1, MyInt* int2) {
    MYINT_DEF(newInt1, *int1);
    MYINT_DEF(newInt2, *int2);

    *int1 = newInt2;
    *int2 = newInt1;
}

void SortBubbleFirst(MyInt* array, const MyInt size, const MyInt curElem) {
    if (size == MyInt(0)) {
        return;
    }

    if (curElem < size) {
        if (array[(int)curElem] < *array) {
            SwapMyInt(array, array + (int)curElem);
        }

        SortBubbleFirst(array, size, curElem + MyInt(1));
    }

    if (curElem == MyInt(0)) {
        SortBubbleFirst(array + 1, size - MyInt(1), curElem);
    }
}
