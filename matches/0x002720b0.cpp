typedef unsigned int uint;
int __cdecl FUN_002720b0(uint value, uint* outValue, uint size, uint unused, uint* outSize) {
    if (size < 4)
        return -1;
    if (value >= 0xd800 && value <= 0xdfff)
        return -2;
    *outValue = value;
    *outSize = 4;
    return 0;
}