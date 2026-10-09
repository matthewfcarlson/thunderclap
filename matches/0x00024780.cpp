struct Item {
    char pad[8];
    unsigned __int64 v;
};
struct Mgr {
    Item* Get(int id);
};
struct Owner {
    char pad[0x44];
    Mgr* mgr;
};
struct C {
    Owner* owner;
    char pad[8];
    int count;
    int ids[1];
    int Target(unsigned a);
};
unsigned __int64 Hash(unsigned a);
int C::Target(unsigned a) {
    int n = 0;
    unsigned __int64 h = Hash(a);
    for (int i = 0; i < count; i++) {
        Mgr* m = owner->mgr;
        Item* it = m->Get(ids[i]);
        if (it->v == h)
            n++;
    }
    return n;
}
