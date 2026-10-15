extern int gCount;
extern int gValues[8];
extern unsigned char gReady;
void FUN_0035a660() {
    gCount = 0x45;
    for (int i = 0; i < 8; ++i)
        gValues[i] = 0;
    gReady = 1;
}