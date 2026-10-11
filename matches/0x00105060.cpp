class Obj {
  public:
    virtual void A();
    virtual void B();
};
extern void thunk(unsigned int);
extern void thunk2(void*);
extern void* g_vft;
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class CPathAgent : public Base {
  public:
    char pad[0x5c];
    Obj* m60;
    Obj* m64;
    char pad2[0x60];
    Obj* mc8;
    ~CPathAgent() throw();
};
CPathAgent::~CPathAgent() throw() {
    *(void* volatile*)&vptr = &g_vft;
    Obj* q = *(Obj* volatile*)&m60;
    if (q) {
        q->B();
        m60 = 0;
    }
    mc8->B();
    Obj* p = m64;
    mc8 = 0;
    if (p) {
        thunk(*(unsigned int*)p);
        thunk(*(unsigned int*)((char*)p + 0xc));
        thunk2(p);
        m64 = 0;
    }
}
