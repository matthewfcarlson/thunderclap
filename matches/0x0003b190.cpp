class Thing_3b190 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3b190 {
  public:
    char pad[0x630];
    Thing_3b190* ptr;
    bool Set(Thing_3b190* p);
};
bool Owner_3b190::Set(Thing_3b190* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
    return true;
}