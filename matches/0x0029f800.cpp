class Thing_29f800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x10];
    int field;
    void Prepare(int);
};
class Item_29f800 {
  public:
    Thing_29f800* owner;
    void Apply(int, int);
};
class Manager_29f800 {
    char pad[0x24];

  public:
    int count;
    Item_29f800* Get(int);
    void Run(int);
};
void Manager_29f800::Run(int arg) {
    if (arg) {
        Item_29f800* p = Get(arg);
        if (p) {
            int value = p->owner->field;
            p->owner->Prepare(value + 1);
            p->Apply(value, arg);
            ++count;
        }
    }
}