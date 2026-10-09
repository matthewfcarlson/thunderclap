struct Sub {
    int Count();
};
struct Item {
    char Check(int*);
};
struct Obj {
    char pad[4];
    Obj* child;
    int Find(int);
};
extern Obj* GetQuery();
char __stdcall Target(int a, int b, int c) {
    Obj* q = GetQuery();
    if (!q)
        return 0;
    q = GetQuery();
    Obj* h = q->child;
    if (!h)
        return 0;
    q = GetQuery();
    h = q->child;
    int n = ((Sub*)((char*)h + 0x18))->Count();
    int args[3];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    for (int i = 0; i < n; ++i) {
        q = GetQuery();
        h = q->child;
        Item* item = (Item*)h->Find(i);
        if (item && item->Check(args))
            return 1;
    }
    return 0;
}