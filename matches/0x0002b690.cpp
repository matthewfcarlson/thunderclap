struct Ref {
    virtual void x();
    virtual void Release(int);
    void Clear();
};
struct Ref0 {
    virtual void x();
    virtual void Release();
};
struct Elem {
    void Fn();
};
struct T {
    char p[4];
    Ref* r;
    Ref* q;
    char p2[0x338];
    Ref0* c;
    Ref0* d;
    char p3[0x904];
    void A();
    void init();
    void fini();
};
extern void __cdecl dispose(Ref*);
extern void globalf();
void T::A() {
    init();
    fini();
    Ref* z = q;
    if (z) {
        z->Clear();
        dispose(z);
    }
    if (r)
        r->Release(1);
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    globalf();
    Elem* e = (Elem*)((char*)this + 0xc50);
    for (int i = 0; i < 16; i++) {
        e = (Elem*)((char*)e - 0x68);
        ((Elem*)((char*)e + 8))->Fn();
        e->Fn();
    }
}
