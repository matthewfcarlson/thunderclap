// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_18810 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_18810** p, Obj_18810* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}