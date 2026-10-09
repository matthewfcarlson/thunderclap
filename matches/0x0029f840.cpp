struct Item;
struct Inner {
    int pad[5];
    int mCount; // 0x14
};
struct Entry {
    Inner* mInner;
    void Set(int idx, Item* it); // FUN_0029eda0
};
struct Src {
    char pad[0x10];
    int mLimit;      // 0x10
    unsigned mCount; // 0x14
    Item** mItems;   // 0x18
};
int __stdcall Grow(int n); // FUN_002a1180

struct Owner {
    char pad[0x24];
    int mTotal;
    Entry* Find(Item* it); // FUN_0029c450
    void Run(Src* s);
};

void Owner::Run(Src* s) {
    unsigned n = s->mCount;
    unsigned i = 0;
    for (i = 0; i < n; i++) {
        if ((int)i >= s->mLimit)
            continue;
        Item* it = s->mItems[i];
        if (!it)
            continue;
        Entry* e = Find(it);
        if (!e)
            continue;
        int c = *(int*)((char*)e->mInner + 0x14);
        Grow(c + 1);
        e->Set(c, it);
        mTotal++;
    }
}
