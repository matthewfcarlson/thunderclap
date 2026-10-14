struct Ref_2b690 {
    virtual void x();
    virtual void Release(int);
    void Clear();
};
struct Ref0 {
    virtual void x();
    virtual void Release();
};
struct Elem_2b690 {
    void Fn();
};
struct T_2b690 {
    char p[4];
    Ref_2b690* r;
    Ref_2b690* q;
    char p2[0x338];
    Ref0* c;
    Ref0* d;
    char p3[0x904];
    void A();
    void init();
    void fini();
};
extern void __cdecl dispose(Ref_2b690*);
extern void globalf();
void T_2b690::A() {
    init();
    fini();
    Ref_2b690* z = q;
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
    Elem_2b690* e = (Elem_2b690*)((char*)this + 0xc50);
    for (int i = 0; i < 16; i++) {
        e = (Elem_2b690*)((char*)e - 0x68);
        ((Elem_2b690*)((char*)e + 8))->Fn();
        e->Fn();
    }
}
