#include <iostream>

void reverse(char* str) {
    char* end = str;
    char tmp;
    if (str) {
        while (*end) {
            ++end;
        }
        --end;
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
    std::cout << str << std::endl;
}

int main() {
    char* str = "abc";
    reverse(str);
}