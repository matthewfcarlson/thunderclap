struct Thing {
    char pad[0x24];
    unsigned flags;
    char pad2[0x32 - 0x28];
    char active;
    void Fn();
};
struct Part {
    unsigned Get();
    void Set(unsigned);
};
struct Engine {
    void Stop(int);
};
struct Sub {
    char pad[0x124];
    Engine* p;
};
struct Global {
    char pad[0x20];
    Sub* sub;
    char pad2[0x3c - 0x24];
    Part* part;
};
extern Global* g;
struct Item {
    void Act();
};
Item* __stdcall Make(int, float, int, int);
void Thing::Fn() {
    unsigned x = g->part->Get();
    g->part->Set(flags | x);
    Make(1, 0.5f, 0, 0)->Act();
    Engine* e = g->sub->p;
    if (e && active) {
        active = 0;
        e->Stop(0);
    }
}