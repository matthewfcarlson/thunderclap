extern "C" void _ReadWriteBarrier();
extern void* g_vftable_287f40[];
void operator delete(void*);
void operator delete[](void*);
class Ref_287f40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_287f40 {
  public:
    void* vptr;
    void Fin();
};
class Obj_287f40 : public Base_287f40 {
  public:
    char pad[0x10c];
    Ref_287f40* m110;
    char pad2[4];
    int m118;
    void* m11c;
    int m120;
    int m124;
    int m128;
    int m12c;
    char pad3[4];
    void* m134;
    ~Obj_287f40() throw();
};
Obj_287f40::~Obj_287f40() throw() {
    vptr = g_vftable_287f40;
    _ReadWriteBarrier();
    if (m110) {
        m110->Release();
        m110 = 0;
    }
    m118 = 0;
    if (m11c) {
        operator delete(m11c);
        m11c = 0;
        m120 = 0;
        m124 = 0;
        m128 = 0;
        m12c = 0;
    }
    if (m134)
        operator delete(m134);
    Fin();
}
