typedef unsigned int u32;
struct Proxy;
struct Owner { Owner* first(); Proxy* second(); };
struct Proxy { void apply(u32, int); };
struct WallRunAction { char pad[0x20]; Owner* owner; u32 value24; u32 value28; void vfunc_4(); };
void WallRunAction::vfunc_4() {
    Proxy* p = owner->first()->second();
    if (p) {
        p->apply(value28, 0);
        p->apply(value24, 0);
    }
}