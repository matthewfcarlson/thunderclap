extern "C" char DAT_003f3390[];
extern "C" char DAT_003f33b8[];
class Ref_18b90 {
  public:
    virtual void AddRef();
    virtual void Release();
};
void BaseInit();
class CJointAction {
  public:
    virtual void V();
    char pad[0x18];
    Ref_18b90* ref;
    int value;
    int extra;
    CJointAction* Init(int, Ref_18b90*);
};
CJointAction* CJointAction::Init(int v, Ref_18b90* r) {
    BaseInit();
    *(int*)this = ((int)DAT_003f3390);
    ref = 0;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    value = v;
    *(int*)this = ((int)DAT_003f33b8);
    extra = 0;
    return this;
}