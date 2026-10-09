struct Helper { int run(int, int, int); };
struct CDamageTrack { char pad[0x10]; int a; int b; int vfunc_12(int); };
extern void* FUN_0008d690(int);
int CDamageTrack::vfunc_12(int x) {
    Helper* p = (Helper*)FUN_0008d690(0x28);
    if (p) return p->run(x, a, b);
    return 0;
}