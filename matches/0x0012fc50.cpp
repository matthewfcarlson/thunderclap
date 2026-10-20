// Same code shape as 0x0012fbe0 (propagated; names are from that function)
extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int g_vftable_12fc50;

class GameStateCondition_12fc50 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual GameStateCondition_12fc50* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void baseDtor();
    char pad4[8];
    void* m0c;
    char pad10[4];
    void* m14;
};

GameStateCondition_12fc50* GameStateCondition_12fc50::vfunc_5(unsigned char flag) {
    *(void**)this = &g_vftable_12fc50;
    thunk_FUN_00267090(m0c);
    thunk_FUN_00267090(m14);
    baseDtor();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
