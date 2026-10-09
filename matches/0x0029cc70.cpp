class Item {
  public:
    virtual void f0();
    virtual void f1();
};
class Owner {
  public:
    Item* a[4];
    Owner* run(unsigned char);
};
extern void __cdecl cleanup(Owner*);
Owner* Owner::run(unsigned char flags) {
    a[3]->f1();
    a[2]->f1();
    a[1]->f1();
    a[0]->f1();
    if (flags & 1)
        cleanup(this);
    return this;
}