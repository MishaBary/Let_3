#include <iostream>
#include "math.h"



long x_16( char *hex ) {
    long answer = 0;
    int hex_size = 0;
    while (hex[hex_size] != '\0') {
        hex_size++;
    }
    if (hex[0] == '0' && hex[1] == 'x' ) {

        for (long i = 2; i < hex_size; i++) {
            if ((long) (hex[i]) < 64) answer = answer + (((long) (hex[i]) - 48) * pow(16, (hex_size - i - 1)));
            else if ((long) (hex[i]) < 90) answer = answer + (((long) (hex[i]) - 55) * pow(16, (hex_size - i - 1)));
            else answer = answer + (((long) (hex[i]) - 87) * pow(16, (hex_size - i - 1)));
        }
    } else if (hex[0] == '+' && hex[1] == '0') {
        for (long i = 3; i < hex_size; i++) {
            if ((long) (hex[i]) < 64) answer = answer + (((long) (hex[i]) - 48) * pow(16, (hex_size - i - 1)));
            else if ((long) (hex[i]) < 90) answer = answer + (((long) (hex[i]) - 55) * pow(16, (hex_size - i - 1)));
            else answer = answer + (((long) (hex[i]) - 87) * pow(16, (hex_size - i - 1)));
        }
    } else if (hex[0] == '-' && hex[1] == '0') {
        for (long i = 3; i < hex_size; i++) {
            if ((long) (hex[i]) < 64) answer = answer + (((long) (hex[i]) - 48) * pow(16, (hex_size - i - 1)));
            else if ((long) (hex[i]) < 90) answer = answer + (((long) (hex[i]) - 55) * pow(16, (hex_size - i - 1)));
            else answer = answer + (((long) (hex[i]) - 87) * pow(16, (hex_size - i - 1)));
        }
        answer *= (-1);
    } else std::cout << " ошибка ввода " << std::endl;

    return answer;
}

int main(int argc, char *argv[]) {
    long journal_variant = 108;

    for(int i = argc - 1; i>0; i-- ) {
        std::cout  << x_16(argv[i]) + journal_variant  << std::endl;
    }
    return 0;
}
