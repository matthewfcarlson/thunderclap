extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int g_vftable_10e780;
class AIHistoryNameCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual AIHistoryNameCondition* vfunc_5(int flag);
    virtual void vfunc_6();
    int pad4;
    int pad8;
    int padc;
    void* m10;
    void reset();
};
AIHistoryNameCondition* AIHistoryNameCondition::vfunc_5(int flag) {
    void* x = m10;
    *(void**)this = &g_vftable_10e780;
    thunk_FUN_00267090(x);
    reset();
    if (flag & 1)
        operator delete(this);
    return this;
}
