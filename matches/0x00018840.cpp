// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_18840 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_18840** p, Obj_18840* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}