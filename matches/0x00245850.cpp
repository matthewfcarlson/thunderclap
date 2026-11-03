int FUN_00245850(char* digits, int length) {
    int value = 0;
    int place = 1;
    char* p;
    for (p = digits + length - 1; p >= digits; --p) {
        value += (*p - 0x30) * place;
        place *= 10;
    }
    return value;
}