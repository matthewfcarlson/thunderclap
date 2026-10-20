class Obj_105060 {
  public:
    virtual void A();
    virtual void B();
};
extern void thunk(unsigned int);
extern void thunk2(void*);
extern void* g_vft_105060;
class Base_105060 {
  public:
    void* vptr;
    ~Base_105060() throw();
};
class CPathAgent : public Base_105060 {
  public:
    char pad[0x5c];
    Obj_105060* m60;
    Obj_105060* m64;
    char pad2[0x60];
    Obj_105060* mc8;
    ~CPathAgent() throw();
};
CPathAgent::~CPathAgent() throw() {
    *(void* volatile*)&vptr = &g_vft_105060;
    Obj_105060* q = *(Obj_105060* volatile*)&m60;
    if (q) {
        q->B();
        m60 = 0;
    }
    mc8->B();
    Obj_105060* p = m64;
    mc8 = 0;
    if (p) {
        thunk(*(unsigned int*)p);
        thunk(*(unsigned int*)((char*)p + 0xc));
        thunk2(p);
        m64 = 0;
    }
}
