extern int g1;
extern int g2;
extern int g3;
struct Helper {
    void init(int);
};
extern void __cdecl f2(int);
extern void __cdecl f3();
extern void __cdecl f4(int, int, int);
struct Obj {
    char pad[8];
    int field;
};
void __fastcall target(Obj* self) {
    if (g1 == 0) {
        g1 = g2;
        ((Helper*)g2)->init(0x40000000);
    }
    if (self->field == 0)
        self->field = g3;
    f2(1);
    f3();
    f4(0x14, 0x19, 500);
}