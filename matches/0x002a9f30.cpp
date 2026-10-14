class Ref_2a9f30 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2a9f30 {
    char pad[0x44];
    Ref_2a9f30* mRef;

  public:
    void Set(class Source_2a9f30*);
};
class Source_2a9f30 {
  public:
    char pad[0x68];
    Ref_2a9f30* mRef;
};
void Owner_2a9f30::Set(Source_2a9f30* src) {
    Ref_2a9f30* p = src->mRef;
    if (p)
        p->A();
    if (mRef)
        mRef->B();
    mRef = p;
}