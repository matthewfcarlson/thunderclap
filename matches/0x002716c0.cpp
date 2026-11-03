typedef unsigned int uint_2716c0;
typedef unsigned char byte_2716c0;
bool FUN_002716c0(byte_2716c0* src, unsigned int* length, uint_2716c0* codepoint) {
    if (*src & 0x80)
        return false;
    if (length != 0)
        *length = 1;
    if (codepoint != 0)
        *codepoint = (uint_2716c0)((int)(signed char)*src & 0xff);
    return true;
}
