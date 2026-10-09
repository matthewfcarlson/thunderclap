struct A {
    void f2();
    void f4();
    void f6(int);
    void f7();
    void f8(void*, int);
};
struct B {
    void f3(int);
};
struct C {
    void f5();
};
extern unsigned char flag;
struct Obj {
    char pad0[4];
    int v4;
    char pad8[0x18];
    A* p20;
    char pad24[0xc];
    C* p30;
    char pad34[4];
    B* p38;
    A* init();
};
void __fastcall target(Obj* self) {
    A* edi = self->init();
    if (!flag)
        edi->f2();
    else
        flag = 0;
    self->p38->f3(0);
    edi->f4();
    self->p30->f5();
    edi->f6(1);
    edi->f7();
    self->p20->f8(self, self->v4);
}