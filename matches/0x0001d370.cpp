extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1d370[];
class Ref_1d370 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1d370 {
  public:
    void* vptr;
    void Fin();
};
class CAction_1d370 : public Action_1d370 {
  public:
    char pad[24];
    Ref_1d370* m;
    ~CAction_1d370();
};
CAction_1d370::~CAction_1d370() {
    vptr = g_vftable_1d370;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
