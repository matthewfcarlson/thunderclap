struct Sub_204350 {
    int Count();
};
struct Item_204350 {
    char Check(int*);
};
struct Obj_204350 {
    char pad[4];
    Obj_204350* child;
    int Find(int);
};
extern Obj_204350* GetQuery();
char __stdcall Target(int a, int b, int c) {
    Obj_204350* q = GetQuery();
    if (!q)
        return 0;
    q = GetQuery();
    Obj_204350* h = q->child;
    if (!h)
        return 0;
    q = GetQuery();
    h = q->child;
    int n = ((Sub_204350*)((char*)h + 0x18))->Count();
    int args[3];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    for (int i = 0; i < n; ++i) {
        q = GetQuery();
        h = q->child;
        Item_204350* item = (Item_204350*)h->Find(i);
        if (item && item->Check(args))
            return 1;
    }
    return 0;
}