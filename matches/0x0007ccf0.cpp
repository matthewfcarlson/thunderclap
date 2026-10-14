class Item_7ccf0 {
  public:
    virtual void F();
    virtual void G();
};
class Obj_7ccf0 {
    char pad[0x3800];
    Item_7ccf0* slots[10];

  public:
    int count;
    void Remove(int);
};
void Obj_7ccf0::Remove(int i) {
    if (count <= 0) {
        count = 0;
        return;
    }
    Item_7ccf0* p = slots[i];
    if (p) {
        p->G();
        slots[i] = 0;
    }
    slots[i] = slots[count - 1];
    slots[count - 1] = 0;
    count--;
}