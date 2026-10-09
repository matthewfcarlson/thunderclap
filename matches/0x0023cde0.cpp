class PlatformCondition {};
struct Factory {
    int vptr;
};
extern int factoryVtable;
extern void __cdecl FUN_002343e0(PlatformCondition*, Factory*);
void __cdecl FUN_0023cde0(PlatformCondition* p) {
    Factory f;
    f.vptr = (int)&factoryVtable;
    FUN_002343e0(p, &f);
}
