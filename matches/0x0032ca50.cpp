extern "C" void _ReadWriteBarrier();
extern void* g_vftable_32ca50[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_32ca50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_32ca50 {
  public:
    void* vptr;
    void Fin();
};

class Obj_32ca50 : public Base_32ca50 {
  public:
    char pad[0x7c];
    Ref_32ca50* m80;
    Ref_32ca50* m84;
    ~Obj_32ca50();
};
Obj_32ca50::~Obj_32ca50() {
    Ref_32ca50* a = m80;
    vptr = g_vftable_32ca50;
    if (a)
        a->Release();
    if (m84)
        m84->Release();
    Fin();
}
