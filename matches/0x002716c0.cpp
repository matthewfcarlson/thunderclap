typedef unsigned int uint_2716c0;
typedef unsigned char byte_2716c0;
bool FUN_002716c0(byte_2716c0* param_1, unsigned int* param_2, uint_2716c0* param_3) {
    if (*param_1 & 0x80)
        return false;
    if (param_2 != 0)
        *param_2 = 1;
    if (param_3 != 0)
        *param_3 = (uint_2716c0)((int)(signed char)*param_1 & 0xff);
    return true;
}
