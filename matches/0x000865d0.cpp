struct A_865d0 {
    void f2();
    void f4();
    void f6(int);
    void f7();
    void f8(void*, int);
};
struct B_865d0 {
    void f3(int);
};
struct C_865d0 {
    void f5();
};
extern unsigned char flag_865d0;
struct Obj_865d0 {
    char pad0[4];
    int v4;
    char pad8[0x18];
    A_865d0* p20;
    char pad24[0xc];
    C_865d0* p30;
    char pad34[4];
    B_865d0* p38;
    A_865d0* init();
};
void __fastcall target(Obj_865d0* self) {
    A_865d0* edi = self->init();
    if (!flag_865d0)
        edi->f2();
    else
        flag_865d0 = 0;
    self->p38->f3(0);
    edi->f4();
    self->p30->f5();
    edi->f6(1);
    edi->f7();
    self->p20->f8(self, self->v4);
}