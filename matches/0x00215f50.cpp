extern "C" unsigned int FUN_00215f50(unsigned int value) {
    unsigned int exponent = 0;
    if (value >= 8) {
        do {
            value = (value + 1) >> 1;
            ++exponent;
        } while (value >= 8);
    }
    return (exponent << 3) | value;
}