typedef unsigned int U;
typedef unsigned char B;
struct Obj {
    void A(U* p);
    void B(U* p);
};
extern Obj* __cdecl FUN_001c3d90(void);
void __stdcall FUN_00099d60(U a, U b, U c, U d, B flag) {
    U x[7];
    x[0] = a;
    x[1] = b;
    x[2] = c;
    x[3] = a;
    x[4] = b;
    x[5] = c;
    x[6] = d;
    Obj* o = FUN_001c3d90();
    if (flag)
        o->A(&x[3]);
    else
        o->B(&x[3]);
}
