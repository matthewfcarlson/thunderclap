class Item_29cc70 {
  public:
    virtual void f0();
    virtual void f1();
};
class Owner_29cc70 {
  public:
    Item_29cc70* a[4];
    Owner_29cc70* run(unsigned char);
};
extern void __cdecl cleanup(Owner_29cc70*);
Owner_29cc70* Owner_29cc70::run(unsigned char flags) {
    a[3]->f1();
    a[2]->f1();
    a[1]->f1();
    a[0]->f1();
    if (flags & 1)
        cleanup(this);
    return this;
}