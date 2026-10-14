class Obj_187a0 {
  public:
    virtual void A();
    virtual void B();
};
void Set(Obj_187a0** p, Obj_187a0* v) {
    if (v)
        v->A();
    if (*p)
        (*p)->B();
    *p = v;
}