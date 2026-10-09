class Item {
  public:
    virtual void Release(int);
    virtual void Skip();
    virtual bool Match(int);
    Item* next;
};
class List {
  public:
    virtual void Begin();
    virtual void End();
};
class Owner {
  public:
    char pad0[0x0c];
    List list;
    char pad10[0x5c];
    Item* slots[3];
    Item* tails[4];
    void Run(int, int);
};
void Clean(void*);
void Owner::Run(int arg, int index) {
    list.Begin();
    Item** p = &slots[index];
    Item* cur = *p;
    Item* prev = 0;
    while (cur != 0) {
        if ((*p)->Match(arg)) {
            Item* x = *p;
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
