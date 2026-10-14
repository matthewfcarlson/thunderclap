extern void* g_vA[];
class Ref_32d0f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_32d0f0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_32d0f0 : public Base_32d0f0 {
  public:
    char pad[0x80 - 4];
    Ref_32d0f0* m80;
    ~Obj_32d0f0() throw();
};
Obj_32d0f0::~Obj_32d0f0() throw() {
    Ref_32d0f0* a = m80;
    vptr = g_vA;
    if (a)
        a->Release();
    Fin();
}
