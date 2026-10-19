struct Thing_1b90b0 {
    char pad[0x24];
    unsigned flags;
    char pad2[0x32 - 0x28];
    char active;
    void Fn();
};
struct Part_1b90b0 {
    unsigned Get();
    void Set(unsigned);
};
struct Engine_1b90b0 {
    void Stop(int);
};
struct Sub_1b90b0 {
    char pad[0x124];
    Engine_1b90b0* p;
};
struct Global_1b90b0 {
    char pad[0x20];
    Sub_1b90b0* sub;
    char pad2[0x3c - 0x24];
    Part_1b90b0* part;
};
extern Global_1b90b0* g_1b90b0;
struct Item_1b90b0 {
    void Act(int, float, int, int);
};
Item_1b90b0* __stdcall Make();
void Thing_1b90b0::Fn() {
    unsigned x = g_1b90b0->part->Get();
    g_1b90b0->part->Set(flags | x);
    Make()->Act(1, 0.5f, 0, 0);
    Engine_1b90b0* e = g_1b90b0->sub->p;
    if (e && active) {
        active = 0;
        e->Stop(0);
    }
}