class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
struct Source {
    char pad[0x20];
    int value;
};
class Base {
  public:
    virtual void dummy();
    Base();
    char pad[0x18];
};
struct Slot {
    Source* ptr;
    Slot() : ptr(0) {}
};
class BallAndChainSpinAction : public Base {
  public:
    virtual void dummy();
    BallAndChainSpinAction(Source*, Ref*);
    Slot source;
    Ref* ref;
    int val;
};
BallAndChainSpinAction::BallAndChainSpinAction(Source* s, Ref* r) : Base(), source(), ref(0) {
    source.ptr = s;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    Source* volatile& q = source.ptr;
    val = q->value;
}