class Ref {
  public:
    virtual void Fn();
    virtual void Release();
};
void BaseInit();
class BounceAction {
  public:
    int vptr;
    int pad04[6];
    int m1c;
    Ref* m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    BounceAction(int, Ref*);
};
BounceAction::BounceAction(int a, Ref* r) {
    BaseInit();
    vptr = 0x411e18;
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m1c = a;
    if (r)
        r->Fn();
    if (m20)
        m20->Release();
    m20 = r;
}