extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int g_vftable_12fe60;
class StatEndTrialTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual StatEndTrialTrack* vfunc_5(int);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    int a;
    int b;
    int c;
    void* m10;
    void Cleanup();
};
StatEndTrialTrack* StatEndTrialTrack::vfunc_5(int flag) {
    void* x = m10;
    *(void**)this = &g_vftable_12fe60;
    thunk_FUN_00267090(x);
    Cleanup();
    if (flag & 1)
        operator delete(this);
    return this;
}
