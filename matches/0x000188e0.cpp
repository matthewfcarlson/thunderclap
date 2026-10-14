// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_188e0 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_188e0** p, Obj_188e0* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}