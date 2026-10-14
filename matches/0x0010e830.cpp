extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int g_vftable_10e830;
class HulkActionRecentCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual HulkActionRecentCondition* vfunc_5(char);
    virtual void vfunc_6();
    char pad[12];
    void* m10;
    void Finish();
};
HulkActionRecentCondition* HulkActionRecentCondition::vfunc_5(char a) {
    void* x = m10;
    *(void**)this = &g_vftable_10e830;
    thunk_FUN_00267090(x);
    Finish();
    if (a & 1)
        operator delete(this);
    return this;
}
