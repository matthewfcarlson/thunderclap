struct Item;
struct Inner_29f840 {
    int pad[5];
    int mCount; // 0x14
};
struct Entry_29f840 {
    Inner_29f840* mInner;
    void Set(int idx, Item* it); // FUN_0029eda0
};
struct Src_29f840 {
    char pad[0x10];
    int mLimit;      // 0x10
    unsigned mCount; // 0x14
    Item** mItems;   // 0x18
};
struct Grow_29f840 { int Grow(int n); }; // FUN_002a1180

struct Owner_29f840 {
    char pad[0x24];
    int mTotal;
    Entry_29f840* Find(Item* it); // FUN_0029c450
    void Run(Src_29f840* s);
};

void Owner_29f840::Run(Src_29f840* s) {
    unsigned n = s->mCount;
    unsigned i = 0;
    for (i = 0; i < n; i++) {
        if ((int)i >= s->mLimit)
            continue;
        Item* it = s->mItems[i];
        if (!it)
            continue;
        Entry_29f840* e = Find(it);
        if (!e)
            continue;
        int c = *(int*)((char*)e->mInner + 0x14);
        ((Grow_29f840*)e->mInner)->Grow(c + 1);
        e->Set(c, it);
        mTotal++;
    }
}
