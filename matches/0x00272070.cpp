typedef unsigned int uint_272070;
typedef unsigned char BOOL;
extern "C" BOOL FUN_00272070(uint_272070* src, uint_272070* length, uint_272070* codepoint) {
    uint_272070 value = *src;
    if (value >= 0xd800 && value <= 0xdfff)
        return 0;
    if (length != 0)
        *length = 4;
    if (codepoint != 0)
        *codepoint = value;
    return 1;
}