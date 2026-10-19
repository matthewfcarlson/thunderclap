class Ref_134db0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct ThisCall_00232660 {
    void BaseCtor();
};
extern int hoverVftable;
class HoverAction {
  public:
    virtual void V();
    char pad[0x18];
    int field1c;
    Ref_134db0* field20;
    HoverAction* Init(int a, Ref_134db0* r);
};
HoverAction* HoverAction::Init(int a, Ref_134db0* r) {
    ((ThisCall_00232660*)(this))->BaseCtor();
    *(int*)this = (int)&hoverVftable;
    field1c = a;
    field20 = 0;
    if (r)
        r->AddRef();
    if (field20)
        field20->Release();
    field20 = r;
    return this;
}