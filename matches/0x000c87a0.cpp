extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct T1 {
    char c;
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad4[0xc];
    Ref* m10;
    Ref* m14;
    Ref* m18;
    Ref* m1c;
    char pad20[0x22c - 0x20];
    Ref* m22c[10];
    ~Obj() throw();
};
Obj::~Obj() throw() {
    *(void* volatile*)&vptr = g_vftable;
    Ref* t10 = *(Ref* volatile*)&m10;
    if (t10) {
        t10->Release();
        m10 = 0;
    }
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Ref** p = m22c;
    int n = 10;
    do {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        p++;
    } while (--n);
    char* q = (char*)this + 0x2968;
    n = 32;
    do {
        q -= 0x38;
        ((T1*)q)->Fini();
    } while (--n);
    q = (char*)this + 0x2280;
    n = 128;
    do {
        q -= 0x40;
        ((T1*)q)->Fini();
    } while (--n);
    Fin();
}
