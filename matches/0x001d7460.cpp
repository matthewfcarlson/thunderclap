class Ref_1d7460 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1d7460 {
    char pad[0x1dc];
    Ref_1d7460* p;

  public:
    void Set(Ref_1d7460*);
};
void Owner_1d7460::Set(Ref_1d7460* value) {
    if ((void*)this != (void*)value) {
        if (value)
            value->A();
        if (p)
            p->B();
        p = value;
    }
}