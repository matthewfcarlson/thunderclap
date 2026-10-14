extern "C" char DAT_00411dc4[];
struct Ref_135470 {
    virtual void AddRef();
    virtual void Release();
};
void BaseCtor();
class FlyingAttackAction {
  public:
    void* volatile vft;
    char pad04[0x18];
    void* volatile arg;
    Ref_135470* ref;
    int x24;
    int x28;
    int x2c;
    int x30;
    int x34;
    int x38;
    FlyingAttackAction* Run(void*, Ref_135470*);
};
FlyingAttackAction* FlyingAttackAction::Run(void* a, Ref_135470* r) {
    BaseCtor();
    vft = (void*)((int)DAT_00411dc4);
    arg = 0;
    ref = 0;
    x24 = 0;
    x28 = 0;
    x2c = 0;
    x30 = 0;
    x34 = 0;
    x38 = 0;
    arg = a;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    return this;
}