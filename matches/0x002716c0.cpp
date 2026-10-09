typedef unsigned int uint;
typedef unsigned char byte;
bool FUN_002716c0(byte* param_1, unsigned int* param_2, uint* param_3) {
    if (*param_1 & 0x80)
        return false;
    if (param_2 != 0)
        *param_2 = 1;
    if (param_3 != 0)
        *param_3 = (uint)((int)(signed char)*param_1 & 0xff);
    return true;
}
