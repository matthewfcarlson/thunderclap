class HulkAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern void __fastcall FUN_00059a30(void*);
extern void* FUN_000678d0();
extern void __fastcall FUN_00067730(void*);
bool HulkAction::vfunc_5(int param_2, int param_3) {
    if (param_2 == 0) {
        void* p = FUN_000592a0(*(void**)((char*)this + 0x20));
        FUN_00059a30(p);
        p = FUN_000678d0();
        FUN_00067730(p);
    }
    return true;
}