struct Item {
    char pad[0x56];
    short value;
};
struct Mgr {
    Item* Find(int);
};
struct Root {
    char pad[4];
    Mgr* volatile mgr;
};
Root* __cdecl GetRoot();
int __stdcall FUN_00204320(int id) {
    Root* r = GetRoot();
    Mgr* m = r->mgr;
    Item* item = m->Find(id);
    if (!item)
        return -1;
    return item->value;
}