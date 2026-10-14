typedef unsigned int uint_2720b0;
int __cdecl FUN_002720b0(uint_2720b0 value, uint_2720b0* outValue, uint_2720b0 size, uint_2720b0 unused, uint_2720b0* outSize) {
    if (size < 4)
        return -1;
    if (value >= 0xd800 && value <= 0xdfff)
        return -2;
    *outValue = value;
    *outSize = 4;
    return 0;
}