extern void* __cdecl alloc(unsigned int);
inline void* operator new(unsigned int, void* where) {
    return where;
}

class Base {
  public:
    Base(void* parent);
    virtual void b0();
    char pad[0x3c];
};

class EAC : public Base {
  public:
    EAC(void* parent) : Base(parent) {
        m[0] = 0;
        m[1] = 0;
        m[2] = 0;
        m[3] = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual EAC* f4();
    void g(int v);
    int m[4];
};

EAC* EAC::f4() {
    EAC* p = (EAC*)alloc(0x50);
    EAC* z = 0;
    if (p != z) {
        new (p) EAC(this);
        p->g(m[0]);
        return p;
    }
    return z;
}
