struct DynamicCasterVtable {
    char unused;
};
extern DynamicCasterVtable DAT_00409148;
extern unsigned __int64 __cdecl FUN_0027b020(void*);
struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(void*, unsigned, unsigned);
};
int __cdecl FUN_000c1ed0(Target* target, void* resource) {
    unsigned __int64 result = FUN_0027b020(resource);
    DynamicCasterVtable* caster = &DAT_00409148;
    return target->slot3(&caster, (unsigned)result, (unsigned)(result >> 32));
}