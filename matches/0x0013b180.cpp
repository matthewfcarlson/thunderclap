class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_13b180 {
  public:
    Action_13b180();
    virtual void Fn();
    char pad[0x18];
};
struct Val {
    int n;
    Val() : n(0) {}
    Val& operator=(int x) {
        n = x;
        return *this;
    }
};
class AnimationChargeAction : public Action_13b180 {
  public:
    virtual void Fn();
    Val value;
    Ref* ref;
    int other;
    AnimationChargeAction(int, Ref*);
};
AnimationChargeAction::AnimationChargeAction(int x, Ref* r) : value(), ref(0), other(0) {
    value = x;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
}