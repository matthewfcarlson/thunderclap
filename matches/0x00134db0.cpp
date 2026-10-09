class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
void BaseCtor();
extern int hoverVftable;
class HoverAction {
  public:
    virtual void V();
    char pad[0x18];
    int field1c;
    Ref* field20;
    HoverAction* Init(int a, Ref* r);
};
HoverAction* HoverAction::Init(int a, Ref* r) {
    BaseCtor();
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