struct Converter {
    unsigned char FUN_001d2d40(unsigned int, float*);
    unsigned char FUN_001d2da0(unsigned int value, int* result);
};
unsigned char Converter::FUN_001d2da0(unsigned int value, int* result) {
    float number;
    unsigned char ok = FUN_001d2d40(value, &number);
    if (ok)
        *result = (int)(number + 0.5f);
    return ok;
}