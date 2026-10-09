class Base {
  public:
    virtual void V();
    char pad[0x18];
    Base();
};
class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class HitEffectAction : public Base {
  public:
    Ref* a;
    int b;
    Ref* c;
    virtual void W();
    HitEffectAction(Ref*, int, Ref*);
};
HitEffectAction::HitEffectAction(Ref* p, int x, Ref* q) {
    a = 0;
    b = 0;
    c = 0;
    if (p)
        p->Add();
    if (a)
        a->Release();
    a = p;
    b = x;
    if (q)
        q->Add();
    if (c)
        c->Release();
    c = q;
}