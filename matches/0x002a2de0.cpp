extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x1c];
    void* m20;
    char pad2[8];
    void* m2c;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m2c)
        operator delete(m2c);
    if (m20)
        operator delete(m20);
    Fin();
}
