extern int __stdcall XCalculateSignatureBegin(int);
extern void __stdcall FUN_002120f5(int, int, int);
extern void __stdcall FUN_00212143(int, int);
extern volatile int DAT_0052c278;
extern volatile int DAT_0052c270;
bool Target(unsigned int size, int arg) {
    int base = DAT_0052c278;
    base = base << 13;
    unsigned int limit = base + 0x2000;
    if (limit >= size) {
    } else {
    }
    if (!(limit < size))
        limit = size;
    int buf = DAT_0052c270;
    int sig = XCalculateSignatureBegin(0);
    if (sig == -1)
        return false;
    FUN_002120f5(sig, buf, limit - base - 0x14);
    FUN_00212143(sig, arg);
    return true;
}
