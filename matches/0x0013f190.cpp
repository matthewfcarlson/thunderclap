typedef unsigned int u32_13f190;
struct Proxy;
struct Owner_13f190 {
    Owner_13f190* first();
    Proxy* second();
};
struct Proxy {
    void apply(u32_13f190, int);
};
struct WallRunAction {
    char pad[0x20];
    Owner_13f190* owner;
    u32_13f190 value24;
    u32_13f190 value28;
    void vfunc_4();
};
void WallRunAction::vfunc_4() {
    Proxy* p = owner->first()->second();
    if (p) {
        p->apply(value28, 0);
        p->apply(value24, 0);
    }
}