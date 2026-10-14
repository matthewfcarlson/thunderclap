// Same code shape as 0x000187a0 (propagated; names are from that function)
class Obj_13a790 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_13a790** p, Obj_13a790* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}