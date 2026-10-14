typedef unsigned int U_327800;
extern int vtd[], vtp[];
class pddiPrimBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class d3dPrimBuffer : public pddiPrimBuffer {
  public:
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    char pad[0x28];
    U_327800 a;
    U_327800 b;
    void cleanup();
    d3dPrimBuffer* f3(unsigned char);
};
extern void __cdecl helper(U_327800);
extern void __stdcall release(U_327800);
extern void __cdecl destroy(d3dPrimBuffer*);
d3dPrimBuffer* d3dPrimBuffer::f3(unsigned char flag) {
    *(int**)this = vtd;
    if (a) {
        helper(a);
        release(a);
    }
    if (b) {
        helper(b);
        release(b);
    }
    *(int**)this = vtp;
    cleanup();
    if (flag & 1)
        destroy(this);
    return this;
}