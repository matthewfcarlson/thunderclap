class PlatformCondition {};
struct Factory_23cde0 {
    int vptr;
};
extern int factoryVtable;
extern void __cdecl FUN_002343e0(PlatformCondition*, Factory_23cde0*);
void __cdecl FUN_0023cde0(PlatformCondition* p) {
    Factory_23cde0 f;
    f.vptr = (int)&factoryVtable;
    FUN_002343e0(p, &f);
}
