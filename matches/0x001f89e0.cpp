struct Item_1f89e0 {
    __int64 Key();
};
struct Collection_1f89e0 {
    char pad[12];
    int count;
    Item_1f89e0* Find(__int64);
    Item_1f89e0* At(int);
};
struct Manager_1f89e0 {
    char pad[4];
    Collection_1f89e0* item;
};
struct Root_1f89e0 {
    char pad[0x20];
    Manager_1f89e0* mgr;
};
struct Owner_1f89e0 {
    Item_1f89e0* value;
    char Test(const char*);
};
extern Root_1f89e0* gRoot_1f89e0;
extern "C" __int64 __cdecl MakeKey(const char*);
char Owner_1f89e0::Test(const char* name) {
    Owner_1f89e0* saved = this;
    Collection_1f89e0* c = gRoot_1f89e0->mgr->item;
    if (c) {
        value = c->Find(MakeKey(name));
        if (value)
            return 1;
        __int64 p = MakeKey(name);
        for (int i = 0; i < c->count; ++i) {
            if (c->At(i)->Key() == p) {
                saved->value = c->At(i);
                return 1;
            }
        }
        Item_1f89e0* dead = *(Item_1f89e0* volatile*)&saved->value;
    }
    return 0;
}
