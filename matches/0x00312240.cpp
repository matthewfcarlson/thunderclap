class Item_312240 {
  public:
    virtual void Use();
    virtual void Release();
};
class Owner_312240 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void Notify();
    char pad[0x204];
    Item_312240* item;
    void HelperA();
    void HelperB();
    void Set(Item_312240*);
};
void Owner_312240::Set(Item_312240* next) {
    Item_312240* old = item;
    if (!next) {
        if (old)
            old->Release();
        item = 0;
        return;
    }
    if (next != old) {
        if (old)
            old->Release();
        item = next;
        next->Use();
        HelperA();
        HelperB();
        Notify();
    }
}
