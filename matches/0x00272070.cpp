typedef unsigned int uint_272070;
typedef unsigned char BOOL;
BOOL FUN_00272070(uint_272070* param_1, uint_272070* param_2, uint_272070* param_3) {
    uint_272070 value = *param_1;
    if (value >= 0xd800 && value <= 0xdfff)
        return 0;
    if (param_2 != 0)
        *param_2 = 4;
    if (param_3 != 0)
        *param_3 = value;
    return 1;
}