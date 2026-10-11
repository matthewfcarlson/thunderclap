extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
void operator delete(void*);
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
    char pad[0x7c];
    Ref* m80;
    Ref* m84;
    ~Obj();
};
Obj::~Obj() {
    Ref* a = m80;
    vptr = g_vftable;
    if (a)
        a->Release();
    if (m84)
        m84->Release();
    Fin();
}
