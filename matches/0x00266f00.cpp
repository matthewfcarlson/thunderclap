struct C_266f00 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
};
struct S_266f00 {
    C_266f00* p;
    char pad[12];
};
extern S_266f00 g_266f00[];
int __cdecl target(int a, int b) {
    return g_266f00[a].p->f4(b);
}