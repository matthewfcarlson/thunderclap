typedef unsigned char u8_38e30;
extern u8_38e30 __cdecl FUN_002029e0(int, int, int, int, int, int);
struct Obj_38e30 {
    void Gate(int);
    u8_38e30 Run(int a, int b, int c, int d, int e, int f);
};
u8_38e30 Obj_38e30::Run(int a, int b, int c, int d, int e, int f) {
    Gate(0);
    u8_38e30 r = FUN_002029e0(a, b, c, d, e, f);
    Gate(1);
    return r;
}