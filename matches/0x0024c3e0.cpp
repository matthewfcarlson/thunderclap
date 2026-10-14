typedef unsigned int uint_24c3e0;
extern int DAT_004cc258[16];
uint_24c3e0 __cdecl FUN_0024c3e0(uint_24c3e0* param_1, uint_24c3e0 param_2) {
    return param_2 / (((*param_1 >> 4) & 0x1f) * DAT_004cc258[((int)(*param_1 << 0x1c) >> 0x1c) * 6]);
}