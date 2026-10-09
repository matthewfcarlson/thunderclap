class Ref {
  public:
    virtual void Fn();
    virtual void Release();
};
class Base {
  public:
    void Init();
};
class AirToGroundTargetAction {
  public:
    int vf;
    char pad[0x18];
    int a, b, c, d, e, f;
    AirToGroundTargetAction(int x, Ref* r);
};
AirToGroundTargetAction::AirToGroundTargetAction(int x, Ref* r) {
    ((Base*)this)->Init();
    Ref* q = r;
    volatile int* p = &vf;
    *p = 0x411e34;
    volatile int* z = &a;
    *z = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (q)
        q->Fn();
    if (b)
        ((Ref*)b)->Release();
    b = (int)q;
}