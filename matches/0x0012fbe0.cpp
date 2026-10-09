extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int g_vftable;

class MissionProgressCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual MissionProgressCondition* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void baseDtor();
    char pad4[8];
    void* m0c;
    char pad10[4];
    void* m14;
};

MissionProgressCondition* MissionProgressCondition::vfunc_5(unsigned char flag) {
    *(void**)this = &g_vftable;
    thunk_FUN_00267090(m0c);
    thunk_FUN_00267090(m14);
    baseDtor();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
