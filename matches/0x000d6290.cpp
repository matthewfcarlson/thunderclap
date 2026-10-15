struct MessageOverlay;
extern unsigned char __cdecl FUN_001d04d0(const void*);
extern int g1, g2;
struct Base {
    virtual void f();
    Base(void*, int);
};
struct Method1 : Base {
    char pad[0xc];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    void* p;
    Method1(void*, void*);
    virtual void f();
};
struct Closure1 : Method1 {
    void* q;
    Closure1(void*, void*, void*);
    virtual void f();
};
inline Method1::Method1(void* x, void* y) : Base(x, 1) {
    p = y;
    a = FUN_001d04d0(&g1);
    b = FUN_001d04d0(&g2);
}
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}
