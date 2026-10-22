class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct Source {
    char pad[0x20];
    int value;
};
class Action_1847e0 {
  public:
    virtual void dummy();
    Action_1847e0();
    char pad[0x18];
};
struct Slot {
    Source* ptr;
    Slot() : ptr(0) {}
};
class BallAndChainSpinAction : public Action_1847e0 {
  public:
    virtual void dummy();
    BallAndChainSpinAction(Source*, Ref*);
    Slot source;
    Ref* ref;
    int val;
};
BallAndChainSpinAction::BallAndChainSpinAction(Source* s, Ref* r) : Action_1847e0(), source(), ref(0) {
    source.ptr = s;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    Source* volatile& q = source.ptr;
    val = q->value;
}