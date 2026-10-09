typedef unsigned int uint;
struct XboxSaveDrive {
    int v0();
    int v1();
    int v2();
    int v3();
    int v4();
    int vfunc_5(int*, int);
};
extern int __cdecl FUN_0026fd50(int, int);
int XboxSaveDrive::vfunc_5(int* param2, int param3) {
    int base = param3;
    uint q = (uint)(base + 0x1fef) / 0x1fec;
    int* p = (int*)((char*)base + q * 20 + 4);
    int r = FUN_0026fd50((int)p, 0x4000);
    r += 0x8000;
    if (*param2)
        r += 0x4000;
    return r;
}