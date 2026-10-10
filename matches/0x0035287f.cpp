// cl-flags: /O1
extern "C" int __cdecl FUN_00347ba4();
int __cdecl FUN_0035287f(unsigned char* p, unsigned short v) {
    bool r = false;
    if (!p)
        return 0;
    if (v > 0xff) {
        int* q = (int*)FUN_00347ba4();
        *q = 0x2a;
        return -1;
    }
    r = true;
    *p = (unsigned char)v;
    return r;
}
