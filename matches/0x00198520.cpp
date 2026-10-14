extern "C" void _ReadWriteBarrier();
extern void* g_vftable_198520[];
class Ref_198520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_198520 {
  public:
    void* vptr;
    void Fin();
};
class Obj_198520 : public Base_198520 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_198520* m20;
    ~Obj_198520();
};
Obj_198520::~Obj_198520() {
    vptr = g_vftable_198520;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
