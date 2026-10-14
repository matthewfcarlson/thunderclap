class Ref_1b75d0 {
  public:
    virtual void F();
};
class Owner_1b75d0 {
  public:
    Ref_1b75d0* mRef;
    Owner_1b75d0* Set(Ref_1b75d0* r);
};
Owner_1b75d0* Owner_1b75d0::Set(Ref_1b75d0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}