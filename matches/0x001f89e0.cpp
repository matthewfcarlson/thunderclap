struct Item {
    __int64 Key();
};
struct Collection {
    char pad[12];
    int count;
    Item* Find(__int64);
    Item* At(int);
};
struct Manager {
    char pad[4];
    Collection* item;
};
struct Root {
    char pad[0x20];
    Manager* mgr;
};
struct Owner {
    Item* value;
    char Test(const char*);
};
extern Root* gRoot;
extern "C" __int64 __cdecl MakeKey(const char*);
char Owner::Test(const char* name) {
    Owner* saved = this;
    Collection* c = gRoot->mgr->item;
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
        Item* dead = *(Item* volatile*)&saved->value;
    }
    return 0;
}
