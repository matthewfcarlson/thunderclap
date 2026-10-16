extern "C" volatile char gDrive[];
extern "C" void FUN_00277190(char* p) {
    unsigned short v = *(volatile unsigned short*)gDrive;
    *(unsigned short*)p = v;
    p[2] = gDrive[2];
}