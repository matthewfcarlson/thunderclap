struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_002345b0(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int smart_vftable;
extern int condition_vftable_4c720;
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = &smart_vftable;
    FUN_0027af50((char*)p + 0x18);
    p->vptr = &condition_vftable_4c720;
    FUN_002345b0(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}