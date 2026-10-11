extern "C" void _ReadWriteBarrier();
extern void* g_vF[];
extern void* g_vS[];
extern void* g_vC[];
void operator delete(void*);
void operator delete[](void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Obj {
  public:
    void* vptr;
    char pad[8];
    Ref* m0c;
    char pad2[4];
    void* m14;
    void* m18;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vF;
    if (!m0c)
        operator delete(m18);
    m18 = 0;
    if (!m0c) {
        operator delete(m14);
    } else {
        _ReadWriteBarrier();
        if (m0c) {
            m0c->Release();
            m0c = 0;
        }
    }
    m14 = 0;
    vptr = g_vS;
    if (!m0c) {
        operator delete(m14);
        m14 = 0;
    } else {
        _ReadWriteBarrier();
        if (m0c) {
            m0c->Release();
            m0c = 0;
        }
        m14 = 0;
    }
    vptr = g_vC;
}
