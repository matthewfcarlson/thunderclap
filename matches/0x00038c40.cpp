class Item_38c40 {
  public:
    virtual void f();
    virtual void Release();
};
struct Entry_38c40 {
    Item_38c40* volatile p;
    volatile unsigned char flag;
    char pad[0x33];
};
class Owner_38c40 {
  public:
    char pad[0x1ed8];
    Entry_38c40 entries[3];
    void Clear();
};
void Owner_38c40::Clear() {
    Entry_38c40* q = entries;
    int n = 3;
    do {
        q->flag = 0;
        Item_38c40* x = q->p;
        if (x) {
            x->Release();
            q->p = 0;
        }
        ++q;
    } while (--n);
}