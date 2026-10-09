class Item {
  public:
    virtual void F();
    virtual void G();
};
class Obj {
    char pad[0x3800];
    Item* slots[10];

  public:
    int count;
    void Remove(int);
};
void Obj::Remove(int i) {
    if (count <= 0) {
        count = 0;
        return;
    }
    Item* p = slots[i];
    if (p) {
        p->G();
        slots[i] = 0;
    }
    slots[i] = slots[count - 1];
    slots[count - 1] = 0;
    count--;
}