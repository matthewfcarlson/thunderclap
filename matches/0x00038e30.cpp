typedef unsigned char u8;
extern u8 __cdecl FUN_002029e0(int, int, int, int, int, int);
struct Obj {
    void Gate(int);
    u8 Run(int a, int b, int c, int d, int e, int f);
};
u8 Obj::Run(int a, int b, int c, int d, int e, int f) {
    Gate(0);
    u8 r = FUN_002029e0(a, b, c, d, e, f);
    Gate(1);
    return r;
}