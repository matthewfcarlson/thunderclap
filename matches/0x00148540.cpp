extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_148540 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_148540 {
  public:
    void* vptr;
    void Fin();
};
class GrappleStruggleAction_148540 : public Action_148540 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_148540* m20;
    ~GrappleStruggleAction_148540() throw();
};
GrappleStruggleAction_148540::~GrappleStruggleAction_148540() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
