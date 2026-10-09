extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern unsigned int DAT_004dd7e0;
void FUN_0008e090() {
    if (DAT_004dd7e0 == 0) {
        char* p = (char*)FUN_0008d690(0xc);
        if (p != 0) {
            p[5] = 0;
            p[6] = 0;
            p[7] = 0;
            p[4] = 0;
            p[8] = 0;
            p[9] = 0;
            *(unsigned int*)p = 0x400870;
        } else {
            p = 0;
        }
        DAT_004dd7e0 = (unsigned int)p;
    }
}
