class Base_144c10 {
  public:
    virtual void V();
    char pad[0x18];
    Base_144c10();
};
class Ref_144c10 {
  public:
    virtual void Add();
    virtual void Release();
};
class HitEffectAction : public Base_144c10 {
  public:
    Ref_144c10* a;
    int b;
    Ref_144c10* c;
    virtual void W();
    HitEffectAction(Ref_144c10*, int, Ref_144c10*);
};
HitEffectAction::HitEffectAction(Ref_144c10* p, int x, Ref_144c10* q) {
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