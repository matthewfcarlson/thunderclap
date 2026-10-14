typedef unsigned short u16_307030;
extern u16_307030* DAT_0055543c;
extern u16_307030* DAT_00555440;
void __cdecl FUN_00307030(u16_307030 param_1) {
    if (*DAT_0055543c < 0x400) {
        DAT_00555440[*DAT_0055543c] = param_1;
        ++*DAT_0055543c;
    }
}