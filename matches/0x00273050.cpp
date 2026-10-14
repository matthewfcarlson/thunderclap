class Item_273050 {
  public:
    virtual void Release(int);
    virtual void Skip();
    virtual bool Match(int);
    Item_273050* next;
};
class List_273050 {
  public:
    virtual void Begin();
    virtual void End();
};
class Owner_273050 {
  public:
    char pad0[0x0c];
    List_273050 list;
    char pad10[0x5c];
    Item_273050* slots[3];
    Item_273050* tails[4];
    void Run(int, int);
};
void Clean(void*);
void Owner_273050::Run(int arg, int index) {
    list.Begin();
    Item_273050** p = &slots[index];
    Item_273050* cur = *p;
    Item_273050* prev = 0;
    while (cur != 0) {
        if ((*p)->Match(arg)) {
            Item_273050* x = *p;
            *p = x->next;
            x->Release(1);
            Clean((char*)this + 0x68);
        } else {
            prev = *p;
            p = &prev->next;
        }
        cur = *p;
    }
    tails[index] = prev;
    list.End();
}
