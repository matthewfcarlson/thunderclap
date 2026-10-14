class Item_2833a0 {
  public:
    virtual void A();
    virtual void B();
};
class Inner_2833a0 {
  public:
    char pad[0x14];
    int value;
    Item_2833a0* item;
};
class Owner_2833a0 {
  public:
    Item_2833a0* item;
    char pad[0x0c];
    Inner_2833a0* inner;
    void set(Item_2833a0* p);
};
void Owner_2833a0::set(Item_2833a0* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
    Inner_2833a0* q = inner;
    if (p)
        p->A();
    if (q->item)
        q->item->B();
    q->item = p;
    q->value = 0xf;
}