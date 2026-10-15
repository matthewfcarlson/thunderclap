struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int index();
};
struct Node {
    char pad[0x1ca0];
    Item* item;
};
struct Holder {
    Node* lookup(unsigned __int64);
    int get(int x);
};
extern "C" unsigned __int64 __cdecl makekey(int, int, int);
int Holder::get(int x) {
    unsigned __int64 key = makekey(x, 0, 0);
    Node* n = lookup(key);
    if (!n)
        return -1;
    Item* i = n->item;
    if (!i)
        return -1;
    return i->index();
}