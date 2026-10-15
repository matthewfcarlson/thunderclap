struct Item {
    virtual void A();
    virtual void Release();
};
struct Arg {
    char pad[8];
    int index;
};
class Slots {
  public:
    Item* items[32];
    bool Remove(Arg* p);
};
inline void Clear(Item*& q) {
    if (q) {
        q->Release();
        q = 0;
    }
}
bool Slots::Remove(Arg* p) {
    if (!p)
        return false;
    int i = p->index;
    if (i >= 0 && i < 32 && items[i]) {
        Clear(items[i]);
        return true;
    }
    return false;
}