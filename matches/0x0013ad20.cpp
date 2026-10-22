class Other_13ad20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_13ad20 {
  public:
    Action_13ad20();
    virtual void X();
    char pad[0x18];
};
struct S_13ad20 {
    int a;
    Other_13ad20* b;
    int c;
    S_13ad20() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class AnimationAction : public Action_13ad20 {
  public:
    virtual void A();
    S_13ad20 s;
    AnimationAction(int, Other_13ad20*);
};
AnimationAction::AnimationAction(int value, Other_13ad20* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}
