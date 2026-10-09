typedef unsigned int uint;
extern int DAT_004cc258[16];
uint __cdecl FUN_0024c3e0(uint* param_1, uint param_2) {
    return param_2 / (((*param_1 >> 4) & 0x1f) * DAT_004cc258[((int)(*param_1 << 0x1c) >> 0x1c) * 6]);
}