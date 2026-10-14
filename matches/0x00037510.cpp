// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_37510 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_37510** p, Obj_37510* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}