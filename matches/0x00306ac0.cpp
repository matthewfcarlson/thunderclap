extern void* g_vt[];
extern void* g_vt2[];
void Free(void*) throw();
void Free2(void*) throw();
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec {
    Ref** b;
    Ref** e;
};
class A {
  public:
    void* vptr;
    char pad[0x14 - 4];
    Vec* v;
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    if (v) {
        for (unsigned i = 0; i < (unsigned)(v->e - v->b); i++)
            v->b[i]->Release();
        v->e = v->b;
        Vec* p = v;
        if (p) {
            p->e = p->b;
            if (p->b)
                Free2(p->b);
            Free(p);
        }
    }
    vptr = g_vt2;
}
