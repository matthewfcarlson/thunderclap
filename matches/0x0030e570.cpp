extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
class Sub {
  public:
    void Fini();
};
struct E1 {
    char pad[0x10];
    Sub* s;
};
struct E2 {
    char pad[0xa4];
    void Fini();
};
class Obj {
  public:
    void* vptr;
    E1* m4;
    E1* m8;
    char pad[8];
    void* m14;
    void* m18;
    char pad2[8];
    void* m24;
    void* m28;
    char pad3[8];
    E2* m34;
    E2* m38;
    char pad4[8];
    void* m44;
    void* m48;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    E1* p = m4;
    if (p <= m8) {
        E1* c;
        do {
            p->s->Fini();
            c = p;
            p++;
        } while (c != m8);
    }
    m48 = m44;
    if (m44)
        operator delete(m44);
    E2* e = m38;
    for (E2* q = m34; q != e; q++)
        q->Fini();
    m38 = m34;
    if (m34)
        operator delete(m34);
    m28 = m24;
    if (m24)
        operator delete(m24);
    m18 = m14;
    if (m14)
        operator delete(m14);
}
