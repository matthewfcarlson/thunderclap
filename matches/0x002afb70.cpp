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
    char pad[0xc];
    void* m10;
    void* m14;
    void* m18;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;

    operator delete(m14);
    operator delete(m18);
    Fin();
}
