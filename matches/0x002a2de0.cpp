extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a2de0[];
void operator delete(void*);
class DisplayTraversal_2a2de0 {
  public:
    void* vptr;
    void Fin();
};
class OpaqueTraversal_2a2de0 : public DisplayTraversal_2a2de0 {
  public:
    char pad[0x1c];
    void* m20;
    char pad2[8];
    void* m2c;
    ~OpaqueTraversal_2a2de0();
};
OpaqueTraversal_2a2de0::~OpaqueTraversal_2a2de0() {
    vptr = g_vftable_2a2de0;
    _ReadWriteBarrier();
    if (m2c)
        operator delete(m2c);
    if (m20)
        operator delete(m20);
    Fin();
}
