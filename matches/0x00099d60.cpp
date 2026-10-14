typedef unsigned int U_99d60;
typedef unsigned char B;
struct Obj_99d60 {
    void A(U_99d60* p);
    void B(U_99d60* p);
};
extern Obj_99d60* __cdecl FUN_001c3d90(void);
void __stdcall FUN_00099d60(U_99d60 a, U_99d60 b, U_99d60 c, U_99d60 d, B flag) {
    U_99d60 x[7];
    x[0] = a;
    x[1] = b;
    x[2] = c;
    x[3] = a;
    x[4] = b;
    x[5] = c;
    x[6] = d;
    Obj_99d60* o = FUN_001c3d90();
    if (flag)
        o->A(&x[3]);
    else
        o->B(&x[3]);
}
