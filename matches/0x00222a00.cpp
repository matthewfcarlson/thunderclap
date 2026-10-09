class EntryOwner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
};
struct Item {
    char pad[4];
    float value;
    unsigned char enabled;
};
extern const float zero;
class Container {
  public:
    char pad[0x68];
    unsigned count;
    Item entries[1];
    unsigned char Check(EntryOwner* item);
};
unsigned char Container::Check(EntryOwner* item) {
    unsigned i = 0;
    while (i < count) {
        Item* e = (Item*)((char*)this + 0x6c + i * 0x28);
        if (*(EntryOwner**)e == item) {
            if (!(e->value < zero) || e->enabled)
                return (unsigned char)item->f13();
            break;
        }
        ++i;
    }
    return 1;
}
