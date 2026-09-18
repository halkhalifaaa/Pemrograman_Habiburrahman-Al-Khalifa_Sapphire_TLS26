#include <iostream>

int hitungPanjang(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int nilaiAlfabet(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0;
}

char nilaiKeHuruf(int val, bool isUpper) {
    if (isUpper) {
        return (char)('A' + val - 1);
    } else {
        return (char)('a' + val - 1);
    }
}

void enkripsiAlien(const char input[], char output[]) {
    int len = hitungPanjang(input);
    if (len == 0) {
        output[0] = '\0';
        return;
    }

    output[0] = input[0];

    for (int i = 1; i < len; i++) {
        bool isUpper = (input[i] >= 'A' && input[i] <= 'Z');
        bool isLower = (input[i] >= 'a' && input[i] <= 'z');

        if (isUpper || isLower) {
            int posSekarang = nilaiAlfabet(input[i]);
            int posSebelum  = nilaiAlfabet(input[i - 1]);

            int posBaru = posSekarang + posSebelum;

            while (posBaru > 26) {
                posBaru -= 26;
            }

            output[i] = nilaiKeHuruf(posBaru, isUpper);
        } else {
            output[i] = input[i];
        }
    }

    output[len] = '\0';
}

int main() {
    char input[1000];
    char output[1000];

    std::cout << "Mau Ngomong Apa: ";
    if (std::cin >> input) {
        enkripsiAlien(input, output);
        std::cout << "Mereka Ga Tau    : " << output << std::endl;
    }

    return 0;
}
