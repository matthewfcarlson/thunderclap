extern int g1_1b3fc0;
extern int g2_1b3fc0;
extern int g3_1b3fc0;
struct Helper_1b3fc0 {
    void init(int);
};
extern void __cdecl f2(int);
extern void __cdecl f3();
extern void __cdecl f4(int, int, int);
struct Obj_1b3fc0 {
    char pad[8];
    int field;
};
void __fastcall target(Obj_1b3fc0* self) {
    if (g1_1b3fc0 == 0) {
        g1_1b3fc0 = g2_1b3fc0;
        ((Helper_1b3fc0*)g2_1b3fc0)->init(0x40000000);
    }
    if (self->field == 0)
        self->field = g3_1b3fc0;
    f2(1);
    f3();
    f4(0x14, 0x19, 500);
}