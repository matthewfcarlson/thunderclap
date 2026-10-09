typedef unsigned int uint;
typedef unsigned char BOOL;
BOOL FUN_00272070(uint *param_1, uint *param_2, uint *param_3)
{
    uint value = *param_1;
    if (value >= 0xd800 && value <= 0xdfff)
        return 0;
    if (param_2 != 0)
        *param_2 = 4;
    if (param_3 != 0)
        *param_3 = value;
    return 1;
}