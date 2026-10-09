struct Helper {
    Helper* f592a0();
    Helper* f59a30();
    void f35ef0(int);
    void f27ffb0(int);
};
extern Helper* __cdecl f27f250();
class A {
  public:
    char pad[0x48];
    void vfunc_4();
};
void A::vfunc_4() {
    Helper* x = ((Helper*)*(void**)(pad + 0x20))->f592a0();
    x = x->f59a30();
    x->f35ef0(*(int*)(*(char**)(pad + 0x1c) + 0x14));
    x = f27f250();
    x->f27ffb0(*(int*)(pad + 0x44));
}