typedef unsigned char u8;
typedef unsigned short u16;
extern void __stdcall FUN_00355364(void*);
void target(u16* param_1) {
    u8 local[12];
    FUN_00355364(local);
    u8* dst = (u8*)param_1;
    *(u16*)dst = *(u16*)local;
    dst[2] = local[2];
    dst[3] = local[6];
    dst[4] = local[8];
    dst[5] = local[10];
    dst[6] = local[12];
}