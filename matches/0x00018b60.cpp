extern "C" void _ReadWriteBarrier();
extern void* gA_18b60[];
class Ref_18b60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_18b60 {
  public:
    void* vptr;
    void Fin();
};
class CAction_18b60 : public Action_18b60 {
  public:
    char pad[0x1c - 4];
    Ref_18b60* m1c;
    ~CAction_18b60();
};
CAction_18b60::~CAction_18b60() {
    vptr = gA_18b60;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
