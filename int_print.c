#include <unistd.h>

void printInteger(int num) {

    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    char buffer[20];
    int index = 0;
    if (num == 0) {
        buffer[index++] = '0';
    }
    while (num > 0) {
        int digit = num % 10;
        buffer[index++] = '0' + digit;
        num /= 10;
    }
    for (int i = 0; i < index / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[index - 1 - i];
        buffer[index - 1 - i] = temp;
    }
    write(1, buffer, index);
}
