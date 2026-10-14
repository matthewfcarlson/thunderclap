// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_c8710 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_c8710** p, Obj_c8710* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}