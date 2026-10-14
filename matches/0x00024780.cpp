struct Item_24780 {
    char pad[8];
    unsigned __int64 v;
};
struct Mgr_24780 {
    Item_24780* Get(int id);
};
struct Owner_24780 {
    char pad[0x44];
    Mgr_24780* mgr;
};
struct C_24780 {
    Owner_24780* owner;
    char pad[8];
    int count;
    int ids[1];
    int Target(unsigned a);
};
unsigned __int64 Hash(unsigned a);
int C_24780::Target(unsigned a) {
    int n = 0;
    unsigned __int64 h = Hash(a);
    for (int i = 0; i < count; i++) {
        Mgr_24780* m = owner->mgr;
        Item_24780* it = m->Get(ids[i]);
        if (it->v == h)
            n++;
    }
    return n;
}
