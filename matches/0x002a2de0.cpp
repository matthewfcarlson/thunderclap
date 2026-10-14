extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a2de0[];
void operator delete(void*);
class Base_2a2de0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2a2de0 : public Base_2a2de0 {
  public:
    char pad[0x1c];
    void* m20;
    char pad2[8];
    void* m2c;
    ~Obj_2a2de0();
};
Obj_2a2de0::~Obj_2a2de0() {
    vptr = g_vftable_2a2de0;
    _ReadWriteBarrier();
    if (m2c)
        operator delete(m2c);
    if (m20)
        operator delete(m20);
    Fin();
}
