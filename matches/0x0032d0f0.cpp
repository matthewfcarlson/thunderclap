extern void* g_vA[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x80 - 4];
    Ref* m80;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    Ref* a = m80;
    vptr = g_vA;
    if (a)
        a->Release();
    Fin();
}
